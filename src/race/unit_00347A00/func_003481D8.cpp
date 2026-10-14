/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

struct P {
    char pad0[0x462];
    u8 f462;
    u8 f463;
    char pad1[0x467 - 0x464];
    u8 f467;
    char pad2[0x48C - 0x468];
    f32 f48C;
    f32 f490;
    char pad3[0x4BA - 0x494];
    u16 f4BA;
    u8 f4BC;
    char pad5[0x4FA - 0x4BD];
    s16 f4FA;
    char pad6[0x514 - 0x4FC];
    f32 f514;
    char pad7[0x522 - 0x518];
    u8 f522;
    char pad8[0x53C - 0x523];
    f32 f53C;
    f32 f540;
};

struct S {
    char pad0[0x202];
    u16 f202;
    char pad1[0x237 - 0x204];
    u8 f237;
};

struct A {
    char pad0[2];
    s8 f2;
    char pad1[9];
    s16 fC;
};

struct Obj {
    char pad0[0x10];
    S *s;
    char pad1[0x104 - 0x14];
    P p;
};

extern "C" s32 func_003F1F98(void *);

static inline float sqrt_s(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_003481D8(Obj *self, A *b, s32 mode) {
    P *p = &self->p;
    S *s = self->s;
    if (p->f4BC == 0 && p->f4BA == 0 && p->f467 != 8) {
        if (mode == 3) {
            f32 f0 = p->f48C;
            f32 f1;
            p->f48C = 0.0f;
            f1 = 1.0f - f0;
            p->f514 = f1;
            if (f1 != p->f48C) {
                p->f463 = 0;
                p->f462 = 0;
            }
            return;
        }
        if (mode == 6 && (b->f2 != 0 || b->fC != 0)) {
            p->f514 = 0.0f;
            return;
        }
        if (s->f237 == 1 && p->f490 > 0x1.999998p-1f) {
            p->f514 = 0.0f;
            return;
        }
        if (func_003F1F98((char *)s + 0x234) != 0 && p->f490 > 0x1.999998p-1f) {
            f32 x = p->f53C;
            f32 y = p->f540;
            if (sqrt_s(x * x + y * y) < 0x1.1c71c6p-2f) {
                p->f514 = 0.0f;
                return;
            }
        }
        if (p->f522 == 0) {
            p->f514 = 0.0f;
            if (p->f48C < 0.25f) p->f514 = 1.0f;
        } else {
            p->f514 = 1.0f;
            if (p->f4FA < s->f202) p->f514 = 0.0f;
        }
    } else {
        p->f514 = 0.0f;
    }
}
