/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x30]; unsigned long bits; };
struct Handle { Obj *p; int pad[3]; };
extern "C" void func_002E09C8(void *, int) throw();
extern "C" void *func_002E0A20(void *, void *) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" void func_002FE278(void *, int);
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
extern "C" void MStorageEntry__get_size(int *dst, void *src, int n, void *value) {
    Handle a;
    int b4[4];
    int shift = 0;
    if (n > 0) {
        func_002FC8C8(&a, value);
        shift = func_002FE250(a.p);
        func_002FC870(&a, 2);
    }
    func_002E0A20(&a, src);
    int *b = b4;
    func_002FE278(b, (int)(a.p->bits >> shift));
    if (dst != b) {
        int v = *b;
        if (v) func_003285A8(v);
        int old = *dst;
        if (old) func_003285F8(old);
        *dst = v;
    }
    func_002FC870(b, 2);
    func_002E09C8(&a, 2);
}
