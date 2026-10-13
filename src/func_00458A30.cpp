typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x30];
};

extern "C" s32 func_004588C0(Obj *o, s32 flags, void *buf);
extern "C" void func_00458AB8(Obj *o, s32 flags, const void *buf, f32 a, f32 b, f32 c);

extern "C" void func_00458A30(Obj *o, s32 flags, f32 a, f32 b, f32 c) {
    if (flags & 1) {
        return;
    }
    char buf[0x10];
    if (!func_004588C0(o, flags, buf)) {
        return;
    }
    return func_00458AB8(o, flags, buf, a, b, c);
}
