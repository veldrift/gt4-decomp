extern "C" int func_00528BA8(void *, int) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern int D_00867FF8[];
extern "C" int func_0052D158(int a, int *out) {
    int r = 2;
    if (a == 0) return r;
    func_005A48D8(D_00867FF8, 0, 0x108);
    r = func_00528BA8(D_00867FF8, a);
    if (r != 0) return r;
    *out = D_00867FF8[0];
    return r;
}
