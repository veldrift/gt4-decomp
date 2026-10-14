/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xA4]; void *vt; char padA8[0x48]; int f0; int f4; };
extern char D_006B00D0[], D_00688C58[];
extern "C" void *func_004B1C10(Obj *, int, void *, int, int, int);
extern "C" int func_004ACA40(Obj *p, int a, int b, int c, int d, int e) {
    func_004B1C10(p, c, D_006B00D0, 0, e, b);
    p->vt = D_00688C58;
    p->f0 = a;
    p->f4 = d;
}
