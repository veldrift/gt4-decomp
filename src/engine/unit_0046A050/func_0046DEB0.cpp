/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int f0; int f4; char pad[0xA80]; char sub[1]; };
extern "C" int func_0046D770(void *);
extern "C" int func_0046DE10(void *) throw();
extern "C" void func_0046E920(void *, int);
extern "C" int func_0046EA08(void *);
extern "C" void func_0046EB40(void *, void *, int);
extern "C" int func_0057F238(const char *, const char *) throw();
extern char D_006ABAA8[];
extern "C" int func_0046DEB0(O *o) {
    void *s = o->sub;
    int n = func_0046EA08(s);
    int d = n - 2;
    if (func_0046D770(o)) {
        if (d < 0) {
            o->f0 = 1;
            o->f4 = 1;
            return 0;
        }
        if (d < 5) func_0046E920(s, d);
        else {
            char buf[8];
            func_0046EB40(s, buf, 5);
            buf[4] = 0;
            if (func_0057F238(D_006ABAA8, buf) == 0) {
                int r = func_0046DE10(o);
                if (r == 0) return r;
            } else {
                func_0046E920(s, n - 7);
            }
        }
        return func_0046D770(o);
    }
    return 0;
}
