/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    char pad[0x954];
    int m954;
};
extern "C" void func_00503C48(O *) throw();
extern "C" void func_00576788(O *) throw();
extern "C" void func_005767C0(O *) throw();

struct Guard {
    O *o;
    Guard(O *p) : o(p) { func_00576788(p); }
    ~Guard() { func_005767C0(o); }
};

extern "C" void func_00503AE0(O *o) {
    Guard g(o);
    int v = o->m954 - 1;
    o->m954 = v;
    if (v == 0) {
        func_00503C48(o);
    }
}
