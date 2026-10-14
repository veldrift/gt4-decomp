struct S { char data[100]; };
extern int *D_0064A220;
extern unsigned int D_0064A228;
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" void func_00509F80(S s, int *out) {
    for (unsigned int i = 0; i < D_0064A228; i++) {
        if (func_0057F238(s.data, (char *)D_0064A220[i]) == 0) {
            *out = D_0064A220[i];
        }
    }
}
