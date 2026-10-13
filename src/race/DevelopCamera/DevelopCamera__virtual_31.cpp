typedef unsigned char u8;

struct Res {
    char pad[0x16B];
    u8 f;
};

struct Base {
    virtual void *v00(int);
    virtual void *v01(int);
    virtual void *v02(int);
    virtual void *v03(int);
    virtual void *v04(int);
    virtual void *v05(int);
    virtual void *v06(int);
    virtual void *v07(int);
    virtual void *v08(int);
    virtual void *v09(int);
    virtual void *v10(int);
    virtual void *v11(int);
    virtual void *v12(int);
    virtual void *v13(int);
    virtual void *v14(int);
    virtual void *v15(int);
    virtual void *v16(int);
    virtual void *v17(int);
    virtual void *v18(int);
    virtual void *v19(int);
    virtual void *v20(int);
    virtual void *v21(int);
    virtual void *v22(int);
    virtual void *v23(int);
    virtual void *v24(int);
    virtual void *v25(int);
    virtual void *v26(int);
};

struct Obj : Base {
    char pad[0x9BC - 4];
    int m9BC;
};

extern "C" u8 DevelopCamera__virtual_31(Obj *arg0) {
    Res *r = (Res *)arg0->v26(arg0->m9BC);
    if (r == 0) {
        return 1;
    }
    return r->f;
}
