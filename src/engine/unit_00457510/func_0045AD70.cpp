typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

extern "C" f32 func_0045AD70(Obj *arg0, s32 arg1) {
    s32 prod = arg0->unk2DC * 0x16C;
    s32 idx = arg1 * 0x34;
    s32 base = prod + (s32)arg0;
    return *(f32 *)(idx + base + 0x6C);
}
