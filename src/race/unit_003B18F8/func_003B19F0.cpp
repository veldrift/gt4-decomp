/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_003B0820(void *) throw();
extern "C" int func_003B2568(void *, int, int, int, float, void *, int, int);
extern "C" int func_003B19F0(char *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, float f) {
    char *p = arg0 + 0x7E0;
    func_003B0820(p);
    int r = func_003B2568(arg0, arg1, arg2, arg3, f, p, arg4, arg5);
    if (r != 0) {
        *(int *)(arg0 + 0x7C0) += 1;
    }
    return r;
}
