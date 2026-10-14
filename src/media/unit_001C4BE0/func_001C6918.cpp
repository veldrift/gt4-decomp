/* compiler: ee-gcc2.96-no-strict-aliasing */
struct A { char p[0x1DD8]; int f1dd8; };
struct B0 { char *vptr; int pad[3]; };
struct Fr { int n; char p[12]; };
struct O { char p[0x4C]; char *vptr; char *f50; char tail[0xC]; };
extern char *D_00622F4C;
extern char D_00661B70[];
extern char D_006614F8[];
extern char D_00660CD8[];
extern "C" int func_001C6AA0(A *);
extern "C" void func_001CBFE0(void *);
extern "C" void func_001CC060(void *, int);
extern "C" int func_001D1038(void *, void *, int, int);
extern "C" void func_001D11D0(void *, int);
extern "C" B0 *func_001D16E0(void *, int);

extern "C" int func_001C6918(A *a) {
    B0 b0;
    char data[0xC80];
    Fr fr;
    O o;
    if (a->f1dd8 != 0)
        return func_001C6AA0(a);
    char *g = D_00622F4C;
    func_001D16E0(&b0, *(int *)(g + 0x39E28));
    O *po = &o;
    char *dp = data;
    fr.n = 0;
    func_001CBFE0(po);
    char *fin = D_006614F8;
    po->vptr = D_00661B70;
    po->f50 = 0;
    func_001D11D0(po, 0);
    po->f50 = dp;
    if (func_001D1038(po, &b0, 0, 0) != 0) {
        po->vptr = fin;
        func_001CC060(po, 0);
        b0.vptr = D_00660CD8;
        return -1;
    }
    int n = fr.n;
    po->vptr = fin;
    func_001CC060(po, 0);
    b0.vptr = D_00660CD8;
    return n;
}
