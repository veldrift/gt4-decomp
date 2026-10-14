struct SW {
    char pad0[4];
    void *vptr;
    char pad8[0xC];
    int f14, f18, f1C, f20, f24, f28, f2C;
    float f30, f34, f38;
    int f3C, f40;
};
extern "C" void *mActor__structor_0(void *);
extern char mSwitchActor__vtable[];

extern "C" void mSwitchActor__structor_0(SW *a) {
    mActor__structor_0(a);
    a->vptr = mSwitchActor__vtable;
    a->f14 = 0;
    a->f18 = 0;
    a->f1C = 0;
    a->f20 = 0;
    a->f24 = 0;
    a->f28 = 0;
    a->f2C = 0;
    a->f30 = 20.0f;
    a->f34 = 20.0f;
    a->f38 = 0x1.111110p-5f;
    a->f3C = 0;
    a->f40 = 0;
}
