typedef int s32;
typedef short s16;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Handle {
    void *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

struct VEntryF {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObjF {
    char pad[4];
    VEntryF *vtbl;
};

extern Rep D_00659FA8;
extern s32 PDISTD__UNIT_MANAGER;
extern void *D_00624984;
extern char D_00693040[];

extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" f32 func_00472940(s32 *p, f32 x);
extern "C" char *func_00472680(s32 *p);
extern "C" void func_00490A40(void *a, void *b, const char *fmt, ...);
extern "C" s32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline f32 vcallf(VObjF *o) {
    VEntryF *e = (VEntryF *)((char *)o->vtbl + 0x60);
    return e->fn((char *)o + e->delta);
}

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MUnit__GetVelocityString(void **arg0, s32 arg1, void **arg2) {
    if (arg1 > 0) {
        char buf[0x80];
        Handle h;
        s32 spare[4];
        Str s;
        f32 vel;
        s32 *g;

        vel = vcallf((VObjF *)*arg2);
        g = &PDISTD__UNIT_MANAGER;
        if (*g != 0) {
            vel = func_00472940(g, vel * 0x1.1C71C6p-2f);
        }
        func_00490A40(D_00624984, buf, D_00693040,
                      (s32)(vel * 10.0f + 0.5f), func_00472680(g));
        {
            Rep *r = &D_00659FA8;
            Str *ps;
            char *bp;
            char *d;
            ps = &s;
            bp = buf;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
            func_005C2630(ps, 0, -1, bp, func_0057F260(bp));
            {
                Handle *ph = &h;
                func_00314B20(ph, ps);
                if ((void *)arg0 != (void *)ph) {
                    void *p = ph->p;
                    if (p != 0) {
                        func_003285A8(p);
                    }
                    if (*arg0 != 0) {
                        func_003285F8(*arg0);
                    }
                    *arg0 = p;
                }
                func_00312318(ph, 2);
            }
            str_release(ps);
        }
    }
}
