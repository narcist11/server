#ifndef _DB_H
#define _DB_H
/* This code generated by make_db_h.   Copyright (c) 2007 Tokutek */
#include <sys/types.h>
#if defined(__cplusplus)
extern "C" {
#endif
#define DB_VERSION_MAJOR 4
#define DB_VERSION_MINOR 3
#define DB_VERSION_PATCH 29
#ifndef _TOKUDB_WRAP_H
#define DB_VERSION_STRING "Tokutek: TokuDB"
#else
#define DB_VERSION_STRING "Tokutek: TokuDB (wrapped bdb)"
#endif
typedef struct __toku_db_btree_stat DB_BTREE_STAT;
typedef struct __toku_db_env DB_ENV;
typedef struct __toku_db_key_range DB_KEY_RANGE;
typedef struct __toku_db_lsn DB_LSN;
typedef struct __toku_db DB;
typedef struct __toku_db_txn DB_TXN;
typedef struct __toku_db_txn_active DB_TXN_ACTIVE;
typedef struct __toku_db_txn_stat DB_TXN_STAT;
typedef struct __toku_dbc DBC;
typedef struct __toku_dbt DBT;
typedef enum {
 DB_BTREE=1
} DBTYPE;
#define DB_VERB_DEADLOCK 1
#define DB_VERB_RECOVERY 2
#define DB_VERB_REPLICATION 4
#define DB_VERB_WAITSFOR 8
#define DB_DBT_MALLOC 4
#define DB_DBT_REALLOC 16
#define DB_DBT_USERMEM 32
#define DB_DBT_DUPOK 64
#define DB_ARCH_ABS 1
#define DB_ARCH_LOG 4
#define DB_CREATE 1
#define DB_PRIVATE 1048576
#define DB_RDONLY 16
#define DB_RECOVER 32
#define DB_THREAD 64
#define DB_TXN_NOSYNC 256
#define DB_LOCK_DEFAULT 1
#define DB_LOCK_OLDEST 7
#define DB_LOCK_RANDOM 8
#define DB_DUP 2
#define DB_NOOVERWRITE 22
#define DB_INIT_LOCK 8192
#define DB_INIT_LOG 16384
#define DB_INIT_MPOOL 32768
#define DB_INIT_TXN 131072
#define DB_KEYEMPTY -30997
#define DB_KEYEXIST -30996
#define DB_LOCK_DEADLOCK -30995
#define DB_NOTFOUND -30989
#define DB_BADFORMAT -30500
#define DB_FIRST 9
#define DB_GET_BOTH 10
#define DB_LAST 17
#define DB_NEXT 18
#define DB_NEXT_DUP 19
#define DB_PREV 25
#define DB_SET 28
#define DB_SET_RANGE 30
#define DB_RMW 536870912
/* in wrap mode, top-level function txn_begin is renamed, but the field isn't renamed, so we have to hack it here.*/
#ifdef _TOKUDB_WRAP_H
#undef txn_begin
#endif
struct __toku_db_btree_stat {
  char __toku_dummy0[12];
  u_int32_t bt_nkeys; /* 32-bit offset=12 size=4, 64=bit offset=12 size=4 */
  u_int32_t bt_ndata; /* 32-bit offset=16 size=4, 64=bit offset=16 size=4 */
  char __toku_dummy1[64];  /* Padding at the end */ 
};
struct __toku_db_env {
  struct __toku_db_env_internal *i;
  void* __toku_dummy0[44];
  char __toku_dummy1[96];
  int  (*close) (DB_ENV *, u_int32_t); /* 32-bit offset=276 size=4, 64=bit offset=456 size=8 */
  void* __toku_dummy2[2];
  void (*err) (const DB_ENV *, int, const char *, ...); /* 32-bit offset=288 size=4, 64=bit offset=480 size=8 */
  void* __toku_dummy3[1];
  int  (*open) (DB_ENV *, const char *, u_int32_t, int); /* 32-bit offset=296 size=4, 64=bit offset=496 size=8 */
  void* __toku_dummy4[9];
  int  (*set_data_dir) (DB_ENV *, const char *); /* 32-bit offset=336 size=4, 64=bit offset=576 size=8 */
  void* __toku_dummy5[2];
  void (*set_errcall) (DB_ENV *, void (*)(const char *, char *)); /* 32-bit offset=348 size=4, 64=bit offset=600 size=8 */
  void* __toku_dummy6[3];
  void (*set_errpfx) (DB_ENV *, const char *); /* 32-bit offset=364 size=4, 64=bit offset=632 size=8 */
  void* __toku_dummy7[2];
  int  (*set_flags) (DB_ENV *, u_int32_t, int); /* 32-bit offset=376 size=4, 64=bit offset=656 size=8 */
  void* __toku_dummy8[13];
  int  (*set_tmp_dir) (DB_ENV *, const char *); /* 32-bit offset=432 size=4, 64=bit offset=768 size=8 */
  void* __toku_dummy9[1];
  int  (*set_verbose) (DB_ENV *, u_int32_t, int); /* 32-bit offset=440 size=4, 64=bit offset=784 size=8 */
  void* __toku_dummy10[2];
  int  (*set_lg_bsize) (DB_ENV *, u_int32_t); /* 32-bit offset=452 size=4, 64=bit offset=808 size=8 */
  void* __toku_dummy11[1];
  int  (*set_lg_dir) (DB_ENV *, const char *); /* 32-bit offset=460 size=4, 64=bit offset=824 size=8 */
  void* __toku_dummy12[1];
  int  (*set_lg_max) (DB_ENV *, u_int32_t); /* 32-bit offset=468 size=4, 64=bit offset=840 size=8 */
  void* __toku_dummy13[2];
  int  (*log_archive) (DB_ENV *, char **[], u_int32_t); /* 32-bit offset=480 size=4, 64=bit offset=864 size=8 */
  void* __toku_dummy14[2];
  int  (*log_flush) (DB_ENV *, const DB_LSN *); /* 32-bit offset=492 size=4, 64=bit offset=888 size=8 */
  void* __toku_dummy15[7];
  int  (*set_lk_detect) (DB_ENV *, u_int32_t); /* 32-bit offset=524 size=4, 64=bit offset=952 size=8 */
  int  (*set_lk_max) (DB_ENV *, u_int32_t); /* 32-bit offset=528 size=4, 64=bit offset=960 size=8 */
  void* __toku_dummy16[16];
  int  (*set_cachesize) (DB_ENV *, u_int32_t, u_int32_t, int); /* 32-bit offset=596 size=4, 64=bit offset=1096 size=8 */
  void* __toku_dummy17[28];
  int  (*txn_begin) (DB_ENV *, DB_TXN *, DB_TXN **, u_int32_t); /* 32-bit offset=712 size=4, 64=bit offset=1328 size=8 */
  int  (*txn_checkpoint) (DB_ENV *, u_int32_t, u_int32_t, u_int32_t); /* 32-bit offset=716 size=4, 64=bit offset=1336 size=8 */
  void* __toku_dummy18[1];
  int  (*txn_stat) (DB_ENV *, DB_TXN_STAT **, u_int32_t); /* 32-bit offset=724 size=4, 64=bit offset=1352 size=8 */
  void* __toku_dummy19[3]; /* Padding at the end */ 
  char __toku_dummy20[16];  /* Padding at the end */ 
};
struct __toku_db_key_range {
  double less; /* 32-bit offset=0 size=8, 64=bit offset=0 size=8 */
  double equal; /* 32-bit offset=8 size=8, 64=bit offset=8 size=8 */
  double greater; /* 32-bit offset=16 size=8, 64=bit offset=16 size=8 */
  void* __toku_dummy0[161]; /* Padding at the end */ 
  char __toku_dummy1[88];  /* Padding at the end */ 
};
struct __toku_db_lsn {
  char __toku_dummy0[8];  /* Padding at the end */ 
};
struct __toku_db {
  struct __toku_db_internal *i;
  void* __toku_dummy0[3];
  void *app_private; /* 32-bit offset=16 size=4, 64=bit offset=32 size=8 */
  void* __toku_dummy1[39];
  char __toku_dummy2[96];
  int (*close) (DB*, u_int32_t); /* 32-bit offset=272 size=4, 64=bit offset=448 size=8 */
  int (*cursor) (DB *, DB_TXN *, DBC **, u_int32_t); /* 32-bit offset=276 size=4, 64=bit offset=456 size=8 */
  int (*del) (DB *, DB_TXN *, DBT *, u_int32_t); /* 32-bit offset=280 size=4, 64=bit offset=464 size=8 */
  void* __toku_dummy3[4];
  int (*get) (DB *, DB_TXN *, DBT *, DBT *, u_int32_t); /* 32-bit offset=300 size=4, 64=bit offset=504 size=8 */
  void* __toku_dummy4[15];
  int (*key_range) (DB *, DB_TXN *, DBT *, DB_KEY_RANGE *, u_int32_t); /* 32-bit offset=364 size=4, 64=bit offset=632 size=8 */
  int (*open) (DB *, DB_TXN *, const char *, const char *, DBTYPE, u_int32_t, int); /* 32-bit offset=368 size=4, 64=bit offset=640 size=8 */
  int (*put) (DB *, DB_TXN *, DBT *, DBT *, u_int32_t); /* 32-bit offset=372 size=4, 64=bit offset=648 size=8 */
  int (*remove) (DB *, const char *, const char *, u_int32_t); /* 32-bit offset=376 size=4, 64=bit offset=656 size=8 */
  int (*rename) (DB *, const char *, const char *, const char *, u_int32_t); /* 32-bit offset=380 size=4, 64=bit offset=664 size=8 */
  void* __toku_dummy5[10];
  int (*set_flags) (DB *, u_int32_t); /* 32-bit offset=424 size=4, 64=bit offset=752 size=8 */
  void* __toku_dummy6[6];
  int (*stat) (DB *, void *, u_int32_t); /* 32-bit offset=452 size=4, 64=bit offset=808 size=8 */
  void* __toku_dummy7[5];
  int (*set_bt_compare) (DB *, int (*)(DB *, const DBT *, const DBT *)); /* 32-bit offset=476 size=4, 64=bit offset=856 size=8 */
  void* __toku_dummy8[23]; /* Padding at the end */ 
  char __toku_dummy9[8];  /* Padding at the end */ 
};
struct __toku_db_txn_active {
  u_int32_t txnid; /* 32-bit offset=0 size=4, 64=bit offset=0 size=4 */
  char __toku_dummy0[4];
  DB_LSN lsn; /* 32-bit offset=8 size=8, 64=bit offset=8 size=8 */
  char __toku_dummy1[132];  /* Padding at the end */ 
};
struct __toku_db_txn {
  struct __toku_db_txn_internal *i;
  void* __toku_dummy0[18];
  char __toku_dummy1[24];
  int (*abort) (DB_TXN *); /* 32-bit offset=100 size=4, 64=bit offset=176 size=8 */
  int (*commit) (DB_TXN*, u_int32_t); /* 32-bit offset=104 size=4, 64=bit offset=184 size=8 */
  void* __toku_dummy2[1];
  u_int32_t (*id) (DB_TXN *); /* 32-bit offset=112 size=4, 64=bit offset=200 size=8 */
  void* __toku_dummy3[4]; /* Padding at the end */ 
};
struct __toku_db_txn_stat {
  void* __toku_dummy0[1];
  char __toku_dummy1[28];
  u_int32_t st_nactive; /* 32-bit offset=32 size=4, 64=bit offset=36 size=4 */
  char __toku_dummy2[8];
  DB_TXN_ACTIVE *st_txnarray; /* 32-bit offset=44 size=4, 64=bit offset=48 size=8 */
  void* __toku_dummy3[1]; /* Padding at the end */ 
  char __toku_dummy4[8];  /* Padding at the end */ 
};
struct __toku_dbc {
  struct __toku_dbc_internal *i;
  void* __toku_dummy0[18];
  char __toku_dummy1[112];
  int (*c_close) (DBC *); /* 32-bit offset=188 size=4, 64=bit offset=264 size=8 */
  void* __toku_dummy2[1];
  int (*c_del) (DBC *, u_int32_t); /* 32-bit offset=196 size=4, 64=bit offset=280 size=8 */
  void* __toku_dummy3[1];
  int (*c_get) (DBC *, DBT *, DBT *, u_int32_t); /* 32-bit offset=204 size=4, 64=bit offset=296 size=8 */
  void* __toku_dummy4[10]; /* Padding at the end */ 
};
struct __toku_dbt {
  void*data; /* 32-bit offset=0 size=4, 64=bit offset=0 size=8 */
  u_int32_t size; /* 32-bit offset=4 size=4, 64=bit offset=8 size=4 */
  u_int32_t ulen; /* 32-bit offset=8 size=4, 64=bit offset=12 size=4 */
  char __toku_dummy0[8];
  u_int32_t flags; /* 32-bit offset=20 size=4, 64=bit offset=24 size=4 */
  /* 4 more bytes of alignment in the 64-bit case. */
};
#ifdef _TOKUDB_WRAP_H
#define txn_begin txn_begin_tokudb
#endif
int db_env_create(DB_ENV **, u_int32_t);
int db_create(DB **, DB_ENV *, u_int32_t);
char *db_strerror(int);
int log_compare (const DB_LSN*, const DB_LSN *);
#if defined(__cplusplus)
}
#endif
#endif
