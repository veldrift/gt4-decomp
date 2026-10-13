#include "types.h"
#define NULL 0
#include "m2c_macros.h"

typedef struct { u8 p0; u8 n; u8 pad[0x12]; u8 b[1]; } V;
extern "C" V *func_00359510(s32);
struct func_00365100_arg0 {
    s32 unk0;
    u8 unk4;
};

extern "C" s8 func_00365100(struct func_00365100_arg0 *arg0, s32 arg1, s8 *arg2, s8 *arg3) {
    V *temp_v0;
    u8 var_a1;
    if (arg0->unk4 != 0) {
        return 0;
    }
    temp_v0 = func_00359510(arg0->unk0 + 0x600);
    var_a1 = 0;
    if (arg1 < temp_v0->n) {
        var_a1 = temp_v0->b[arg1];
    }
    *arg2 = -0x64;
    *arg3 = 0x64;
    return M2C_FIELD((var_a1 + arg0->unk0), s8 *, 0x96);
}
