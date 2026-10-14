struct G { char pad[0x38CB0]; unsigned char b[0x20]; };
struct G2 { char pad[0x38CBC]; int v; };
extern "C" G *D_00622F4C;
extern int PDISTD__UNIT_MANAGER[];
extern char PDISTD__LOCALE[], D_006235A8[];
extern "C" int func_0048EE98(void *, unsigned);
extern "C" void func_004434E8(void *, int);
extern "C" void func_00472528(int *, int);
extern "C" void func_00103F18(int);
extern "C" void func_00460580(void);
extern "C" void func_004360B8(int a) {
    func_0048EE98(PDISTD__LOCALE, a);
    ((G2 *)D_00622F4C)->v = a;
    func_004434E8(D_006235A8, a);
    func_00472528(PDISTD__UNIT_MANAGER, a);
    unsigned char *p = D_00622F4C->b;
    PDISTD__UNIT_MANAGER[0] = p[0x10];
    PDISTD__UNIT_MANAGER[1] = p[0x11];
    PDISTD__UNIT_MANAGER[2] = p[0x12];
    func_00103F18(a);
    func_00460580();
}
