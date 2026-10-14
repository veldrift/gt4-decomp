/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Inner {
    char pad0[0x18];
    s32 f18;
};

struct Obj {
    Inner *inner;
};

extern "C" s32 func_00451078(Obj *, s32) throw();
extern "C" s32 func_00455300(s32, s32, s32);
extern "C" s32 ModelSet2__texLOD(s32);
extern "C" s32 ModelSet2__texLevel(s32);

static inline float fabsf_(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" s32 func_00453248(Obj *self, s32 idx)
{
    if (self->inner == 0) {
        return 0;
    }
    s32 a0 = 1;
    if (!(fabsf_(*(float *)((char *)self + idx * 0x38 + 0xB8)) > 0x1.3ffffep+2f)) {
        a0 = 0;
    }
    s32 s2 = 0;
    s32 s4 = ModelSet2__texLevel(a0);
    s32 s3 = ModelSet2__texLOD(1);
    if (self->inner != 0) {
        s2 = self->inner->f18;
    }
    s32 s0 = 1;
    s32 v = func_00451078(self, ((idx >> 1) ^ 1) & 1);
    if (s2 != 0 && v != 0) {
        s0 = func_00455300(s2, idx & 1, v);
    }
    ModelSet2__texLevel(s4);
    ModelSet2__texLOD(s3);
    return s0;
}
