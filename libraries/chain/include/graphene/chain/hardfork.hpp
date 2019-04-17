/*****************************************
 *                                       *
 * This file is automatically generated. *
 * To create new hardfork, please modify *
 * the .hf files in hardfork.d instead   *
 * of modifying this file.               *
 *                                       *
 *****************************************/

#pragma once
//#1001 is for commission rate
#ifndef HARDFORK_1001_TIME
#define HARDFORK_1001_TIME (fc::time_point_sec( 1506787200 ))
#endif
// hardfork 1002
// start at 2017-11-01 00:00:00
// voting with GXS
#ifndef HARDFORK_1002_TIME
#define HARDFORK_1002_TIME (fc::time_point_sec(1509465600))
#endif
// hardfork 1003 is for commission allocation
// x% --> reserve pool
#ifndef HARDFORK_1003_TIME
#define HARDFORK_1003_TIME (fc::time_point_sec( 1509292800 ))
#endif

// hardfork 1004 disable limit order
#ifndef HARDFORK_1004_TIME
#define HARDFORK_1004_TIME (fc::time_point_sec( 1524153600 ))
#endif

// hardfork 1005
// create asset fee
#ifndef HARDFORK_1005_TIME
#define HARDFORK_1005_TIME (fc::time_point_sec( 1524153600 ))
#endif

// hardfork 1006
// add wasm validate, for testnet
// start at 2018-08-20 18:00:00
#ifndef HARDFORK_1006_TIME
#define HARDFORK_1006_TIME (fc::time_point_sec( 1534759200 ))
#endif

// hardfork 1008
// core asset hardfork
#ifndef HARDFORK_1008_TIME
#define HARDFORK_1008_TIME (fc::time_point_sec( 1541433600 )) // for mainnet, 2018-11-06T00:00:00
#endif

// set min witness num 21
#ifndef HARDFORK_1010_TIME
#define HARDFORK_1010_TIME (fc::time_point_sec( 1545796800 )) // for mainnet, 2018-12-26T04:00:00
#endif

// contract call fee
#ifndef HARDFORK_1011_TIME
#define HARDFORK_1011_TIME (fc::time_point_sec( 1545796800 )) // for mainnet, 2018-12-26T04:00:00
#endif

// update active trustnodes
#ifndef HARDFORK_1012_TIME
#define HARDFORK_1012_TIME (fc::time_point_sec( 1545796800 )) // for mainnet, 2018-12-26T04:00:00
#endif

// call_contract fix fee calculation
#ifndef HARDFORK_1013_TIME
// should be updated before next release, should be removed after next release
#define HARDFORK_1013_TIME (fc::time_point_sec( 1545034200 )) // for test, 2018-12-17T08:10:00(UTC)
#endif

// add inline_transfer api for contract
#ifndef HARDFORK_1017_TIME
// should be updated before next release
#define HARDFORK_1017_TIME (fc::time_point_sec( 1545436800 )) // for test, 2018-12-22T00:00:00(UTC)
#endif

#ifndef HARDFORK_1015_TIME
// disable udpate_contract for normal account
#define HARDFORK_1015_TIME (fc::time_point_sec( 1546084800 )) // for mainnet, 2018-12-29T12:00:00 UTC
#endif

// enable witness guaranty
#ifndef HARDFORK_1129_TIME
#define HARDFORK_1129_TIME (fc::time_point_sec( 1545796800 )) // for mainnet, 2018-12-26T04:00:00
#endif

// #1103 the time point before you can renaming asset symbol
// UTC 2018-11-30 00:00:00
#ifndef HARDFORK_1103_TIME
#define HARDFORK_1103_TIME (fc::time_point_sec( 1543507200 ))
#endif

#ifndef HARDFORK_1016_TIME
// disable udpate_contract for normal account
#define HARDFORK_1016_TIME (fc::time_point_sec( 1547536200 )) // for mainnet, 2018-12-29T12:00:00 UTC
#endif

