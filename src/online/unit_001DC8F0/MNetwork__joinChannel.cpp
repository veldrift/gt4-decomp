typedef int s32;

struct Str {
    char *p;
    char pad[0xC];
};

extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, void *) throw();
extern "C" s32 func_001F16A8(void *);
extern "C" s32 func_001F2358(void *);
extern "C" s32 func_001F2958(void *);
extern "C" s32 func_001F2B40(void *, s32, const char *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" const char *func_00314AD8(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

static inline void assign(void **arg0, Str *h) {
    if ((void *)arg0 != (void *)h) {
        void *p = h->p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*arg0 != 0) {
            func_003285F8(*arg0);
        }
        *arg0 = p;
    }
}

extern "C" void MNetwork__joinChannel(void **arg0, void *arg1, s32 arg2, void **arg3) {
    Str sp0;
    Str o10;
    Str o20;
    if (arg2 > 0) {
        const char *name = 0;
        func_001DC650(&sp0, arg1);
        Str *p10 = &o10;
        func_002FC8C8(p10, arg3);
        s32 v = func_002FE250(p10->p);
        Str *p20;
        if (arg2 >= 2) {
            p20 = &o20;
            func_00312370(p20, arg3 + 1);
            name = func_00314AD8(p20->p);
            func_00312318(p20, 2);
        } else {
            p20 = &o20;
        }
        if (func_001F2B40(sp0.p, v, name) == 0) {
            func_002FE278(p20, 0);
            assign(arg0, p20);
            func_002FC870(p20, 2);
            func_002FC870(p10, 2);
            func_001DC5F8(&sp0, 2);
            return;
        }
        if (func_001F16A8(sp0.p) == 0) {
            func_002FE278(p20, 0);
            assign(arg0, p20);
            func_002FC870(p20, 2);
            func_002FC870(p10, 2);
            func_001DC5F8(&sp0, 2);
            return;
        }
        if (func_001F2358(sp0.p) == 0) {
            func_002FE278(p20, 0);
            assign(arg0, p20);
            func_002FC870(p20, 2);
            func_002FC870(p10, 2);
            func_001DC5F8(&sp0, 2);
            return;
        }
        if (func_001F2958(sp0.p) == 0) {
            func_002FE278(p20, 0);
            assign(arg0, p20);
            func_002FC870(p20, 2);
            func_002FC870(p10, 2);
            func_001DC5F8(&sp0, 2);
            return;
        }
        func_002FE278(p20, 1);
        assign(arg0, p20);
        func_002FC870(p20, 2);
        func_002FC870(p10, 2);
        func_001DC5F8(&sp0, 2);
    }
}
