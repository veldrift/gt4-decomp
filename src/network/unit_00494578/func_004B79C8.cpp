/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot { int state; char pad[0x418]; };
struct Obj { char pad0[0x20]; Slot slots[2]; int cur; int unk85c; int done; };
extern "C" void func_004B7430(Obj *) throw();
extern "C" void func_004B51A8(Obj *, int) throw();
extern "C" int func_004B79C8(Obj *arg0) {
    if (arg0->done) return 1;
    Slot *s = &arg0->slots[1 - arg0->cur];
    switch (s->state) {
    case 0: return 0;
    case 1:
        func_004B7430(arg0);
        return 1;
    case 2:
        func_004B51A8(arg0, -1);
        return 1;
    }
    return 1;
}
