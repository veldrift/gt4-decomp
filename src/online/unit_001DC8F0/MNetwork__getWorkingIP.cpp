typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
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

extern Rep D_00659FA8;
extern char D_006959D0[];

extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001F1080(void *ret, void *obj);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" s32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" s32 func_005C2A50(Str *self, Str *other, u32 pos, u32 n);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MNetwork__getWorkingIP(void **arg0, void *arg1) {
    Handle h0;
    Str s4;
    Str s;
    Handle h;
    Str *p4;
    const char *lit;
    s32 ok;

    func_001DC650(&h0, arg1);
    p4 = &s4;
    func_001F1080(p4, h0.p);
    lit = D_006959D0;
    {
        Str *ps;
        Rep *r = &D_00659FA8;
        char *d;
        ps = &s;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, lit, func_0057F260(lit));
        ok = func_005C2A50(p4, ps, 0, -1) != 0;
        str_release(ps);
    }
    if (ok) {
        Handle *ph = &h;
        func_00314B20(ph, p4);
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
    str_release(p4);
    func_001DC5F8(&h0, 2);
}
