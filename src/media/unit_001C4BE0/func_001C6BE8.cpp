/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { char p[0x2B4]; unsigned v; void clear() { v &= ~0xFF; } };
struct S {
    int n;
    int f4;
    int f8;
    int list[1];
    char p0[0x64C - 0x10];
    E e[2];
    int a, b, c, d, last;
};
struct T {
    char p[0xBBC];
    int a, b, c, d, e;
};
extern "C" int func_001C6918(void *) throw();
extern "C" int func_001C6AA0(void *) throw();
extern "C" float func_00579398(float);

extern "C" void func_001C6BE8(S *self, int shuffle) {
    int n = func_001C6918(self);
    if (n < 0) n = 0;
    if (n == 0) {
        *(int *)((char *)self + 0x1DD8) = 1;
        n = func_001C6AA0(self);
    }
    if (n >= 0x190) n = 0x190;
    self->f4 = -1;
    self->f8 = 1;
    self->n = n;
    int i;
    for (i = 0; i < n; i++)
        self->list[i] = i;
    if (shuffle != 0 && n > 0) {
        float fn = n;
        int *p = self->list;
        int *base = p;
        i = n;
        do {
            int j = (int)(fn * func_00579398(1.0f)) % n;
            int t = *p;
            *p = self->list[j];
            self->list[j] = t;
            p++;
        } while (--i != 0);
    }
    S *t = self;
    E *e = (E *)((char *)self + 0x64C);
    t->a = 0;
    t->b = 0;
    t->c = 0;
    t->d = -1;
    t->last = -1;
    for (i = 0; i < 2; i++) {
        self->e[i].clear();
    }
}
