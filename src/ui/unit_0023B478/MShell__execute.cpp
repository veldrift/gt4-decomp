/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
extern "C" void func_0023B1D8(void *, int) throw();
extern "C" void func_0023B230(void *) throw();
extern "C" void func_0023C0D0(void *, u8 *, void *);
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" u8 *func_00314920(void *);

extern "C" void MShell__execute(void *arg0, void *arg1, int arg2, char *arg3) {
    void *sp[4];
    void *sp10[4];
    void *sp20[4];
    if (arg2 > 0) {
        func_0023B230(sp);
        void **p = sp10;
        func_00312370(p, arg3);
        void **q;
        if (arg2 >= 2) {
            q = sp20;
            func_00255110(q, arg3 + 4);
            void *h = sp[0];
            func_0023C0D0(h, func_00314920(p[0]), q[0]);
            func_002550B8(q, 2);
        } else {
            void *h = sp[0];
            func_0023C0D0(h, func_00314920(p[0]), 0);
        }
        func_00312318(p, 2);
        func_0023B1D8(sp, 2);
    }
}
