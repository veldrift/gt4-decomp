struct S { char data[100]; };
extern int *D_0064A274;
extern unsigned int D_0064A27C;
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" void func_00509E18(S s, int *out) {
    for (unsigned int i = 0; i < D_0064A27C; i++) {
        if (func_0057F238(s.data, (char *)D_0064A274[i] + 8) == 0) {
            *out = D_0064A274[i];
        }
    }
}
