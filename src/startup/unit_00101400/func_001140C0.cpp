typedef int s32;
typedef unsigned char u8;
struct Base {
    char pad[0x12C];
    virtual void v0();
    virtual void v1();
    virtual s32 v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual s32 v9(s32);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void *v18();
};
struct Obj : public Base {
    char pad2[0x1000];
};
extern "C" {
void func_003BB440(s32, char *);
void func_003EDD80(void *, void *);
long *func_00441248(void *);
s32 func_004471E0(void *, char *);
s32 func_00447F48(s32, void *);
s32 func_0057F260(char *);
}
extern char *D_00622F4C;
extern "C" void func_001140C0(Obj *self) {
    char sp[0x20];
    char **gp = &D_00622F4C;
    func_003BB440((s32)self, *gp + 0x44);
    char *s0 = *gp + 4;
    if (func_0057F260(s0)) {
        func_004471E0(self->v18(), s0);
    }
    func_00447F48(self->v2(), sp);
    self->v9(*(u8 *)(sp + 0x11));
    char *t = *gp + 0x13938;
    s32 eq = (~*func_00441248(t)) == 0;
    if (!eq) {
        func_003EDD80(self, func_00441248(t));
    }
}
