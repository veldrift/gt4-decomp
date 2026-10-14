extern "C" void *exception__structor_0(unsigned int flags);
extern "C" void func_005012E8(void *obj);

extern int D_00649544;

extern "C" void func_00503100(void) {
    if (D_00649544 == 0) {
        void *obj = exception__structor_0(0x8858);
        func_005012E8(obj);
        D_00649544 = (int)obj;
    }
}
