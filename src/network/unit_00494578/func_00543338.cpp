extern "C" {
#include "types.h"

/* memcpy and memset (Sony SDK): called by address so that gcc does not
   expand the fixed-size copy inline as a builtin. */
void *func_005A4724(void *dst, const void *src, unsigned int n);
void *func_005A48D8(void *dst, int c, unsigned int n);

struct NetRecord {
    char pad0[0x2C];
    u8 *key; /* 0x2C: 64-byte buffer */
};

NetRecord *func_00538988(s32 id) throw();
s32 func_005428E8(const u8 *buf) throw();

s32 func_00543338(s32 id, s32 arg1, u8 *out) {
    NetRecord *rec;

    rec = func_00538988(id);
    if (out != 0) {
        if (rec != 0 && func_005428E8(rec->key) == 0) {
            func_005A4724(out, rec->key, 0x40);
            return 0;
        }
        func_005A48D8(out, 0, 0x40);
    }
    return -1;
}

}
