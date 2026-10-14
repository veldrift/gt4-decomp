/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; };
struct Rep { int len, cap, ref, sel; };
extern char D_00697A98[], D_00697AA0[];
extern unsigned int PDISTD__LOCALE;
extern "C" void *func_0048F270(void *);
extern "C" const char *func_0048EDA0(unsigned int);
extern "C" int func_0057DA20(char *, const char *, ...);
extern "C" void func_0048F320(void *, const char *);
extern "C" void func_00213C88(void *, void *, void *) throw();
extern "C" void func_0048F2B0(void *, int);
static inline const char *c_str(Str *s) {
    int len = ((Rep *)s->p)[-1].len;
    if (len == 0) return D_00697A98;
    s->p[len] = 0;
    return s->p;
}
extern "C" void mUpdateContextPS2__virtual_53(void *self, Str *a, Str *b) {
    int obj[4];
    char buf[0x80];
    func_0048F270(obj);
    const char *middle = func_0048EDA0(PDISTD__LOCALE);
    func_0057DA20(buf, D_00697AA0, c_str(a), middle, c_str(b));
    func_0048F320(obj, buf);
    func_00213C88(self, b, obj);
    func_0048F2B0(obj, 2);
}
