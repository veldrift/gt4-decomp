/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0056EA50(int, int, void *, int, int);
extern "C" int func_0056FF10(int arg0, void *arg1, int *arg2, int *arg3) {
    int r;
    if (func_0056EA50(arg0, 0x23, arg1, 0, 0xC) < 0) return -0x21E;
    if (arg2) *arg2 = *(int *)((char *)arg1 + 4);
    if (arg3) *arg3 = *(int *)((char *)arg1 + 8);
    r = *(int *)arg1;
    return r;
}
