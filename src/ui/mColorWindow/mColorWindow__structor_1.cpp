typedef int s32;

struct Vec {
    char pad[4];
    char *start;
    char *finish;
    char *eos;
};

extern "C" void func_00105280(void *, s32);
extern "C" void func_00203118(void *, s32);
extern "C" void mComposite__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" const char **MColor__tf(void);

extern void *mColorWindow__vtable;

extern "C" void mColorWindow__structor_1(char *arg0, s32 arg1) {
    Vec *v = (Vec *)(arg0 + 0xB0);
    char *p;
    char *e;
    char *s;
    s32 n;
    char *sp[4];
    *(void **)(arg0 + 4) = &mColorWindow__vtable;
    func_00105280(arg0 + 0xC4, 2);
    s = v->start;
    e = v->finish;
    p = s;
    sp[0] = s;
    if (s != e) {
        do {
            char *q = p;
            p += 0x10;
            func_00203118(q, 2);
        } while (p != e);
        s = v->start;
    }
    n = (v->eos - s) >> 4;
    if (s != 0) {
        func_00326798(s, n << 4, 4, *MColor__tf());
    }
    mComposite__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_00326798(arg0, 0x100, 4, "RefCounter");
    }
}
