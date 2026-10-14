/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline void rect(f32 *r, f32 x, f32 y, f32 w, f32 h) { r[0]=x; r[1]=y; r[2]=w; r[3]=h; }

struct Movie {
    char pad0[0x10];
    f32 w;
    f32 h;
};

struct Self {
    char pad0[0xC];
    Movie *movie;
    void *unk10;
    char pad14[8];
    s32 unk1C;
};

extern "C" void func_0022A910(void *, void *);
extern "C" char *func_002314E8(void *);
extern "C" f32 func_002317C8(void *);
extern "C" void func_00231C10(void *);
extern "C" void func_00231C48(void *);
extern "C" void func_00472DE8(void *);
extern "C" void func_004735A0(s32 *);
extern "C" void func_004735C8(s32 *);
extern "C" void func_004742A0(void *, void *, f32, s32);
extern "C" void func_00474368(void *, void *);
extern "C" void func_00475CA0(void *, void *, s32);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7844(f32, f32, f32);
extern "C" void func_004A7890(f32, f32, f32);

extern "C" void mFlashPS2__virtual_13(Self *self, void *arg1, f32 fw, f32 fh, f32 alpha) {
    f32 v[4];
    s32 m[12];
    f32 r[4];
    f32 zero;
    if (self->unk1C != 0) {
        if (self->unk10 == 0) return;
        if (self->movie == 0) return;
    } else {
        if (self->movie == 0) return;
    }
    zero = 0.0f;
    v[2] = fw;
    v[3] = fh;
    v[0] = zero;
    v[1] = zero;
    func_0022A910(v, func_002314E8(arg1));
    func_00472DE8(m);
    func_004A53F8();
    func_004735A0(m);
    {
        Movie *mv = self->movie;
        f32 mw = mv->w;
        f32 mh = mv->h;
        f32 s = minf(v[2] / mw, v[3] / mh);
        f32 w = mw * s;
        f32 h = mh * s;
        rect(r, v[0] + (v[2] - w) * 0.5f,
             v[1] + (v[3] - h) * 0.5f, w + 0.5f, h + 0.5f);
        func_004A7844(r[0], r[1], zero);
        func_004A7890(s, s, 1.0f);
    }
    func_00231C10(arg1);
    func_00474368(self->movie, m);
    {
        s32 col = ((s32)(func_002317C8(arg1) * 128.0f) << 24) | 0xFFFFFF;
        if (self->unk1C != 0) {
            func_00475CA0(self->unk10, m, col);
        } else {
            func_004742A0(self->movie, m, alpha, col);
        }
    }
    func_00231C48(arg1);
    func_004735C8(m);
    func_004A5400();
}
