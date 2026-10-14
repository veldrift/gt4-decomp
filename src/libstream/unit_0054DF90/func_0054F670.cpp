/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Base { char pad[0x38]; virtual ~Base(); };
struct Elem : Base { char tail[0x84]; virtual ~Elem(); };
struct Holder { Elem array[2]; ~Holder() {} };
extern Holder D_0086F640;
extern "C" void func_0054F218(Elem *) throw();
extern "C" void func_0054F670(int init, int prio) {
    if (prio == 0xffff) {
        if (init == 1) {
            func_0054F218(&D_0086F640.array[0]);
            func_0054F218(&D_0086F640.array[1]);
        }
        if (init == 0) {
            D_0086F640.~Holder();
        }
    }
}
