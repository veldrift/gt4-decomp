#include "types.h"

f32 func_00364CE0(s32, s32, f32, f32);                /* extern */
f32 func_00364D00(s32, s32, f32, f32);                /* extern */

struct func_00459B48_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

struct func_00459B48_arg1 {
    char pad0[4];
    s32 unk4;
};

struct func_00459B48_elem {
    f32 unk0;
    f32 unk4;
    char pad8[4];
    s32 unkC;
};

void *func_00459B48(struct func_00459B48_arg0 *arg0, struct func_00459B48_arg1 *arg1, s32 arg2) {
    struct func_00459B48_elem *e;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f23;
    s32 temp_s3;

    e = (struct func_00459B48_elem *)((char *)arg1 + (arg2 << 4) + 0x10);
    temp_s3 = e->unkC;
    temp_f23 = e->unk4;
    temp_f20 = func_00364CE0(arg1->unk4, temp_s3, 0.0f, 0.0f) * 0x1.ca5dc00000000p+5f + e->unk0;
    temp_f0 = func_00364D00(arg1->unk4, temp_s3, 0.0f, 0.0f) * 0x1.ca5dc00000000p+5f;
    arg0->unk0 = temp_f23;
    arg0->unk4 = temp_f20;
    arg0->unk8 = temp_f0;
    return arg0;
}
