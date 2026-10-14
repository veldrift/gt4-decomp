extern "C" void *malloc(int size) throw();
extern "C" void *(*D_0064B714)(int);
extern "C" int func_00538B08(void **out, unsigned long size) {
    void *(*alloc)(int) = D_0064B714;
    if (alloc == 0) {
        void *p = malloc(size);
        *out = p;
        if (p == 0) return 100;
    } else {
        void *p = alloc(size);
        *out = p;
        if (p == 0) return 100;
    }
    return 0;
}
