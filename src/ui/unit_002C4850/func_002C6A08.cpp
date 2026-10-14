/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(char *, s32);
};

struct Vobj {
    char pad0[4];
    char *vt;
};

struct Self {
    char pad0[8];
    s32 f8;
    char padC[4];
    Vobj *f10;
    void *f14;
    void *f18;
    char pad1c[4];
    f32 x0;
    f32 y0;
    f32 dx;
    f32 dy;
    char pad30[4];
    s32 f34;
    s32 rows;
    s32 selr;
    s32 cols;
    s32 selc;
};

extern "C" void func_00231508(s32 a, void *b);
extern "C" void func_00231798(s32 a, void *b);
extern "C" void func_00265E50(void *a, s32 b);
extern "C" void func_002C57D8(Self *s, s32 a, f32 x, f32 y) throw();
extern "C" void func_002C5880(Self *s, s32 a, s32 b, f32 x, f32 y) throw();
extern "C" s32 func_002C6180(Self *s, s32 a, s32 b, s32 c) throw();
extern "C" s32 func_002C6208(Self *s, s32 a, s32 b, s32 c) throw();

extern "C" void func_002C6A08(Self *a, s32 arg1) {
    if (arg1 == a->f8) {
        s32 s3 = 0;
        f32 f21;
        func_00231508(arg1, a->f10);
        {
            Vobj *o = a->f10;
            VEntry *e = (VEntry *)(o->vt + 0x2E8);
            e->fn((char *)o + e->delta, a->f8);
        }
        func_00231798(a->f8, a->f10);
        func_00265E50(a->f18, 1);
        func_00265E50(a->f14, 1);
        f21 = a->y0;
        if (a->rows > 0) {
            do {
                f32 f20 = a->x0;
                s32 s2 = 0;
                if (a->cols > 0) {
                    do {
                        if (func_002C6180(a, a->f34, s3, s2) != 0) {
                            s32 a1 = 0;
                            s32 s1;
                            if (s3 == a->selr) {
                                a1 = (s2 == a->selc);
                            }
                            func_002C57D8(a, a1, f20, f21);
                            for (s1 = 0; s1 < 4; s1++) {
                                func_002C5880(a, func_002C6208(a, s3, s2, s1), s1, f20, f21);
                            }
                        }
                        s2++;
                        f20 += a->dx;
                    } while (s2 < a->cols);
                }
                f21 += a->dy;
                s3++;
            } while (s3 < a->rows);
        }
        func_00265E50(a->f18, 0);
        func_00265E50(a->f14, 0);
    }
}
