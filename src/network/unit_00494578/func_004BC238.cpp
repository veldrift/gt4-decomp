/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent {
    int w0;
    int w4;
    int w8;
    char pad[0xEC - 0xC];
};
struct Ctx {
    char pad0[0xC];
    int *p0C;
    char pad10[0x18];
    void *p28;
    int *p2C;
    char pad30[8];
    int *p38;
    char pad3C[4];
    Ent *t40;
};
extern char D_006452D4[];
extern "C" void func_004BC6E8(Ctx *);
extern "C" int func_004BFDA0(Ctx *, void *, void *, int *, int);
extern "C" int func_004C0860(Ctx *, int, int, Ent *);
extern "C" int func_004C0F30(Ctx *, int);
extern "C" void func_004C8F08(void *, void *);
extern "C" void func_004C8FD8(void *, void *);

extern "C" int func_004BC238(void) {
    char sp[0x60];
    Ctx **gp = (Ctx **)D_006452D4;
    int s0;
    if (*(*gp)->p2C == 0x65) return 0x80000277;
    Ent *t = (*gp)->t40;
    if (t->w4 == 0) return 0;
    int v = t->w0 - 1;
    t->w0 = v;
    if (v < 0) (*gp)->t40->w0 = 0;
    {
        Ent *e = (*gp)->t40 + (*gp)->t40->w0;
        s0 = func_004C0F30((*gp), e->w8);
    }
    if (s0 == 0) {
        {
            Ent *e = (*gp)->t40 + (*gp)->t40->w0;
            s0 = func_004C0860(*gp, 0x300, e->w8, e);
        }
        if (s0 == 0) {
            Ent *e = (*gp)->t40 + (*gp)->t40->w0;
            *(*gp)->p0C = e->w8;
            e = (*gp)->t40 + (*gp)->t40->w0;
            func_004C8FD8(sp, (char *)e + 0x28);
            func_004C8F08((*gp)->p28, sp);
            *(*gp)->p38 = 0;
            e = (*gp)->t40 + (*gp)->t40->w0;
            s0 = func_004BFDA0(*gp, (char *)e + 0xC, (*gp)->p28, (*gp)->p38, 1);
            if (s0 >= 0) {
                Ent *t2 = (*gp)->t40;
                int c = t2->w4 - 1;
                t2->w4 = c;
                if (c == 0) (*gp)->t40->w0 = 0;
                s0 = 1;
            } else {
                func_004BC6E8(*gp);
            }
        } else {
            func_004BC6E8(*gp);
        }
    } else {
        func_004BC6E8(*gp);
    }
    return s0;
}
