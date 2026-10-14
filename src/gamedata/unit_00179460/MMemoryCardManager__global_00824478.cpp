/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Hdr;

extern char D_00690F78[];
extern char D_00691410[];
extern "C" void func_00179280(void *, int);
extern "C" void func_001792D8(void *);
extern "C" s32 func_001794A0(void *, const char *);
extern "C" void func_0017C348(void *, s32, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(void *);
extern "C" s32 func_002FE278(void *, int);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" char **func_00314920(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

extern "C" void MMemoryCardManager__global_00824478(int unused, void *arg1, int count, void *obj) {
    Hdr *a[4];
    void *h[4];
    void *r[4];
    void *t[4];
    func_001792D8(a);
    if (count > 0) {
        void **ph = h;
        func_00312370(ph, obj);
        void **pr = r;
        func_002FE278(pr, 0);
        if (count >= 2) {
            void **pt = t;
            func_002FC8C8(pt, (char *)obj + 4);
            if (pr != pt) {
                void *nv = pt[0];
                if (nv != 0)
                    func_003285A8(nv);
                if (pr[0] != 0)
                    func_003285F8(pr[0]);
                pr[0] = nv;
            }
            func_002FC870(pt, 2);
        }
        Hdr *a0 = a[0];
        char **sp = func_00314920(ph[0]);
        const char *s;
        if (((s32 *)*sp)[-4] == 0) {
            s = D_00690F78;
        } else {
            (*sp)[((s32 *)*sp)[-4]] = 0;
            s = *sp;
        }
        s32 w = func_001794A0(D_00691410, s);
        func_0017C348(a0, w, func_002FE250(pr[0]));
        func_002FC870(pr, 2);
        func_00312318(ph, 2);
    }
    func_00179280(a, 2);
}
