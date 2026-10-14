struct Obj { char pad0[8]; int a; char pad1[0x40]; int b; int c; char pad2[0x228]; };
extern "C" int func_00538BF8(Obj **, int);
extern "C" int func_00537FC8(void *, int, int);
extern "C" void func_0051D8E0(Obj *);
extern "C" Obj *func_0051D838(int a, int b, int c) {
    Obj *p = 0;
    for (;;) {
        func_00538BF8(&p, 0x2dc);
        if (!p) break;
        p->a = a;
        if (func_00537FC8((char *)p + 0x6c, b, 0)) break;
        p->b = b;
        if (func_00537FC8((char *)p + 0x54, c, 0)) break;
        p->c = c;
        return p;
    }
    func_0051D8E0(p);
    return 0;
}
