typedef int s32;

struct Str {
    char *p;
    char pad[0xC];
};

extern "C" void func_001DC5F8(void *, int);
extern "C" void func_001DC650(void *, void *);
extern "C" void *func_001F4D58(void *);
extern "C" s32 func_001F4DA8(void *);
extern "C" void *func_001F64E8(void *, int);
extern "C" void *func_001F6648(void *, int, int);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" char *func_00314AD8(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);


static inline void setResult(void **ret, Str *tmp, s32 value) {
    func_002FE278(tmp, value);
    if ((void *)ret != (void *)tmp) {
        void *p = tmp->p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*ret != 0) {
            func_003285F8(*ret);
        }
        *ret = p;
    }
    func_002FC870(tmp, 2);
}

extern "C" void MNetwork__joinGameMGCL(void **arg0, void *arg1, s32 arg2, char *arg3) {
    Str sp0;
    if (arg2 > 0) {
        Str a;
        Str b;
        Str *pa;
        s32 v6 = 0;
        s32 v4;
        func_001DC650(&sp0, arg1);
        pa = &a;
        func_002FC8C8(pa, arg3);
        v4 = func_002FE250(pa->p);
        if (arg2 >= 2) {
            Str *t = &b;
            func_00312370(t, arg3 + 4);
            v6 = (s32)func_00314AD8(t->p);
            func_00312318(t, 2);
        }
        if (func_001F64E8(sp0.p, v4) == 0) {
            setResult(arg0, &b, 0);
            func_002FC870(pa, 2);
            func_001DC5F8(&sp0, 2);
            return;
        }
        if (func_001F6648(sp0.p, v4, v6) == 0) {
            setResult(arg0, &b, 0);
            func_002FC870(pa, 2);
            func_001DC5F8(&sp0, 2);
            return;
        }
        if (func_001F4D58(sp0.p) == 0) {
            setResult(arg0, &b, 0);
            func_002FC870(pa, 2);
            func_001DC5F8(&sp0, 2);
            return;
        }
        if (func_001F4DA8(sp0.p) == 0) {
            setResult(arg0, &b, 0);
            func_002FC870(pa, 2);
            func_001DC5F8(&sp0, 2);
            return;
        }
        setResult(arg0, &b, 1);
        func_002FC870(pa, 2);
        func_001DC5F8(&sp0, 2);
    }
}
