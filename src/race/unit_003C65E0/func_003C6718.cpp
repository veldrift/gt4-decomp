struct S { char pad0[6]; unsigned short n6, n8; char pad1[6]; char *p10, *p14; };
static inline void adj(char **p, int delta) { *p += delta; }
extern "C" void func_003C6718(S *s, int delta) {
    if (s->p10) adj(&s->p10, delta);
    if (s->p14) adj(&s->p14, delta);
    int n = s->n6;
    if (n != 0) {
        do { n--; } while (n != 0);
    }
    unsigned short temp = s->n8;
    if (temp != 0) {
        int m = temp;
        do { m--; } while (m != 0);
    }
}
