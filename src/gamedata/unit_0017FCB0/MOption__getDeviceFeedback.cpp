typedef int s32;

struct H {
    void *p;
    char pad[12];
};

extern "C" void func_0017FAD0(void *, int) throw();
extern "C" void func_0017FB28(void *, void *) throw();
extern "C" s32 func_0018FD50(void *, void *, void *, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" int func_00312370(void *, void *);
extern "C" char *func_00314AD8(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

extern "C" void MOption__getDeviceFeedback(H *dst, void *a1, s32 n, char *args) {
    if (n >= 2) {
        H o0, h1, h2, h3;
        s32 v = 0;
        func_0017FB28(&o0, a1);
        H *p1 = &h1;
        func_00312370(p1, args);
        H *p2 = &h2;
        func_00312370(p2, args + 4);
        H *p3;
        if (n >= 3) {
            p3 = &h3;
            func_002FC8C8(p3, args + 8);
            v = func_002FE250(p3->p);
            func_002FC870(p3, 2);
        } else {
            p3 = &h3;
        }
        void *o = o0.p;
        char *c1 = func_00314AD8(p1->p);
        char *c2 = func_00314AD8(p2->p);
        func_002FE278(p3, func_0018FD50(o, c1, c2, v));
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
        func_00312318(p1, 2);
        func_0017FAD0(&o0, 2);
    }
}
