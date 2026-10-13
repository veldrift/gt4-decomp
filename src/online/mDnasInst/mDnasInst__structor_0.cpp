typedef int s32;

extern char mDnasInst__vtable[];

struct hObject__structor_0 {
    s32 m0;
    char *vtbl;
    s32 m8, mC;
    hObject__structor_0();
};

struct Pair {
    s32 a, b;
    Pair() {
        a = 0;
        b = 0;
    }
};

struct mDnasInst : hObject__structor_0 {
    Pair p;
    mDnasInst();
};

mDnasInst::mDnasInst() {
    vtbl = mDnasInst__vtable;
}
