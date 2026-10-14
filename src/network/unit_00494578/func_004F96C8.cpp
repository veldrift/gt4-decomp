/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[0xccc]; int h0, h1, h2; char pad1[0x204]; int current; char pad2[0x21e0]; unsigned size; };
struct Desc { int a; unsigned size; };
extern char D_006C09D0[], D_006C09E0[];
extern unsigned D_0064952C;
extern Desc D_00649530;
extern "C" void func_004FAA88();
extern "C" void func_004FAAC8();
extern "C" void func_004FAB90();
extern "C" void func_004FAC00();
extern "C" int func_004F95A8(Obj *, void *, int, void (*)(), void (*)(), void (*)()) throw();
extern "C" int func_004F96C8(Obj *o) {
    int old = o->h0;
    if (old == -1) {
        int r = func_004F95A8(o, D_006C09D0, 0, func_004FAA88, func_004FAAC8, func_004FAC00);
        o->h0 = r;
        if (r == old) return 0;
    }
    old = o->h1;
    if (old == -1) {
        int r = func_004F95A8(o, D_006C09E0, 0, func_004FAA88, func_004FAAC8, func_004FAC00);
        o->h1 = r;
        if (r == old) return 0;
    }
    old = o->h2;
    if (old == -1) {
        D_0064952C = (o->size + 3) >> 2;
        D_00649530.size = o->size;
        int r = func_004F95A8(o, &D_00649530, 0, func_004FAA88, func_004FAB90, func_004FAC00);
        o->h2 = r;
        if (r == old) return 0;
    }
    o->current = o->h1;
    return 1;
}
