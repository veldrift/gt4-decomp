/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x2A8];
    s32 f2A8;
    char pad2AC[0x2B4 - 0x2AC];
    void *f2B4;
    s32 f2B8;
    char pad2BC[0x2D4 - 0x2BC];
    f32 f2D4;
    f32 f2D8;
    f32 f2DC;
    f32 f2E0;
    f32 f2E4;
    f32 f2E8;
    f32 f2EC;
    f32 f2F0;
    f32 f2F4;
    f32 f2F8;
    f32 f2FC;
    char pad300[0x308 - 0x300];
    f32 f308;
    s32 i30C;
};

struct Font {
    char pad0[0x1C];
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    char pad2C[0x4C - 0x2C];
    s32 f4C;
    char pad50[0x64 - 0x50];
    s32 f64;
};

struct Vtx { f32 x, y, z; };
struct E16 { char b[16]; };

extern Font *PDISTD__global_font_manager;
extern E16 D_00618770[];

extern "C" f32 func_0011DBE8(void *, int, f32);
extern "C" void func_00120540(f32, f32, f32, f32);
extern "C" void func_001205D8(f32 *, f32 *, f32, f32);
extern "C" void func_00490290(Font *, const char *);
extern "C" void func_00490518(Font *, f32, f32, f32, f32);
extern "C" void func_004906F8(Font *, s32);
extern "C" void func_00490700(Font *, s32, s32, s32, s32);
extern "C" f32 func_00490830(Font *);
extern "C" f32 func_00490860(Font *);
extern "C" void func_00490890(Font *, f32, f32);
extern "C" void func_00490950(Font *, const char *, ...);
extern "C" void func_0049FD50(s32, void *, s32, s32, s32, s32);
extern "C" void func_004A1638(s32);
extern "C" void func_004A2808(s32, f32);
extern "C" Vtx *func_004A5B70(s32);
extern "C" void func_004A7288(f32, f32, f32, f32, f32, f32);
extern "C" void func_004AB040(s32);
extern "C" void func_004AB2B0(E16 *);
extern "C" void func_004AB2E8(f32, f32, f32);

static inline void setScale(Font *f, f32 a, f32 b) {
    f->f28 = b;
    f->f24 = a;
}

static inline void resetBox(Font *f) {
    func_00490700(f, 0, 0, (s32)f->f1C, (s32)f->f20);
}

extern "C" void func_00121FF0(Obj *self, s32 arg1, s32 arg2, f32 y) {
    f32 lo = self->f2D8;
    f32 h = self->f2E0;
    f32 mid = (self->f2D4 + self->f2DC) * 0.5f;
    f32 inv = 1.0f / self->f2E4;
    f32 yc = y < lo ? lo : y;
    func_00490290(PDISTD__global_font_manager, "hn_16");
    func_004AB2E8(0.9f, 0.5f, 0x1.999998p-4f);
    f32 w = self->f2FC - self->f2F8;
    func_004A7288(w, h, 0.0f, w, lo, 0.0f);
    func_004A1638(9);
    func_004AB040(6);
    func_004A2808(0x44, 1.0f);
    func_00490290(PDISTD__global_font_manager, "hc_20");
    setScale(PDISTD__global_font_manager, 0.7f, 0.7f);
    func_00490518(PDISTD__global_font_manager, 0.9f, 0.9f, 0.9f, 1.0f);
    func_00490890(PDISTD__global_font_manager, self->f2EC * 0.5f + 15.0f, self->f2F4 - (yc + 4.0f + 2.0f));
    if (self->f2B8 != 0) {
        func_00490950(PDISTD__global_font_manager, "%.1tm", (s32)(mid * 10.0f));
    } else {
        func_00490950(PDISTD__global_font_manager, "%.1tml", (s32)(mid * 0x1.45C73Cp-11f * 1000.0f));
    }
    void *curve = self->f2B4;
    f32 t = (self->f308 / (f32)self->i30C) / self->f2E8;
    f32 va;
    f32 vb;
    if (self->f2A8 != 0) {
        va = func_0011DBE8(curve, 0, mid) * 3.6f;
    } else {
        va = 0.0f;
    }
    if (self->f2A8 != 0) {
        vb = func_0011DBE8(curve, 1, mid) * 3.6f;
    } else {
        vb = 0.0f;
    }
    f32 inv2 = 1.0f / self->f2E4;
    f32 sideB = -1.0f;
    func_00490290(PDISTD__global_font_manager, "hc_20");
    setScale(PDISTD__global_font_manager, 0x1.999998p-1f, 0x1.999998p-1f);
    f32 sideA = -1.0f;
    f32 dirA = inv2;
    if (arg1 != 0 && arg2 != 0) {
        if (vb < va) {
            sideA = 1.0f;
        } else {
            sideB = 1.0f;
        }
        dirA = -inv2;
    }
    if (arg1 != 0) {
        f32 px = mid;
        f32 py = va * t + y;
        if (py - 30.0f < lo) {
            sideA = 1.0f;
        }
        func_004AB2B0(&D_00618770[0]);
        func_001205D8(&px, &py, dirA, sideA);
        f32 xx = self->f2EC * 0.5f;
        f32 yy = self->f2F4 - py;
        f32 th = func_00490860(PDISTD__global_font_manager);
        f32 tw = func_00490830(PDISTD__global_font_manager);
        if (dirA < 0.0f) {
            { Font *f = PDISTD__global_font_manager; f->f64 = 10; f->f4C = 1; }
            func_00490700(PDISTD__global_font_manager, (s32)(xx - 128.0f - 45.0f), (s32)(yy - th), 0x80, (s32)tw);
        } else {
            func_00490890(PDISTD__global_font_manager, xx + 45.0f, yy);
        }
        if (self->f2B8 != 0) {
            func_00490950(PDISTD__global_font_manager, "%.1tkm/h", (s32)(va * 10.0f));
        } else {
            func_00490950(PDISTD__global_font_manager, "%.1tmph", (s32)(va * 0x1.3E249p-1f * 10.0f));
        }
        resetBox(PDISTD__global_font_manager);
        func_004906F8(PDISTD__global_font_manager, 0);
    }
    if (arg2 != 0) {
        f32 px = mid;
        f32 py = vb * t + y;
        if (py - 30.0f < lo) {
            sideB = 1.0f;
        }
        func_004AB2B0(&D_00618770[1]);
        func_001205D8(&px, &py, inv2, sideB);
        func_00490890(PDISTD__global_font_manager, self->f2EC * 0.5f + 45.0f, self->f2F4 - py);
        if (self->f2B8 != 0) {
            func_00490950(PDISTD__global_font_manager, "%.1tkm/h", (s32)(vb * 10.0f));
        } else {
            func_00490950(PDISTD__global_font_manager, "%.1tmph", (s32)(vb * 0x1.3E249p-1f * 10.0f));
        }
    }
    func_004AB2E8(1.0f, 0.0f, 0.0f);
    Vtx *v = func_004A5B70(3);
    v[0].x = mid - inv;
    v[0].y = h;
    v[0].z = 0.0f;
    v[1].x = mid - inv;
    v[1].y = lo;
    v[1].z = 0.0f;
    v[2].x = mid + inv;
    v[2].y = h;
    v[2].z = 0.0f;
    v[3].x = mid + inv;
    v[3].y = lo;
    v[3].z = 0.0f;
    func_0049FD50(4, v, 0, 0, 0, 0);
    func_00120540(mid, inv * 8.0f, yc + 11.0f, yc + 1.0f);
    func_004AB040(9);
}
