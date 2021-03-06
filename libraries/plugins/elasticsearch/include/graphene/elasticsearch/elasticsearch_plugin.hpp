/*
 * Copyright (c) 2017 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once

#include <graphene/app/plugin.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/chain/operation_history_object.hpp>

namespace graphene { namespace elasticsearch {
   using namespace chain;

//
// Plugins should #define their SPACE_ID's so plugins with
// conflicting SPACE_ID assignments can be compiled into the
// same binary (by simply re-assigning some of the conflicting #defined
// SPACE_ID's in a build script).
//
// Assignment of SPACE_ID's cannot be done at run-time because
// various template automagic depends on them being known at compile
// time.
//
#ifndef ELASTICSEARCH_SPACE_ID
#define ELASTICSEARCH_SPACE_ID 6
#endif

namespace detail
{
    class elasticsearch_plugin_impl;
}

class elasticsearch_plugin : public graphene::app::plugin
{
   public:
      elasticsearch_plugin();
      virtual ~elasticsearch_plugin();

      std::string plugin_name()const override;
      //std::string plugin_description()const override;
      virtual void plugin_set_program_options(
         boost::program_options::options_description& cli,
         boost::program_options::options_description& cfg) override;
      virtual void plugin_initialize(const boost::program_options::variables_map& options) override;
      virtual void plugin_startup() override;

      friend class detail::elasticsearch_plugin_impl;
      std::unique_ptr<detail::elasticsearch_plugin_impl> my;
};

struct operation_history_struct {
   int trx_in_block;
   int op_in_trx;
   std::string operation_result;
   int virtual_op;
   std::string op;
   variant op_object;
};

struct block_struct {
   int block_num;
   fc::time_point_sec block_time;
   std::string trx_id;
};

struct bulk_struct {
   account_transaction_history_object account_history;
   operation_history_struct operation_history;
   int operation_type;
   int operation_id_num;
   block_struct block_data;
};

struct adaptor_struct {
   variant adapt(const variant_object& op)
   {
      fc::mutable_variant_object o(op);
      vector<string> keys_to_rename;
      map<string,string> ele_str_map;
      for (auto i = o.begin(); i != o.end(); ++i)
      {
         auto& element = (*i).value();
         if (element.is_object())
         {
            const string& name = (*i).key();
            auto& vo = element.get_object();
            if (vo.contains(name.c_str()))
               keys_to_rename.emplace_back(name);
            element = adapt(vo);
         }
         else if (element.is_array()){
            string old_key = (*i).key();
            auto ele_str = fc::json::to_string(o[old_key.c_str()]);
            ele_str_map[old_key] = ele_str;
         }
      }
      for(const auto& i : ele_str_map)
      {
         string key =  i.first + "_str";
         o[key.c_str()]=i.second.c_str();
         o.erase(i.first.c_str());
      }
      for (const auto& i : keys_to_rename)
      {
         string new_name = i + "_";
         o[new_name] = variant(o[i]);
         o.erase(i);
      }

      if (o.find("memo") != o.end())
      {
         auto& memo = o["memo"];
         if (memo.is_string())
         {
            o["memo_"] = o["memo"];
            o.erase("memo");
         }
         else if (memo.is_object())
         {
            fc::mutable_variant_object tmp(memo.get_object());
            if (tmp.find("nonce") != tmp.end())
            {
               tmp["nonce"] = tmp["nonce"].as_string();
               o["memo"] = tmp;
            }
         }
      }
      if (o.find("new_parameters") != o.end())
      {
         auto& tmp = o["new_parameters"];
         if (tmp.is_object())
         {
            fc::mutable_variant_object tmp2(tmp.get_object());
            if (tmp2.find("current_fees") != tmp2.end())
            {
               tmp2.erase("current_fees");
               o["new_parameters"] = tmp2;
            }
         }
      }
      if (o.find("owner") != o.end() && o["owner"].is_string())
      {
         o["owner_"] = o["owner"].as_string();
         o.erase("owner");
      }
      if (o.find("amount") != o.end())
      {
         auto amo = o["amount"].as_int64();
         o["amount_str"] = std::to_string(amo);
         o.erase("amount");
      }
      if (o.find("max_market_fee") != o.end() )
      {
         auto amo = o["max_market_fee"].as_int64();
         o.erase("max_market_fee");
         o["max_market_fee_row"] = std::to_string(amo);
      }
      
      variant v;
      fc::to_variant(o, v, FC_PACK_MAX_DEPTH);
      return v;
   }

   void adapt(fc::variants& v)
   {
      for (auto& array_element : v)
      {
         if (array_element.is_object())
            array_element = adapt(array_element.get_object());
         else if (array_element.is_array())
            adapt(array_element.get_array());
         else
            array_element = array_element.as_string();
      }
   }
};

} } //graphene::elasticsearch

FC_REFLECT( graphene::elasticsearch::operation_history_struct, (trx_in_block)(op_in_trx)(operation_result)(virtual_op)(op)(op_object) )
FC_REFLECT( graphene::elasticsearch::block_struct, (block_num)(block_time)(trx_id) )
FC_REFLECT( graphene::elasticsearch::bulk_struct, (account_history)(operation_history)(operation_type)(operation_id_num)(block_data) )
