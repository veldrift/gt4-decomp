typedef float f32;

struct func_00421B08_arg0 {
    int unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_00421B08_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

extern "C" struct func_00421B08_arg0 *func_00421B08(struct func_00421B08_arg0 *arg0, struct func_00421B08_arg1 *arg1) {
    f32 t8 = arg1->unk8;
    f32 t4 = arg1->unk4;
    f32 m4 = t4 * 0x1.0p-1f;
    f32 t0 = arg1->unk0;
    f32 m8 = t8 * 0x1.555554p-2f;
    arg0->unk0 = 0;
    arg0->unk4 = t0;
    arg0->unk8 = m4;
    arg0->unkC = m8;
    return arg0;
}
