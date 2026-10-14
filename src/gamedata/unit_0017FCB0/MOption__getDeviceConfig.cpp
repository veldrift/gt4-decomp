typedef int s32;

struct H {
    void *p;
    char pad[12];
    void *get() const { return p; }
};

extern "C" void func_0017FAD0(void *, int) throw();
extern "C" void func_0017FB28(void *, void *) throw();
extern "C" s32 func_0018FCC8(void *, char *, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" int func_00312370(void *, void *);
extern "C" char *func_00314AD8(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

extern "C" void MOption__getDeviceConfig(H *dst, void *a1, s32 n, char *args) {
    if (n > 0) {
        H o0, h1, h2;
        s32 v = 0;
        func_0017FB28(&o0, a1);
        H *p1 = &h1;
        func_00312370(p1, args);
        if (n >= 2) {
            func_002FC8C8(&h2, args + 4);
            v = func_002FE250(h2.get());
            func_002FC870(&h2, 2);
        }
        H *p2 = &h2;
        void *o = o0.p;
        char *c = func_00314AD8(p1->p);
        func_002FE278(p2, func_0018FCC8(o, c, v));
        if (dst != p2) {
            void *s0 = p2->p;
            if (s0 != 0) {
                func_003285A8(s0);
            }
            if (dst->p != 0) {
                func_003285F8(dst->p);
            }
            dst->p = s0;
        }
        func_002FC870(p2, 2);
        func_00312318(p1, 2);
        func_0017FAD0(&o0, 2);
    }
}
