/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00364BB0(s32, s32, f32, f32);                /* extern */
f32 func_00364C40(s32, s32, f32, f32);          /* extern */
f32 func_00364C60(s32, s32, f32, f32);                /* extern */

struct func_00459C10_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_00459C10_arg1 {
    char pad0[0x4];
    s32 unk4;
};
struct func_00459C10_temp_a2 {
    char pad0[0x18];
    f32 unk18;
    s32 unk1C;
};

void *func_00459C10(struct func_00459C10_arg0 *arg0, struct func_00459C10_arg1 *arg1, s32 arg2) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    s32 temp_s0;
    struct func_00459C10_temp_a2 *temp_a2;

    temp_a2 = (struct func_00459C10_temp_a2 *)((arg2 * 0x10) + (s32)arg1);
    temp_s0 = temp_a2->unk1C;
    temp_f21 = func_00364C40(arg1->unk4, temp_s0, 0.0f, 0.0f);
    temp_f20 = func_00364BB0(arg1->unk4, temp_s0, 0.0f, 0.0f) + ((struct func_00459C10_temp_a2 *)((temp_s0 * 0x10) + (s32)arg1))->unk18;
    temp_f0 = func_00364C60(arg1->unk4, temp_s0, 0.0f, 0.0f);
    arg0->unk0 = temp_f21;
    arg0->unk4 = temp_f20;
    arg0->unk8 = temp_f0;
    return arg0;
}
