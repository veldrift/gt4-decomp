typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

extern "C" f32 func_0045ADA0(struct Obj *arg0, s32 arg1) {
    char *base = (char *)arg0 + arg0->unk2DC * 0x16C;
    return *(f32 *)(arg1 * 0x34 + base + 0x70);
}
