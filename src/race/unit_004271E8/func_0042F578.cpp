/* compiler: ee-gcc2.96-no-strict-aliasing */
struct B4 { char c[4]; };
struct B16 { char c[16]; };
struct VEnt { short adj; short pad; int (*fn)(void *, void *); };
struct Sub { int p0; int start; int count; int pC; B16 e[0xB6A]; };
struct Obj { VEnt *vt; int p4; Sub s; };
static inline int write4(char *dst, void *src) { *(B4 *)dst = *(B4 *)src; return 4; }
static inline int write16(char *dst, B16 *src) { * (B16 *)dst = *src; return 16; }
static inline int capacity(Sub *s) { return 0xB6A; }
static inline int stride(Sub *s) { return 16; }
static inline unsigned index(Sub *s, int i) {
    unsigned k = s->start + i;
    if (k >= (unsigned)capacity(s)) k -= 0xB6A;
    return k;
}
static inline B16 *get(Sub *s, int i) { return &s->e[index(s,i)]; }
extern "C" int func_0042F578(Obj *o, char *out) {
    Sub *s = &o->s;
    int n = s->count;
    char *p = out;
    p += write4(p, &n);
    for (int i = 0; i < capacity(s); i++) {
        if (i < n) write16(p, &s->e[index(&o->s,i)]);
        p += stride(s);
    }
    write4(p, (char *)o + 0xB6C0);
    VEnt *v = (VEnt *)((char *)o->vt + 0x20);
    return v->fn((char *)o + v->adj, out);
}
