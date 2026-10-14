/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int dummy; unsigned char *begin; unsigned char *end; unsigned char *cap; };
extern "C" void func_00334FA8(void *);
extern "C" unsigned int func_00334FC8(void *, unsigned char *, unsigned int);
extern "C" void *func_005A47D4(void *, const void *, unsigned int) throw();
extern "C" void func_005CD6E8(Vec *, unsigned char *, unsigned int, const unsigned char *);
extern "C" void func_00334E38(char *o) {
    unsigned char zero;
    Vec *v = (Vec *)(o + 0xF8);
    func_00334FA8(o);
    unsigned int n = func_00334FC8(o, 0, 0);
    unsigned char *end = v->end;
    unsigned int size = end - v->begin;
    zero = 0;
    if (n < size) {
        unsigned char *p = v->begin + n;
        func_005A47D4(p, end, 0);
        v->end -= end - p;
    } else {
        func_005CD6E8(v, end, n - size, &zero);
    }
    func_00334FC8(o, v->begin, n);
}
