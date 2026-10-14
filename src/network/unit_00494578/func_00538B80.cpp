extern "C" void *func_00575E30(void *, int);
extern "C" void *(*D_0064B718)(void *, int);
extern "C" int func_00538B80(void **out, unsigned long size) {
    void *(*reallocFn)(void *, int) = D_0064B718;
    if (reallocFn == 0) {
        void *p = func_00575E30(*out, size);
        *out = p;
        if (p == 0) return 100;
    } else {
        void *p = reallocFn(*out, size);
        *out = p;
        if (p == 0) return 100;
    }
    return 0;
}
