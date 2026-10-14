struct A { char pad[0x104]; int id; };
struct B { char pad[8]; int id; };
extern A *D_00854150;
extern "C" B *func_00515DD8(unsigned int) throw();
extern "C" void func_00516130(unsigned int) throw();
extern "C" void func_00516260(unsigned int) throw();
extern "C" int func_005162D0(unsigned int arg0) {
    A *a = D_00854150;
    if (!a) return 8;
    B *b = func_00515DD8(arg0);
    if (!b) return 8;
    if (b->id == a->id) {
        func_00516260(arg0);
        return 0;
    } else {
        func_00516130(arg0);
        return 0;
    }
}
