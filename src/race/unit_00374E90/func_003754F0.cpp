struct Obj;
struct Entry { short delta, index; int (*fn)(void *, int); };
struct Obj { char *vtbl; };
extern "C" void func_003777C8(Obj *, int, int, int, int, int *);
extern "C" void func_00377898(Obj *, int, int, int, int, int *);
extern "C" void func_00378F28(int, int, char *, char *, char *);
extern "C" void func_0037D260(int, int, int);
extern "C" void func_003FC4F0(char *, int);
extern "C" int func_003FD5A8(int, char *, int);
extern "C" int func_003FD620(int, int, char *, int, int *);
static inline int VCALL(Obj *self, int idx) {
    Entry *e = (Entry *)(self->vtbl + 0xD8);
    return e->fn((char *)self + e->delta, idx);
}
extern "C" void func_003754F0(Obj *self, int a1, int a2, int idx, int flags, int *out) {
    int tmp[4];
    int r = 0;
    char *base = (char *)self + idx * 0x19C;
    char *s1 = base + 0x10;
    char *fp = base + 0xE0;
    int v = *(int *)(s1 + 0x18C);
    if (v >= 0) {
        r = 1;
        func_003FC4F0(s1, v);
    }
    signed char c = fp[0x1F];
    if (c != 0) {
        if (func_003FD5A8(a1, s1, c > 0)) r = 1;
    }
    if (r) {
        flags |= 4;
        out[1] = 1;
    }
    if (func_003FD620(a1, a2, s1, 0, tmp) == 1)
        func_00377898(self, a1, a2, idx, flags, out);
    else
        func_003777C8(self, a1, a2, idx, flags, out);
    int s0 = *(int *)(s1 + 0x16C);
    int s3 = *(int *)(s1 + 0x194);
    int s4 = *(int *)(s1 + 0x198);
    int p = VCALL(self, idx);
    if (p == s0 && s3 >= 0)
        func_0037D260(p, s3, s4);
    func_00378F28(VCALL(self, idx), a1, fp, s1, (char *)self + 0x9C0);
    int s0b = *(int *)(s1 + 0x16C);
    int p2 = VCALL(self, idx);
    if (p2 == s0b)
        *(int *)((char *)self + idx * 0x19C + 0x198) = *(int *)((char *)p2 + 0x2C0);
}
