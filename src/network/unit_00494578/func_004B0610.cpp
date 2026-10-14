/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    char pad[0x3290];
    int m3290;
};
extern "C" void func_004B0398(O *) throw();
extern "C" void func_00574EB0(void *);
extern "C" void func_00574EE8(void *);

extern "C" void func_004B0610(O *o) {
    for (;;) {
        func_00574EB0((char *)o + 0x3170);
        if (o->m3290 == 0) {
            break;
        }
        func_004B0398(o);
        func_00574EE8((char *)o + 0x31A0);
    }
}
