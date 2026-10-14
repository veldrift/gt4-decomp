/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Names { const char *n[6]; };
extern "C" const Names D_006C8610;
extern "C" char *func_005A6AB0(char *dst, const char *src) throw();
extern "C" void func_0055F490(unsigned int i, char *dst, int n);
extern "C" void func_00551D50(unsigned int i, char *dst, int n)
{
    Names t = D_006C8610;
    if (i < 6)
        func_005A6AB0(dst, t.n[i]);
    else
        func_0055F490(i, dst, n);
}
