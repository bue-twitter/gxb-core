file(GLOB HEADERS "include/graphene/chain/*.hpp")
file(GLOB PROTOCOL_HEADERS "include/graphene/chain/protocol/*.hpp")

if( GRAPHENE_DISABLE_UNITY_BUILD )
   set( GRAPHENE_DB_FILES
        db_balance.cpp
        db_block.cpp
        db_debug.cpp
        db_getter.cpp
        db_init.cpp
        db_maint.cpp
        db_management.cpp
        db_update.cpp
        db_witness_schedule.cpp
      )
   message( STATUS "Graphene database unity build disabled" )
else( GRAPHENE_DISABLE_UNITY_BUILD )
   set( GRAPHENE_DB_FILES
        database.cpp )
   message( STATUS "Graphene database unity build enabled" )
endif( GRAPHENE_DISABLE_UNITY_BUILD )

## SORT .cpp by most likely to change / break compile
add_library( graphene_chain

             # As database takes the longest to compile, start it first
             ${GRAPHENE_DB_FILES}
             fork_database.cpp
             name.cpp

             protocol/types.cpp
             protocol/address.cpp
             protocol/authority.cpp
             protocol/asset.cpp
             protocol/assert.cpp
             protocol/account.cpp
             protocol/transfer.cpp
             protocol/committee_member.cpp
             protocol/witness.cpp
             protocol/market.cpp
             protocol/proposal.cpp
             protocol/withdraw_permission.cpp
             protocol/asset_ops.cpp
             protocol/memo.cpp
             protocol/worker.cpp
             protocol/custom.cpp
             protocol/operations.cpp
             protocol/transaction.cpp
             protocol/block.cpp
             protocol/fee_schedule.cpp
             protocol/confidential.cpp
             protocol/vote.cpp

             genesis_state.cpp
             get_config.cpp

             pts_address.cpp

             evaluator.cpp
             stale_evaluator.cpp
             balance_evaluator.cpp
             account_evaluator.cpp
             assert_evaluator.cpp
             witness_evaluator.cpp
             data_market_evaluator.cpp
             data_transaction_evaluator.cpp
             pay_data_transaction_evaluator.cpp
             free_data_product_evaluator.cpp
             league_data_product_evaluator.cpp
             league_evaluator.cpp
             datasource_copyright_evaluator.cpp
             loyalty_evaluator.cpp
             proxy_transfer_evaluator.cpp
             contract_evaluator.cpp
             staking_evaluator.cpp

             committee_member_evaluator.cpp
             asset_evaluator.cpp
             transfer_evaluator.cpp
             proposal_evaluator.cpp
             market_evaluator.cpp
             vesting_balance_evaluator.cpp
             withdraw_permission_evaluator.cpp
             worker_evaluator.cpp
             confidential_evaluator.cpp
             special_authority.cpp
             buyback.cpp

             apply_context.cpp
             transaction_context.cpp
             wast_to_wasm.cpp
             wasm_interface.cpp
             wasm_validation.cpp
             wasm_injection.cpp

             webassembly/wavm.cpp
             webassembly/binaryen.cpp
             webassembly/wabt.cpp

             account_object.cpp
             asset_object.cpp
             fba_object.cpp
             proposal_object.cpp
             vesting_balance_object.cpp

             block_database.cpp

             is_authorized_asset.cpp

             abi_serializer.cpp
             
             trust_node_pledge_helper.cpp

             ${HEADERS}
             ${PROTOCOL_HEADERS}
           )

target_link_libraries( graphene_chain fc graphene_db Logging IR WAST WASM Runtime wasm
    asmjs passes ast emscripten-optimizer support softfloat builtins wabt)

target_include_directories( graphene_chain
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
           "${CMAKE_CURRENT_SOURCE_DIR}/../wasm-jit/Include"
           "${CMAKE_CURRENT_SOURCE_DIR}/../../externals/binaryen/src"
           "${CMAKE_SOURCE_DIR}/libraries/wabt"
           "${CMAKE_BINARY_DIR}/libraries/wabt")

if(MSVC)
  set_source_files_properties( db_init.cpp db_block.cpp database.cpp block_database.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   graphene_chain

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/graphene/chain" )
INSTALL( FILES ${PROTOCOL_HEADERS} DESTINATION "include/graphene/chain/protocol" )