#ifndef HARDFORK_1019_TIME
// for mainnet can transfer to contract account, can be removed after mainnet released
#define HARDFORK_1019_TIME (fc::time_point_sec( 1552176000 ))  // for mainnet, 2019-03-10T00:00:00 UTC
#endif

#ifndef HARDFORK_1020_TIME
// for testnet after this time can not remove contract table
#define HARDFORK_1020_TIME (fc::time_point_sec( 1552381200 )) // for testnet, 2019-03-12T08:00:00(UTC)
#endif

#ifndef HARDFORK_1021_TIME
// for testnet after this time can be remove contract table
#define HARDFORK_1021_TIME (fc::time_point_sec( 1553040000 )) // for testnet, 2019-03-15T00:00:00(UTC)
#endif

#ifndef HARDFORK_1022_TIME
// for testnet after this time can support "GXC....." public key in assert_recover_key
#define HARDFORK_1022_TIME (fc::time_point_sec( 1553990400 )) // for testnet, 2019-03-31T00:00:00(UTC)
#endif

#ifndef HARDFORK_1023_TIME
// for testnet after this time add api get_asset_precision
#define HARDFORK_1023_TIME (fc::time_point_sec( 1555761600 )) // for testnet, 2019-04-20T12:00:00(UTC)
#endif

#ifndef HARDFORK_1024_TIME
// for testnet after this time modify update_contract logic
#define HARDFORK_1024_TIME (fc::time_point_sec( 1556625600 )) // for testnet, 2019-04-30T12:00:00(UTC)
#endif

// #413 Add operation to claim asset fees
#ifndef HARDFORK_413_TIME
#define HARDFORK_413_TIME (fc::time_point_sec( 1446652800 ))
#endif
// #415 Default accept policy for asset with no whitelist authorities
#ifndef HARDFORK_415_TIME
#define HARDFORK_415_TIME (fc::time_point_sec( 1446652800 ))
#endif
// #416 enforce_white_list is inconsistently applied
#ifndef HARDFORK_416_TIME
#define HARDFORK_416_TIME (fc::time_point_sec( 1446652800 ))
#endif
// #419 Account can pay fees in blacklisted asset
#ifndef HARDFORK_419_TIME
#define HARDFORK_419_TIME (fc::time_point_sec( 1446652800 ))
#endif
// #436 Prevent margin call from being triggered unless feed < call price
#ifndef HARDFORK_436_TIME
#define HARDFORK_436_TIME (fc::time_point_sec( 1450288800 ))
#endif
// #445 Refund create order fees on cancel
#ifndef HARDFORK_445_TIME
#define HARDFORK_445_TIME (fc::time_point_sec( 1450288800 ))
#endif
// #453 Hardfork to retroactively correct referral percentages
#ifndef HARDFORK_453_TIME
#define HARDFORK_453_TIME (fc::time_point_sec( 1450288800 ))
#endif
// #480 Fix non-BTS MIA core_exchange_rate check
#ifndef HARDFORK_480_TIME
#define HARDFORK_480_TIME (fc::time_point_sec( 1450378800 ))
#endif
// #483 Operation history numbering change
#ifndef HARDFORK_483_TIME
#define HARDFORK_483_TIME (fc::time_point_sec( 1450378800 ))
#endif
// #538 Buyback accounts
#ifndef HARDFORK_538_TIME
#define HARDFORK_538_TIME (fc::time_point_sec( 1456250400 ))
#endif
// #555 Buyback accounts
#ifndef HARDFORK_555_TIME
#define HARDFORK_555_TIME (fc::time_point_sec( 1456250400 ))
#endif
// #563 Stealth fee routing
#ifndef HARDFORK_563_TIME
#define HARDFORK_563_TIME (fc::time_point_sec( 1456250400 ))
#endif
// #572 Allow asset to update permission flags when no supply exists
#ifndef HARDFORK_572_TIME
#define HARDFORK_572_TIME (fc::time_point_sec( 1456250400 ))
#endif
// #615 Fix price feed expiration check, so websocket server will never spam too much data
#ifndef HARDFORK_615_TIME
#define HARDFORK_615_TIME (fc::time_point_sec( 1458752400 ))

#endif
