typedef int s32;
typedef long s64;
typedef unsigned char u8;
struct Q { char pad[0x3E]; u8 b3e; };
struct G { char pad[4]; char x4[0xC0]; s32 c4; };
struct Base {
    char pad[0x12C];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3(s32);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual Q *v18();
};
struct Obj : public Base {
    char pad2[0x1000];
};
extern "C" {
void func_003BB440(s32, s32);
s64 *func_00441248(void *);
void func_004452F8(void *, void *);
s32 func_00447C78(void *);
}
extern char D_0068D898[];
extern G *D_00622F4C;
extern "C" void func_00118540(Obj *self) {
    char *m = (char *)self + 0x130;
    func_003BB440((s32)self, (s32)D_0068D898);
    *(s32 *)((char *)self + 0xB0) = 0;
    s32 n = D_00622F4C->c4;
    if (self->v18()->b3e < n) {
        n = self->v18()->b3e;
    }
    self->v9(n);
    self->v3(func_00447C78(D_00622F4C->x4));
    char *t = (char *)D_00622F4C + 0x13938;
    s32 eq = (~*func_00441248(t)) == 0;
    if (!eq) {
        func_004452F8(m, func_00441248(t));
    }
}
