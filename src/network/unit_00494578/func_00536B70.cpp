struct Pair { int a,b; };
struct Obj { char pad[0x60]; Pair value; int n; };
extern Obj *D_0064B47C;
extern "C" int func_00536B40() throw();
extern "C" void func_005325C8(int, char *, int, int, int) throw();
extern "C" void func_00536B70(int a, Pair value, int n, int x, int y) {
    D_0064B47C->value = value;
    D_0064B47C->n = n;
    func_005325C8(func_00536B40(), 0, 0x100, x, y);
}
