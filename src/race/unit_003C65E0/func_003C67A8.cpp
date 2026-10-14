/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { unsigned short a, n; int addr; };
extern "C" void func_003C6A10(int *);
extern "C" void func_003C67A8(S *s, int delta) {
    int addr = s->addr;
    int *h = &s->addr;
    if (addr != 0) {
        addr += delta;
        *h = addr;
        int n = s->n;
        int i = 0;
        if (n != 0) {
            do {
                int off = i * 4;
                i++;
                int *e = (int *)((char *)s->addr + off);
                *e += delta;
            } while (i < (n = s->n));
        }
    }
    for (int i = 0; i < s->n; i++) {
        func_003C6A10((int *)((int *)s->addr)[i]);
    }
}
