typedef float f32;

struct func_00421C28_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

struct func_00421C28_arg1 {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

extern "C" struct func_00421C28_arg0 *func_00421C28(struct func_00421C28_arg0 *arg0, struct func_00421C28_arg1 *arg1) {
    f32 scaled = arg1->unkC;
    f32 doubled = arg1->unk8 + arg1->unk8;
    arg0->unk0 = arg1->unk4;
    arg0->unk4 = doubled;
    arg0->unk8 = scaled * 3.0f;
    return arg0;
}
