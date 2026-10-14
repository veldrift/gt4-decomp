/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p0[0x18]; int state; char p1[0x2c]; unsigned short flags; char p2[0xad4]; short count; };
extern "C" void func_0049E698(Obj *) throw();
extern "C" void func_0049E780(Obj *) throw();
extern "C" void func_0049E918(Obj *) throw();
extern "C" void func_0049EB90(Obj *, float);
extern "C" void func_0049ECF8(Obj *);
extern "C" void func_0049EE00(Obj *);
extern "C" void func_0049F038(Obj *);
extern "C" void func_0049EA80(Obj *p, float f) {
    if ((unsigned short)(p->flags & 1)) func_0049ECF8(p);
    if (p->flags & 2) func_0049EE00(p);
    if (p->flags & 4) func_0049F038(p);
    if ((p->flags & 0x18) != 0x18) return func_0049E698(p);
    if (p->flags & 0x40) {
        if (p->count < 2) return func_0049EB90(p, f);
        p->state = 0x16;
    } else {
        if (p->count < 3) return func_0049E918(p);
        return func_0049E780(p);
    }
}
