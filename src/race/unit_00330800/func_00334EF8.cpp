/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int dummy; unsigned char *begin; unsigned char *end; unsigned char *cap; };
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" void *func_005A47D4(void *, const void *, unsigned int) throw();
extern "C" void func_005CD6E8(Vec *, unsigned char *, unsigned int, const unsigned char *);
extern "C" void func_00334EF8(char *o, const void *src, unsigned int n) {
    unsigned char zero = 0;
    Vec *v = (Vec *)(o + 0xF8);
    unsigned char *end = v->end;
    unsigned int size = end - v->begin;
    if (n < size) {
        unsigned char *p = v->begin + n;
        func_005A47D4(p, end, 0);
        v->end -= end - p;
    } else {
        func_005CD6E8(v, end, n - size, &zero);
    }
    func_005A4724(v->begin, src, n);
}
