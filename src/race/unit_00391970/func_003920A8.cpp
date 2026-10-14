/* compiler: ee-gcc2.96-nogcse */
extern "C" void EngineSound__structor_1(void *, int) throw();
extern "C" void func_005C1628(void *) throw();
struct VEntry { short delta, index; void (*fn)(void *, int); };
extern "C" void func_003920A8(char *self, int flags) {
    EngineSound__structor_1(self + 0x2d0, 2);
    char *a = self + 0x14;
    if (a != (char *)-0x1c) {
        char *p = self + 0x278;
        if (self + 0x30 != p) {
            char *end = self + 0x30;
            do {
                p -= 0x124;
                VEntry *e = (VEntry *)(*(char **)(p + 0x1c) + 8);
                e->fn(p + e->delta, 2);
            } while(end != p);
        }
    }
    if (flags & 1) return func_005C1628(self);
}
