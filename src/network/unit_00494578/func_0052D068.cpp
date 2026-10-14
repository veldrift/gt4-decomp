struct Ops { char p[0xC]; void (*end)(); char p2[8]; void (*close)(int); };
struct Obj { int h; int x; int p; char gap[0x3C]; int a, b; };
extern Ops *D_0064B4B0;
extern "C" int func_00538C68(int *);
extern "C" void func_0053E0B8(int);
extern "C" int func_0052D068(Obj *o) {
    D_0064B4B0->close(o->h);
    func_00538C68(&o->a);
    func_00538C68(&o->b);
    int p = o->p;
    if (p) {
        func_0053E0B8(p);
        o->p = 0;
    }
    D_0064B4B0->end();
    return 0;
}
