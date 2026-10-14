typedef long long s64;
struct R { s64 a; s64 b; s64 c; s64 d; };
extern "C" void func_00434D80(R *r) {
    s64 f8 = r->b;
    s64 f18 = r->d;
    s64 f10 = r->c;
    f8 &= ~1LL;
    f8 &= ~2LL;
    f8 &= ~0x1FCLL;
    f8 &= 0xFFFFFFFFF80001FFLL;
    f8 &= 0xFFFFE000FFFFFFFFLL;
    f18 &= 0xFFFFFFFF000003FFLL;
    f10 &= 0xFFFFFFFFFF000000LL;
    f18 |= 0x3FF;
    r->c = f10;
    r->d = f18;
    r->a = -1;
    r->b = f8;
    *(int *)((char *)r + 0x14) = 0;
}
