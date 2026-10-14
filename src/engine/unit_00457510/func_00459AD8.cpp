typedef float f32;

struct Src {
    char pad[0x8];
    f32 unk8;
    char pad2[0x50 - 0x0C];
    f32 unk50;
};

struct Vec3 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

extern "C" Vec3 *func_00459AD8(Vec3 *arg0, Src *arg1) {
    f32 z = 0.0f;
    f32 sum = arg1->unk8 + arg1->unk50;
    arg0->unk0 = z;
    arg0->unk4 = sum;
    arg0->unk8 = z;
    return arg0;
}
