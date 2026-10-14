/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0049FAC8(unsigned long, int, int, int, int, int, int) throw();
extern "C" int func_0049FDA0(int n, int b, int c, int d, int e) {
    int tmp = e;
    e = c;
    c = tmp;
    if (n >= 3) return func_0049FAC8(0x70002000, b, c, d, e, n, 1);
}
