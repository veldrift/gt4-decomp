extern "C" {
void func_0046F4A8(void *);
void func_0046E7C0(void *);
void func_00471FD8(void *);
void func_00472028(void *);
void func_004720B8(void *);
int func_0046CE70(void *);
extern char D_00688900[];
}
extern "C" int func_0046CC38(char *o)
{
    *(char **)(o + 0x11D0) = D_00688900;
    char *base = o + 0xDE0;
    char *p = base;
    func_0046F4A8(o + 8);
    func_0046E7C0(o + 0xA88);
    for (int i = 2; i != -1; i--) {
        func_00471FD8(p);
        p += 0x108;
    }
    char *q = base + 0x318;
    for (int i = 1; i != -1; i--) {
        char *r = q;
        for (int j = 2; j != -1; j--) {
            func_00472028(r);
            r += 0x24;
        }
        q += 0x6C;
    }
    int i = 0;
    char *s = o;
    for (; i < 2; i++) {
        char *r = s + 0x10F8;
        for (int j = 2; j >= 0; j--) {
            func_004720B8(r);
            r += 0x24;
        }
        s += 0x6C;
    }
    return func_0046CE70(o);
}
