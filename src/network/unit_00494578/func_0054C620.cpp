/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { int f0; char pad[0x60]; int f64; };
extern int D_0064C404;
extern Blk *D_0064C3E4;
extern volatile int D_0064C3EC, D_0064C3F0;
extern int D_0064C3FC;
extern "C" void func_00578908(int);
extern "C" void func_00574EE8(void *);
extern "C" void func_00574DA8(void *, int);
extern "C" void func_005C1628(void *) throw();
extern "C" void func_0054C620(void) {
    if (D_0064C404 != 0) {
        Blk *b = D_0064C3E4;
        if (b != 0) {
            D_0064C3EC = 0;
            (void)D_0064C3EC;
            D_0064C3F0 = 1;
            (void)D_0064C3F0;
            func_00578908(D_0064C3FC);
            b->f64 = 1;
            func_00574EE8((char *)b + 4);
            func_00578908(b->f0);
            Blk *d = D_0064C3E4;
            if (d != 0) {
                func_00574DA8((char *)d + 0x34, 2);
                func_00574DA8((char *)d + 4, 2);
                func_005C1628(d);
            }
            D_0064C3E4 = 0;
        }
        D_0064C404 = 0;
    }
}
