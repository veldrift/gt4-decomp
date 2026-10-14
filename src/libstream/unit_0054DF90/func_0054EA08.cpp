/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int data[0x94 / 4]; };
struct Obj { char pad[0x198]; Block current; Block pending; };
extern int D_00654D8C;
extern "C" int func_005ADCE0(int);
extern "C" void func_005ADCC0(int);
extern "C" void func_0054EA08(Obj *o) {
    func_005ADCE0(D_00654D8C);
    o->current = o->pending;
    o->pending.data[0] = 0;
    func_005ADCC0(D_00654D8C);
}
