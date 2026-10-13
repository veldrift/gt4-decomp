typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

extern "C" f32 func_0045ABD0(Obj *arg0, s32 arg1) {
    char *e = (char *)arg0 + arg0->unk2DC * 0x16C;
    return *(f32 *)(e + arg1 * 0x34 + 0x58);
}
