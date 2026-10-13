typedef float f32;
typedef short s16;

struct func_00350ED0_arg0 {
    char pad0[0x54C];
    f32 unk54C;
    char pad550[0xAE];
    s16 unk5FE;
    char pad600[0x138];
    f32 unk738;
    f32 unk73C;
};

void func_00350ED0(struct func_00350ED0_arg0 *arg0) {
    f32 *p738 = &arg0->unk738;
    f32 *p73C = &arg0->unk73C;
    f32 temp_f1;
    f32 temp_f3;
    f32 temp_f1_2;

    temp_f1 = *p73C;
    temp_f3 = arg0->unk54C;
    temp_f1_2 = temp_f1 + (((((f32) arg0->unk5FE - *p738) * 0x1.F4p+9f) - (temp_f1 * 0x1.9p+5f)) * temp_f3);
    *p73C = temp_f1_2;
    *p738 = *p738 + (temp_f1_2 * temp_f3);
}
