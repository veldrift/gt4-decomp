struct __attribute__((packed)) V { long long n; };
struct Arg { int a, b; };
struct Obj {
    char p0[0xA88];
    char p1[0xAB0 - 0xA88];
    V v0;
    V v1;
    char p2[0xAC0 - 0xAC0];
};
struct __attribute__((packed)) Obj2 {
    char p0[0xA88];
    char p1[8 + 0x20 - 0x8 + 0];
};
extern "C" {
void func_0046CE70(void *);
void func_0046E868(void *, int, int);
void func_00471EB8(void *);
void *func_005A48D8(void *, int, int);
}
struct O {
    char p0[0xAB0];
    V v0;
    V v1;
    char p1[0xD80 - 0xAC0];
    int flag;
    char p2[0xDCC - 0xD84];
    int m1, m2;
    char p3[0xDDC - 0xDD4];
    int m3;
};
extern "C" void func_0046CEE8(O *o, V *a, Arg *c)
{
    func_0046CE70(o);
    o->v0 = *a;
    o->v1 = *(V *)c;
    func_00471EB8((char *)o + 0xAC0);
    o->flag = 1;
    int i = 2;
    do {
        func_005A48D8((char *)o + 0xD84, 0, 0x18);
    } while (--i >= 0);
    o->m1 = 0;
    o->m2 = 0;
    o->m3 = 0;
    func_0046E868((char *)o + 0xA88, c->b, c->a);
}
