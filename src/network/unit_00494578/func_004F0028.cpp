/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Heap {
    int m0;
};
extern Heap D_006454F0;
extern "C" void func_00503100(void);
extern "C" unsigned int func_005724B0(Heap *, unsigned int, unsigned int);
extern "C" void *func_00578CF0(int, int);
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" void func_004F0028(void) {
    if (D_006454F0.m0 == 0) {
        void *p = func_00578CF0(0x80, 0xC0000);
        func_005A48D8(p, 0, 0xC0000);
        func_005724B0(&D_006454F0, (unsigned int)p, 0xC0000);
    }
    func_00503100();
}
