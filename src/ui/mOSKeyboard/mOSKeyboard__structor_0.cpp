typedef int s32;

struct Sub {
    s32 m0;
    s32 m4;
    s32 m8;
    s32 mC;
};

struct mOSKeyboard {
    char pad0[4];
    union {
        char *vtbl;
        s32 word;
    } u;
    s32 m8;
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18;
    s32 m1C;
    s32 m20;
    s32 m24;
    s32 m28;
    s32 m2C;
    s32 m30;
    s32 m34;
    s32 m38;
    s32 m3C;
    s32 m40;
    s32 m44;
    struct Sub sub;
    s32 m58;
    s32 m5C;
    s32 m60;
    s32 m64;
};

extern char mOSKeyboard__vtable[];
extern "C" s32 RefCounter__structor_0(struct mOSKeyboard *);

extern "C" void mOSKeyboard__structor_0(struct mOSKeyboard *arg0) {
    s32 spare[4];
    RefCounter__structor_0(arg0);
    struct Sub *p = &arg0->sub;
    arg0->m8 = 0;
    arg0->u.vtbl = mOSKeyboard__vtable;
    arg0->mC = 0;
    arg0->m10 = 0;
    arg0->m14 = 0;
    arg0->m18 = 0;
    arg0->m1C = 0;
    arg0->m20 = 0;
    arg0->m24 = 0;
    arg0->m28 = 0;
    arg0->m2C = 0;
    arg0->m30 = 0;
    arg0->m34 = 0;
    arg0->m38 = 0;
    arg0->m3C = 0;
    arg0->m40 = 0;
    arg0->m44 = 0;
    p->m4 = 0;
    p->m8 = 0;
    p->mC = 0;
    arg0->m58 = 0;
    arg0->m5C = 0;
    arg0->m60 = 0;
    arg0->m64 = 0;
    spare[0] = 0;
}
