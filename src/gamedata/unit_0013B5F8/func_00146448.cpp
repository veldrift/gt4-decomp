typedef int s32;
typedef float f32;
struct Text5 { char bytes[5]; };
struct Obj { char pad[0x174]; s32 value; };
extern void *D_00624984;
extern "C" const Text5 D_0068F520;
extern "C" f32 func_001465D8(Obj *);
extern "C" void func_00490A40(void *, void *, s32, s32);
extern "C" void func_00146448(Obj *self, s32 size, char *buffer) {
    s32 value = self->value;
    f32 scale = func_001465D8(self);
    if (value <= 0) {
        *(Text5 *)buffer = D_0068F520;
        return;
    }
    if (scale <= 0.0f) {
        *(Text5 *)buffer = D_0068F520;
        return;
    }
    s32 shown = (s32)(((f32)self->value / func_001465D8(self)) * 1000.0f + 0.5f);
    func_00490A40(D_00624984, buffer, size, shown);
}
