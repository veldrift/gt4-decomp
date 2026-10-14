typedef int s32;
struct E16 { char pad[16]; };
struct Hdr {
    s32 f0;
    Hdr *self;
    s32 f8;
    s32 fC;
    E16 *a;
    unsigned short n0;
    unsigned short n1;
    s32 f18;
    E16 *b;
    bool fixed() { return this == self; }
};
extern "C" void func_0042B098(void *t, int d);
extern "C" void func_00427680(void *p, int d);
extern "C" void func_00427698(Hdr *h) {
    if (!h->fixed()) {
        int i = 0;
        int d = (char *)h - (char *)h->self;
        E16 *a = h->a;
        E16 *b = h->b;
        h->a = a ? (E16 *)((char *)a + d) : 0;
        h->b = b ? (E16 *)((char *)b + d) : 0;
        h->self = h;
        if (h->n0) {
            do {
                func_0042B098(&h->a[i++], d);
            } while (i < h->n0);
        }
        i = 0;
        if (h->n1) {
            do {
                func_00427680(&h->b[i++], d);
            } while (i < h->n1);
        }
    }
}
