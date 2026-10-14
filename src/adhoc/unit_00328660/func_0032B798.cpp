/* compiler: ee-gcc2.96-no-strict-aliasing */
struct String { char *data; };
extern char D_0069EEA0[];
extern "C" double func_0057FB50(float);
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(void *, unsigned int, unsigned int, const char *, unsigned int);
static inline void format(char *buf, const char *fmt, double value) {
    func_0057DA20(buf, fmt, value);
}
extern "C" String *func_0032B798(String *self, float value) {
    char buf[32];
    format(buf, D_0069EEA0, func_0057FB50(value));
    unsigned int n = func_0057F260(buf);
    func_005C2630(self, ((unsigned int *)self->data)[-4], 0, buf, n);
    return self;
}
