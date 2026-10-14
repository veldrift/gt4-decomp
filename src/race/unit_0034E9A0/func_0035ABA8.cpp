/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E7 { char p[0x440]; unsigned char m440, m441; char q[0x614 - 0x442]; unsigned m614; };
struct E { char p[0x104]; E7 e7; };
struct Rec { char p[2]; unsigned char m2; char q[0x10F4 - 3]; unsigned char data[0x400]; };
extern "C" E *func_0034C190(void *, int);
extern "C" void func_003F85F0(E *, void *);
extern "C" void func_003455F0(E *);
extern "C" unsigned func_003584A0(void *, int) throw();
extern "C" void func_0045B948(void *, int);
extern "C" void func_0045CF18(void *, void *, int);

extern "C" void func_0035ABA8(char *self, int idx, Rec *r) {
    E *e = func_0034C190(self, idx);
    E7 *s1 = &e->e7;
    unsigned char s2 = s1->m441;
    unsigned char s3 = s1->m440;
    func_003F85F0(e, (char *)r + 0x54);
    s1->m441 = s2;
    char *base = self + 0xDA6C;
    s1->m440 = s3;
    func_003455F0(e);
    s1->m614 = func_003584A0(self, 0x32 - r->m2);
    func_0045B948(base, idx);
    int sum = 0;
    for (unsigned i = 0; i < 0x400; i++) sum += r->data[i];
    if (sum != 0) func_0045CF18(base + idx * 0x4F0 + 0xC, r->data, sum);
}
