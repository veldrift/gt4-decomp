/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Str {
    char *p;
    char pad[0xC];
};

extern char D_006959D8[];

extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, void *) throw();
extern "C" s32 func_001F6828(void *, Str *, void *, s32, const char *, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void *func_00312370(void *, void *);
extern "C" Str *func_00314920(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_005A6AB0(void *, const char *, s32) throw();

struct Handle {
    char *p;
    char pad[12];
    Handle(void *src) { func_002FC8C8(this, src); }
    ~Handle() { func_002FC870(this, 2); }
    int get() { return func_002FE250(p); }
};

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}

extern "C" void MNetwork__gcreateLAN(void **arg0, void *arg1, s32 arg2, void **arg3) {
    Str sp0;
    Str o10;
    Str o20;
    char b30[0x20];
    Str o50;
    Str o60;
    s32 flag;
    if (arg2 >= 4) {
        func_001DC650(&sp0, arg1);
        Str *p10 = &o10;
        func_00312370(p10, arg3);
        Str *p20 = &o20;
        func_00312370(p20, arg3 + 1);
        func_005A6AB0(b30, c_str(func_00314920(p20->p)), 0x20);
        flag = 0;
        Str *p50 = &o50;
        func_002FC8C8(p50, arg3 + 2);
        s32 v = func_002FE250(p50->p);
        Str *p60 = &o60;
        func_00312370(p60, arg3 + 3);
        if (arg2 >= 5) {
            flag = Handle(arg3 + 4).get();
        }
        Str o70;
        Str *p70 = &o70;
        void *obj = sp0.p;
        Str *a = func_00314920(p10->p);
        const char *name = c_str(func_00314920(p60->p));
        func_002FE278(p70, func_001F6828(obj, a, b30, v, name, flag) != 0);
        if ((void *)arg0 != (void *)p70) {
            void *p = p70->p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_002FC870(p70, 2);
        func_00312318(p60, 2);
        func_002FC870(p50, 2);
        func_00312318(p20, 2);
        func_00312318(p10, 2);
        func_001DC5F8(&sp0, 2);
    }
}
