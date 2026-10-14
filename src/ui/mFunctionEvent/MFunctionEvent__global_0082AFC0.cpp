/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0020D1B8(void *, int) throw();
extern "C" void func_0020D210(void *, void *) throw();
extern "C" void func_0020D8D8(void *, int *);
extern "C" void func_0020D930(void *, unsigned int);
extern "C" void func_0020DA00(void *, int, int *);
extern "C" void func_002F9B38(void *, int);
extern "C" void func_002F9B90(void *, void *);
extern "C" void MFunctionEvent__global_0082AFC0(void *unused, void *src, int n, int *p) {
    void *handle[4];
    int value[4];
    if (n > 0) {
        int i = 1;
        func_0020D210(handle, src);
        func_002F9B90(value, p);
        func_0020D8D8(handle[0], value);
        func_0020D930(handle[0], n - 1);
        if (i < n) {
            ++p;
            do {
                func_0020DA00(handle[0], i - 1, p);
                ++i;
                ++p;
            } while (i < n);
        }
        func_002F9B38(value, 2);
        func_0020D1B8(handle, 2);
    }
}
