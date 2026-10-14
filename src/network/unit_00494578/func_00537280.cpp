struct Mgr {
    int (*v00)(void *);
    int (*v04)(void *, int);
    char pad08[4];
    int (*v0C)(void *, int);
    char pad10[0xC];
    int (*v1C)(void *);
    char pad20[0x24];
    int (*v44)(void *, int);
    void *(*v48)(void *, int);
    char pad4C[0x98];
    int (*vE4)(void *, int);
    char padE8[0x20];
    int f108;
    char pad10C[0x10];
    int f11C;
    void (*cb)(void *);
    int cbdata;
};
struct Obj {
    char pad0[0x100];
    int *f100;
    int f104;
};
struct Cfg {
    char pad[0x5C];
    int w5C;
};
struct Arg {
    int w0;
    unsigned short h4;
    unsigned short h6;
};
struct Sp {
    int code;
    int data;
};
struct Handle {
    int w0;
    int w4;
    int w8;
    int wC;
    int w10;
};
extern Mgr *D_0064B4B4;
extern Cfg *D_0064B47C;
extern "C" void func_005310D0(Obj *, int) throw();
extern "C" void func_005316E8(int) throw();
extern "C" int func_00534990(Obj *, int) throw();

extern "C" int func_00537280(Obj *o, int unused, unsigned s6, Arg *s3) {
    Handle *s1;
    int s5;
    if (o == 0) return -1;
    if (s6 >= 0x40) return -1;
    if (D_0064B4B4 != 0 && D_0064B4B4->f108 != 0) return 8;
    s5 = o->f104;
    if (s5 == 0x100) return -1;
    if (D_0064B4B4 != 0) s1 = (Handle *)D_0064B4B4->v48(o, s5);
    else s1 = 0;
    if (s1 == 0) return -1;
    if (D_0064B4B4 != 0 && D_0064B4B4->f11C == 1) {
        D_0064B4B4->v1C(o);
        if (D_0064B4B4->cb != 0) {
            Sp sp;
            sp.data = D_0064B4B4->cbdata;
            sp.code = 7;
            D_0064B4B4->cb(&sp);
            D_0064B4B4->cb = 0;
            D_0064B4B4->cbdata = 0;
        }
        return 8;
    }
    if (o->f100 == 0) return -1;
    o->f100[3] = 4;
    func_005310D0(o, -1);
    if (D_0064B4B4 != 0) {
        D_0064B4B4->v44(o, s6);
        if (D_0064B4B4 != 0) D_0064B4B4->f108 = 1;
    }
    func_005316E8(s3->w0);
    {
        Cfg *cfg = D_0064B47C;
        s1->w0 = cfg->w5C;
        s1->w8 = s3->h4;
        s1->w10 = s3->h6;
    }
    func_00534990(o, 1);
    if (D_0064B4B4 != 0) {
        D_0064B4B4->vE4(o, -1);
        if (D_0064B4B4 != 0) D_0064B4B4->v0C(o, s5);
    }
    return 8;
}
