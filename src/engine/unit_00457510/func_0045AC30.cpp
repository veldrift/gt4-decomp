typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

extern "C" f32 func_0045AC30(struct Obj *arg0, s32 arg1) {
    s32 n = arg0->unk2DC * 0x16C;
    char *p = (char *)(arg1 * 0x34 + (n + (s32)arg0));
    return *(f32 *)(p + 0x60);
}
