struct Ctx;
struct Ctx {
    int w0;
    int w4;
    int w8;
    char pad0C[0x1018];
    int w1024;
    char pad1028[0x1030];
    void (*fn2058)(void *, int, int);
};
struct Obj {
    char pad0[0x3C];
    int w3C;
    char pad40[4];
    Ctx *ctx;
};
struct Mgr {
    char pad[0x18];
    void (*f18)(int);
};
extern Mgr *D_0064B4B0;
extern char D_006C40D8[];
extern char D_0086C848[];
extern char D_0086C850[];
extern int D_0064C11C;
extern int D_0064C120;
extern int D_0064C12C;
extern int D_0064C130;
extern "C" int func_0053BD78(Obj *, int *) throw();
extern "C" void func_00540EB0(int);
extern "C" int func_00540F10(int, const char *, int, int);
extern "C" int func_00540F98(int, int *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A48D8(void *, int, unsigned);

extern "C" int func_0053C6D0(Obj *o) {
    int sp0 = 0;
    int sp4;
    int sp8;
    int v = func_0053BD78(o, &sp0);
    if (v != 0 || sp0 != 0) {
    if (o->ctx->w1024 == 0xC8 && sp0 != 0) {
        int f = o->ctx->w8;
        if (f & 0x1000) {
            sp4 = 0;
            if (func_00540F10(o->ctx->w4, D_006C40D8, 0, 1) == 0 && func_00540F98(o->ctx->w4, &sp4) == 0) {
                func_005A4724(D_0086C848, (const void *)sp4, 4);
                D_0064C11C = 1;
                D_0064C12C = v;
            }
        } else if (f & 0x800) {
            sp8 = 0;
            if (func_00540F10(o->ctx->w4, D_006C40D8, 0, 1) == 0 && func_00540F98(o->ctx->w4, &sp8) == 0) {
                func_005A4724(D_0086C850, (const void *)sp8, 4);
                D_0064C120 = 1;
                D_0064C130 = v;
            }
        }
    }
    func_00540EB0(o->ctx->w4);
    o->ctx->w4 = 0;
    D_0064B4B0->f18(o->ctx->w0);
    {
        Ctx *c = o->ctx;
        c->w0 = 0;
        c->fn2058(o, v, (c->w8));
    }
    o->ctx->fn2058 = 0;
    func_005A48D8(&o->ctx->w1024, 0, 0x100C);
    o->w3C = 0;
    }
    return v;
}
