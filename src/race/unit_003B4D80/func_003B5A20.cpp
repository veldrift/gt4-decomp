/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { short delta; short pad; int (*fn)(char *, char *, int, int, int); };
extern "C" int func_004462E0(char *);
extern "C" int func_00446320(char *);
extern "C" int SPEC_DATABASE__RaceSpec__getCourseType(void *);
extern "C" char *func_005A609C(char *, const char *);
extern "C" char *func_003B5A20(char *self, int flag, char *arg, char *out) {
    char *name = flag != 0 ? self + 0x358C : self + 0x359C;
    if (*name != 0) {
        func_005A609C(out, name);
    } else {
        int value;
        if (flag != 0) value = func_004462E0(self + 0x20);
        else value = func_00446320(self + 0x20);
        int course = SPEC_DATABASE__RaceSpec__getCourseType(*(void **)(arg + 0x70));
        char *a = *(char **)(self + 0x2880);
        Ent *e = (Ent *)(*(char **)(a + 8) + 0x88);
        e->fn(a + e->delta, out, value, flag, course == 1);
    }
    return out;
}
