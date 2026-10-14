/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0057ADE0(void *, unsigned long, int);
extern "C" void func_00346080(void *w, int n) {
    int sign = 0;
    if (n < 0) { n = -n; sign = 1; }
    int one = 1;
    int bits = 1;
    while (n >= (one << bits)) {
        n -= one << bits;
        bits += 2;
    }
    func_0057ADE0(w, bits >> 1, 3);
    func_0057ADE0(w, sign, 1);
    func_0057ADE0(w, n, bits);
}
