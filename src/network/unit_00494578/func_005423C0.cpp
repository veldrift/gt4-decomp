struct A {
    char pad[0x8414];
    char buf[0x800];
    int len;
};
struct B {
    int m0;
    char *m4;
    int m8;
};
extern "C" int func_00541208(A *, char **, int) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned int);

extern "C" int func_005423C0(A *a, B *b) {
    int r = func_00541208(a, &b->m4, a->len + 1);
    if (r != 0) {
        return r;
    }
    b->m8 = a->len;
    b->m0 = 2;
    func_005A4724(b->m4, a->buf, a->len);
    a->buf[0] = 0;
    a->len = 0;
    return 0;
}
