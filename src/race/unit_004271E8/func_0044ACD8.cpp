struct C { int n; unsigned char a[16]; };
extern "C" void func_0044B4A0(unsigned char *d, int n, void *p, void *q, int k);
extern "C" void *func_0044B598(void *d, void *s);
extern "C" void func_0044B900(unsigned char *o, unsigned char *i, int n, void *key);

extern "C" void func_0044ACD8(C *c, unsigned char *k) {
    unsigned char buf[8];
    unsigned char t1[0xE0];
    unsigned char t2[0xE0];
    func_0044B4A0(t1, c->n, c->a + 8, k, 10);
    func_0044B900(buf, c->a, c->n, t1);
    func_0044B4A0(t2, c->n, k, c->a, 10);
    func_0044B598(t1, t2);
    for (unsigned i = 0; i < 8; i++) {
        c->a[i] ^= buf[i];
        buf[i] = ~c->a[i + 8];
    }
    func_0044B900(buf, buf, c->n, t1);
    for (unsigned i = 0; i < 8; i++)
        c->a[i + 8] ^= buf[i];
}
