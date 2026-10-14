/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
extern "C" void func_003B76F0(void *, int, int, int);
extern "C" void RaceDisplay__virtual_35(char *self, char *other, int a, int b) {
    if (a == b) {
        if (*(unsigned char *)(self + 0x34) == 0) {
            char *p = other + 0xF4;
            *(unsigned int *)(self + 0x34) = (*(unsigned int *)(self + 0x34) & ~0xFFu) | 1;
            func_003B76F0(p, 0x18, 0xB, 0);
            func_003B76F0(p, 8, 0, 0);
            if (*(unsigned char *)(self + 0x3B) != 0) {
                VEntry *e = (VEntry *)(*(char **)self + 0x148);
                e->fn(self + e->delta);
            }
        }
    }
}
