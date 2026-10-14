/* compiler: ee-gcc2.96-no-strict-aliasing */
struct List { int count; int entries[1]; };
extern "C" void func_00397A98(List *p, int delta) {
    int i=0;
    if (i < p->count) {
        int *q = p->entries;
        do {
            if (*q++ != 0)
                p->entries[i] += delta;
            i++;
        } while(i < p->count);
    }
}
