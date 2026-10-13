typedef float f32;

struct Obj {
    char pad[4];
    f32 unk4;
    f32 unk8;
};

extern "C" void func_003AA2A8(Obj *arg0, f32 fparg0) {
    f32 temp_f0 = arg0->unk4 * fparg0;
    f32 temp_f1 = arg0->unk8 + temp_f0;
    arg0->unk8 = temp_f1 - (f32)(int)temp_f1;
}
