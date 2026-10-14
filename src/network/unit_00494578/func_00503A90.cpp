/* compiler: ee-gcc2.96-no-strict-aliasing */
struct A { char pad[0x954]; int count; };
extern "C" void func_00576788(A*);
extern "C" void func_005767C0(A*);
extern "C" void func_00503B30(A*);
struct Guard {
    A *p;
    Guard(A *a):p(a) { func_00576788(a); }
    ~Guard() { func_005767C0(p); }
};
extern "C" void func_00503A90(A *a) {
    Guard guard(a);
    if(++a->count == 1) func_00503B30(a);
}
