typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

extern "C" f32 func_0045AC00(struct Obj *arg0, s32 arg1) {
    char *base = (char *)arg0 + arg0->unk2DC * 0x16C;
    char *elem = (char *)(arg1 * 0x34) + (s32)base;
    return *(f32 *)(elem + 0x5C);
}
