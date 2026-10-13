#include "types.h"

struct Obj00529228 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" s32 func_005292C0(void *arg0, s32 arg1, s32 arg2);   /* solved */
extern "C" s32 func_0053EE38(s32 arg0, s32 arg1, s32 arg2);     /* solved */

extern "C" s32 func_00529228(void *arg0, s32 arg1, s32 arg2) {
    s32 r = 0xD2F2;
    if (arg0 != 0) {
        s32 v = ((struct Obj00529228 *)arg0)->unk8;
        if (v != 0) {
            r = func_0053EE38(v, arg1, arg2);
            if (r != 0) {
                return func_005292C0(arg0, arg1, arg2);
            }
        } else {
            return func_005292C0(arg0, arg1, arg2);
        }
    }
    return r;
}
