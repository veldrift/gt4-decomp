/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00846640[];
extern "C" unsigned long func_00485BA0(const char *);
extern "C" int func_004859A0(void *, unsigned long);
extern "C" long func_0060A410(void *, int);
struct Instrument {
    void play(unsigned, float, int) throw() __asm__("func_0045FFF8");
};
extern "C" void func_00460220(const char *name, unsigned select, float volume, int mode) {
    int i = func_004859A0(D_00846640, func_00485BA0(name));
    if (i >= 0) {
        Instrument *p = (Instrument *)(int)func_0060A410(D_00846640, i);
        p->play(select, volume, mode);
    }
}
