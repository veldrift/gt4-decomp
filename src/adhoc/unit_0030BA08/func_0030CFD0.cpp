/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0030C5D8(char *dst, const char *src) throw();
extern "C" void func_0030CE78(char *dst, const char *dir, const char *file) throw();
extern "C" int func_0057F238(const char *a, const char *b) throw();
extern "C" void func_0057D9C0(const char *fmt, ...);

struct Test { const char *dir; const char *file; const char *expect; };

extern "C" void func_0030CFD0(void) {
    Test tbl[2] = {
        { "/usr/people/fuga", "../hoge", "/usr/people/hoge" },
        { 0, 0, 0 }
    };
    char buf1[0x400];
    char buf2[0x400];
    int i;
    for (i = 0; tbl[i].dir != 0; i++) {
        func_0030CE78(buf1, tbl[i].dir, tbl[i].file);
        func_0030C5D8(buf2, buf1);
        if (func_0057F238(buf2, tbl[i].expect) != 0) {
            func_0057D9C0("[%s][%s]->[%s] NG [%s]\n", tbl[i].dir, tbl[i].file, buf2, tbl[i].expect);
        } else {
            func_0057D9C0("[%s][%s]->[%s] OK [%s]\n", tbl[i].dir, tbl[i].file, buf2, tbl[i].expect);
        }
    }
}
