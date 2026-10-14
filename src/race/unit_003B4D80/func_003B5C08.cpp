/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { short delta; short pad; void (*fn)(char *, char *, char *, int); };
extern "C" int func_003B5A20(char *, int, int, char *) throw();
extern "C" void func_003B5C08(char *self, int arg) {
    char buf[2][0x10];
    char *p = buf[0];
    for (int i = 0; i < 2; i++, p += 0x10) {
        func_003B5A20(self, i == 0, arg, p);
    }
    char *a = *(char **)(self + 0x2880);
    Ent *e = (Ent *)(*(char **)(a + 8) + 0x90);
    e->fn(a + e->delta, buf[0], buf[1], 0);
}
