/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Rec {
    f32 xyz[3];
    char pad[0x34];
    f32 w[4];
};

struct Self {
    Rec arr[7];
    char pad230[0x8];
    s32 flag;
    char *obj;
};

extern "C" void func_0038E7C8(f32 *, f32 *, f32) throw();
extern "C" void func_0038F240(Self *self);
extern "C" void func_004523B0(f32, f32, f32);
extern "C" void func_004523E8(f32, f32, f32, f32);
extern "C" void func_00452408(f32);

extern "C" void func_0038F168(Self *self, s32 idx) {
    f32 tmp[4];
    if (self->flag != 0) {
        char *o = self->obj;
        f32 neg = -*(f32 *)(o + 0xA78);
        func_0038E7C8(tmp, self->arr[idx].w, 1.0f / *(f32 *)(o + 0x38));
        func_004523B0(self->arr[idx].xyz[0] * neg, self->arr[idx].xyz[1] * neg, self->arr[idx].xyz[2] * neg);
        func_004523E8(tmp[0], tmp[1], tmp[2], tmp[3]);
        func_00452408(1.0f);
    } else {
        func_0038F240(self);
    }
}
