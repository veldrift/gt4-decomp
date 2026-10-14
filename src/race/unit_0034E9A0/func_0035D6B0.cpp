/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;

struct Info {
    u8 type;
    u8 n;
    char pad2[2];
    u8 b4[0x28];
    u8 b2C[0x10];
    s8 b3C[0x10];
};
struct Tmp { char pad[0x30]; f32 f30; f32 f34; };
struct Wheel { char pad0[0x28]; f32 f28; f32 f2C; char pad30[0xEC - 0x30]; };
struct S {
    char pad0[0x2C];
    f32 f2C;
    char pad30[0x480 - 0x30];
    f32 f480;
    char pad484[0x53C - 0x484];
    f32 f53C;
    f32 f540;
    char pad544[0x56C - 0x544];
    f32 f56C;
    char pad570[0x57C - 0x570];
    f32 f57C;
    char pad580[4];
    f32 f584;
};
struct Self {
    char pad0[0x10];
    char *car;
    char pad14[0x104 - 0x14];
    S s;
};

extern s32 D_00620784;
extern s32 D_00620788;

extern "C" Info *func_00359510(char *) throw();
extern "C" Tmp *func_00359F50(Self *) throw();
extern "C" f32 func_0057D1F0(f32);
extern "C" f32 func_0057D380(f32);

static inline bool isPos(Info *info, s32 i) { if (i >= info->n) return false; return info->b3C[i] > 0; }
static inline bool isNeg(Info *info, s32 i) { if (i >= info->n) return false; return info->b3C[i] < 0; }
static inline bool is1(s32 m) { return m == 1; }
static inline u8 at(u8 *base, s32 k) { return base[k]; }
static inline u8 at4(Info *info, s32 k) { return info->b4[k]; }
static inline u8 idxOf(Info *info, s32 i) { if (i >= info->n) return 0; return at4(info, i + 0x10); }
static inline u8 *rowC(Info *info) { return (u8 *)info + 0xC; }
static inline char *sub8(char *car) { return car + 8; }

extern "C" void func_0035D6B0(Self *self) {
    Info *info;
    S *s;
    s32 i;
    f32 k;
    char *car;
    s = &self->s;
    car = self->car;
    info = func_00359510(car);
    k = s->f57C;
    for (i = 0; i < info->n; i++) {
        Wheel *w = (Wheel *)((char *)self + 0x164 + i * 0xEC);
        s32 idx = info->b2C[i];
        f32 a = *(f32 *)(car + idx * 4 + 0x10);
        f32 t;
        if (isPos(info, i)) {
            t = -a * k;
        } else if (isNeg(info, i)) {
            t = a * k;
        } else {
            t = 0.0f;
        }
        if (isPos(info, i) && info->type == 1 && D_00620788 != 0) {
            f32 b = *(f32 *)(car + idxOf(info, i) * 4 + 0x2C4);
            Tmp *o = func_00359F50(self);
            f32 ang = o->f30;
            b *= func_0057D380(ang);
            b -= o->f34 / func_0057D1F0(ang);
            f32 g = s->f480;
            t += g * b * func_0057D1F0(s->f56C);
        }
        if (D_00620784 != 0) {
            t -= s->f584 * *(f32 *)(car + idx * 4 + 0x40) * s->f2C;
        }
        w->f2C = s->f540 + t;
        u8 m = at(rowC(info), i + 0x10);
        f32 c = *(f32 *)(sub8(car) + idx * 4 + 0x20);
        f32 u;
        if (m == 0) {
            u = -c * k;
        } else if (is1(m)) {
            u = c * k;
        } else {
            u = 0.0f;
        }
        w->f28 = s->f53C + u;
    }
}
