extern "C" void func_00543BE0(void) throw();
extern "C" int func_00539528(void) throw();

extern "C" void func_00543C20(int *p) {
    unsigned int i = 0;
    func_00543BE0();
    do {
        int v = func_00539528();
        p[i] = v;
        i = (i + 1) & 0xFF;
    } while (i < 0x10);
}
