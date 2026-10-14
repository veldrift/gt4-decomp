/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    char pad[0x14];
    int m14;
};
extern char D_00634B90[];
extern char D_00897FC0[];
extern "C" void func_00576788(void *);
extern "C" void func_004AE0B8(O *);
extern "C" void func_005767C0(void *);

extern "C" void func_004B0398(O *o) {
    func_00576788(D_00634B90);
    o->m14 = (int)D_00897FC0;
    func_004AE0B8(o);
    func_005767C0(D_00634B90);
}
