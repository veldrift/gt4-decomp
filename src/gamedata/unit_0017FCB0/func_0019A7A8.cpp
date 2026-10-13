#include "types.h"

struct Vec;

extern "C" {
void func_001C95B0(void *arg0, s32 arg1);      /* extern */
void func_005CD8E8(Vec *v);                    /* extern */

struct func_0019A7A8_arg0 {
    char pad0[0xA0];
    void *unkA0;
    char pad1[0x4];
    char unkA4[0];
};

void func_0019A7A8(void *arg0) {
    void **p = &((struct func_0019A7A8_arg0 *)arg0)->unkA0;
    void *temp_v0;

    temp_v0 = *p;
    if (temp_v0 != 0) {
        func_001C95B0(temp_v0, 3);
    }
    *p = 0;
    func_005CD8E8((Vec *)((char *)arg0 + 0xA4));
}
}
