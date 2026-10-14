typedef int s32;
struct Base {
    char pad[0x64];
    virtual void v0(s32);
    virtual void v1();
    virtual void v2();
    virtual void v3();
};
struct Obj : public Base { char pad2[0x100]; };
extern "C" {
void func_001032B0(char *);
void func_00574DA8(void *, s32);
void free(s32);
void func_005C1628(s32);
}
extern Obj *D_00618318;
extern char *D_0061831C;
extern s32 D_00618314;
extern "C" void func_00103E28(void) {
    if (D_00618318) {
        D_00618318->v2();
        D_00618318->v3();
        D_00618318->v0(2);
        D_00618318 = 0;
        func_001032B0(D_0061831C);
        char *p = D_0061831C;
        if (p) {
            func_00574DA8(p + 0x38, 2);
            func_00574DA8(p + 8, 2);
            func_005C1628((s32)p);
        }
        D_0061831C = 0;
    }
    if (D_00618314) {
        free(D_00618314);
        D_00618314 = 0;
    }
}
