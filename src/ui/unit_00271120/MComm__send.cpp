/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00270EC8(void *, int) throw();
extern "C" void func_00270F20(void *, void *) throw();
extern "C" int func_00271D10(int, char *, int);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, int);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" char **func_00314920(int);
extern "C" char *func_00314AD8(int);
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
extern "C" void MComm__send(int *dst, void *src, int n, void *arg) {
    int buf0[4];
    int buf1[4];
    if (n > 0) {
        func_00312370(buf0, arg);
        int *p = buf1;
        func_00270F20(p, src);
        int obj = *p;
        char *data = func_00314AD8(buf0[0]);
        int result = func_00271D10(obj, data, *(int *)(*func_00314920(buf0[0]) - 16));
        func_00270EC8(p, 2);
        func_002FE278(p, result != 0);
        if (dst != p) {
            int nv = *p;
            if (nv) func_003285A8(nv);
            int old = *dst;
            if (old) func_003285F8(old);
            *dst = nv;
        }
        func_002FC870(p, 2);
        func_00312318(buf0, 2);
    }
}
