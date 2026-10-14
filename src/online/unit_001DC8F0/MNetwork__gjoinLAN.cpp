typedef int s32;
struct RefCounter;
struct Str { char *p; };

extern char D_006959D8[];

extern "C" void func_001DC5F8(void *, s32) throw();
extern "C" void func_001DC650(void *, s32) throw();
extern "C" s32 func_001F6930(s32, s32, const char *);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, s32);
extern "C" void func_00312370(void *, void *);
extern "C" Str *func_00314920(s32);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);

static inline const char *cstr(Str *s) {
    char *d = s->p;
    s32 len = ((s32 *)d)[-4];
    if (len == 0)
        return D_006959D8;
    d[len] = 0;
    return s->p;
}

extern "C" void MNetwork__gjoinLAN(s32 *dst, s32 a1, s32 n, s32 *obj) {
    struct F { s32 h[4]; s32 k[4]; s32 s[4]; s32 r[4]; } fr;
    if (n >= 2) {
        func_001DC650(fr.h, a1);
        s32 *pk = fr.k;
        func_002FC8C8(pk, obj);
        s32 sv = func_002FE250(pk[0]);
        s32 *ps = fr.s;
        func_00312370(ps, obj + 1);
        s32 h0 = fr.h[0];
        Str *p = func_00314920(ps[0]);
        s32 v = func_001F6930(h0, sv, cstr(p));
        s32 *pr = fr.r;
        func_002FE278(pr, v != 0);
        if (dst != pr) {
            s32 x = pr[0];
            if (x != 0)
                func_003285A8((RefCounter *)x);
            s32 old = *dst;
            if (old != 0)
                func_003285F8((RefCounter *)old);
            *dst = x;
        }
        func_002FC870(pr, 2);
        func_00312318(ps, 2);
        func_002FC870(pk, 2);
        func_001DC5F8(fr.h, 2);
    }
}
