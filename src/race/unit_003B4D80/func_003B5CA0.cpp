/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { short delta; short pad; void (*fn)(char *, char *, int); };
extern "C" int func_003B5AF8(char *, char *) throw();
extern "C" int func_0057F238(const char *, const char *) throw();
extern char D_006A2578[];
extern "C" void func_003B5CA0(char *self) {
    char buf[0x10];
    func_003B5AF8(self, buf);
    if (func_0057F238(buf, D_006A2578) != 0) {
        char *a = *(char **)(self + 0x2880);
        Ent *e = (Ent *)(*(char **)(a + 8) + 0x98);
        e->fn(a + e->delta, buf, 0);
    }
}
