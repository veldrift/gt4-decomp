/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned char u8;

static inline float sqrt_s(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

struct Cam { char pad0[0xC]; f32 fov; f32 x, y, z; char pad1[0x16D - 0x1C]; u8 flag; };
struct Lens { char pad[0x44]; f32 k; };
struct Tgt { char pad[0x18]; void *unk18; };

extern "C" f32 func_00344798(void *, f32);
extern "C" f32 func_003447F8(void *, f32);
extern "C" f32 func_00344828(void *, f32);
extern "C" void func_0036E9D8(f32 *) throw();
extern "C" s32 func_003FDD60(void *, f32 *, f32 *);
extern "C" f32 func_0057D380(f32);
extern "C" f32 func_005F5010(f32 *);
extern "C" void func_005F5230(f32 *, f32 *);
extern "C" void func_005F5268(f32 *, f32 *);

extern "C" s32 func_0037C9F0(Cam *self, Lens *lens, Tgt *tgt) {
    if (self->flag != 0)
        return 0;
    {
        s32 ret = 0;
        f32 v[3];
        f32 w[3];
        f32 *px = &w[0];
        void *o = tgt->unk18;
        f32 lim = lens->k * 0x1.66819ap-1f * (1.0f / func_0057D380(self->fov * 0.5f * 0x1.1df468p-6f));
        v[0] = self->x;
        v[1] = self->y;
        v[2] = self->z;
        f32 a = func_00344798(o, 0.0f);
        f32 b = func_003447F8(o, 0.0f);
        f32 c = func_00344828(o, 0.0f);
        f32 *py = &w[1];
        f32 *pz = &w[2];
        *px = a;
        *py = b;
        *pz = c;
        func_005F5268(px, v);
        if (lim < sqrt_s(func_005F5010(px))) {
            func_0036E9D8(px);
            *px *= lim;
            *py *= lim;
            *pz *= lim;
            func_005F5230(v, px);
            ret = func_003FDD60(tgt, v, 0) ^ 1;
        }
        return ret;
    }
}
