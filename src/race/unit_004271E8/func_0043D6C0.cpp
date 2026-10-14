/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef signed char s8;
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" s8 func_0043C148(char *, int) throw();
extern "C" s8 func_0043C5E0(char *, int) throw();
extern "C" s8 func_0043C8C8(char *, int) throw();
extern "C" s8 func_0043CBD8(char *, int) throw();
extern "C" int func_0043D6C0(char *self, const char *name) {
    if (func_0057F238(name, "VIBRATION") == 0) {
        return func_0043C148(self + 0x18, 0) != 0;
    }
    if (func_0057F238(name, "WHEEL FEEDBACK") == 0) {
        int r = 0;
        if (func_0043C5E0(self + 0x48, 0) || func_0043C8C8(self + 0x64, 0) || func_0043CBD8(self + 0x8C, 0))
            r = 1;
        return r;
    }
    return 0;
}
