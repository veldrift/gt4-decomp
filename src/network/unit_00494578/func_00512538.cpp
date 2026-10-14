struct Obj { char pad[0x18]; int flag; char text[0x11]; };
extern char D_0064A318[];
extern int D_008A0194;
extern int (*D_008A03BC)(Obj *, int);
extern "C" void func_005A6AB0(void *, void *, int) throw();
extern "C" int func_00512538(int a, int b, int c, Obj *p) {
    if (p->flag == 0) func_005A6AB0(D_0064A318, p->text, 0x11);
    if (D_008A03BC) D_008A03BC(p, D_008A0194);
    return 0x30;
}
