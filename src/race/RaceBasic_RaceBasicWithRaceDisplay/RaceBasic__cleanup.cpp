/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short d; short i; void (*fn)(void *); };
extern "C" void RacePS2Base__cleanup(char *);
extern "C" void func_003DCD88(void *);
extern "C" void RaceBasic__cleanup(char *self) {
    char *o = *(char **)(self + 0xE420);
    if (o) {
        VE *e = (VE *)(*(char **)o + 8);
        e->fn(o + e->d);
    }
    o = *(char **)(self + 0xE41C);
    if (o) {
        VE *e = (VE *)(*(char **)(o + 0xC) + 0x18);
        e->fn(o + e->d);
    }
    o = *(char **)(self + 0xE400);
    if (o) {
        VE *e = (VE *)(*(char **)(o + 8) + 0x18);
        e->fn(o + e->d);
    }
    o = *(char **)(self + 0xE404);
    if (o) {
        VE *e = (VE *)(*(char **)(o + 8) + 0x18);
        e->fn(o + e->d);
    }
    void *p = *(void **)(self + 0xE40C);
    if (p) func_003DCD88(p);
    RacePS2Base__cleanup(self);
}
