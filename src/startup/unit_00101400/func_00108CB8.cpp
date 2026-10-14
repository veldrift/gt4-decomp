extern char D_0068BB20[];
extern char D_0068CC60[];
extern char D_0068CC68[];
extern char D_0068CC78[];
extern char D_0068CC80[];
extern char D_0068CC90[];
extern char D_0068CC98[];
extern "C" void func_0048F8B0(void);
extern "C" void func_0048F930(void *);
extern "C" int func_0057F238(const char *, const char *);

extern "C" void func_00108CB8(void) {
    func_0048F8B0();
    if (func_0057F238(D_0068BB20, D_0068CC60) == 0) {
        func_0048F930(D_0068CC68);
    } else if (func_0057F238(D_0068BB20, D_0068CC78) == 0) {
        func_0048F930(D_0068CC80);
    } else if (func_0057F238(D_0068BB20, D_0068CC90) == 0) {
        func_0048F930(D_0068CC98);
    } else {
        func_0048F930(D_0068CC68);
    }
}
