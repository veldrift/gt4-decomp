typedef int s32;

struct H {
    void *p;
    char pad[12];
};

struct Str {
    char *p;
    char pad[0xC];
};

extern "C" void func_0017FAD0(void *, int) throw();
extern "C" void func_0017FB28(void *, void *) throw();
extern "C" s32 func_001900E0(void *, s32, const char *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" Str *func_00314920(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

extern "C" void MOption__save(H *dst, void *a1, s32 n, char *args) {
    if (n >= 2) {
        H o0, h1, h2, h3;
        func_0017FB28(&o0, a1);
        H *p1 = &h1;
        func_002FC8C8(p1, args);
        H *p2 = &h2;
        func_00312370(p2, args + 4);
        void *o = o0.p;
        s32 v = func_002FE250(p1->p);
        Str *t = func_00314920(p2->p);
        const char *c;
        s32 len = *(s32 *)(t->p - 0x10);
        if (len == 0) {
            c = "";
        } else {
            t->p[len] = 0;
            c = t->p;
        }
        func_002FE278(&h3, func_001900E0(o, v, c));
        H *p3 = &h3;
        if (dst != p3) {
            void *s0 = p3->p;
            if (s0 != 0) {
                func_003285A8(s0);
            }
            if (dst->p != 0) {
                func_003285F8(dst->p);
            }
            dst->p = s0;
        }
        func_002FC870(p3, 2);
        func_00312318(p2, 2);
        func_002FC870(p1, 2);
        func_0017FAD0(&o0, 2);
    }
}
