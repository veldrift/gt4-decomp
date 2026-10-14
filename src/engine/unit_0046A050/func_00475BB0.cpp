/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { char p0[0x14]; int f14; int f18; char p1[8]; void *f24; void *f28; };
extern "C" void func_00475870(O *, void *) throw();
extern "C" void *func_00475AF0(int, void *, void *) throw();
extern "C" int func_00475BB0(O *o, int ev) {
    void *p = o->f24;
    if (!p) return 0;
    void *q = o->f28;
    if (!q) {
        func_00475870(o, p);
        return 0;
    }
    if (o->f18) {
        if (ev == 0x26) { func_00475870(o, func_00475AF0(3,p,q)); return 1; }
        if (ev == 0x28) { func_00475870(o, func_00475AF0(2,p,q)); return 1; }
    }
    if (o->f14) {
        if (ev == 0x25) { func_00475870(o, func_00475AF0(1,p,q)); return 1; }
        if (ev == 0x27) { func_00475870(o, func_00475AF0(0,p,q)); return 1; }
    }
    return 0;
}
