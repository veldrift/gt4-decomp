/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Buf { u8 *p; unsigned size; int pad[2]; };
extern "C" int func_0044BFA8(void *);
extern "C" void *func_0044C2F0(void *, void *, void *, void *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A48D8(void *, int, unsigned);

extern "C" void func_0044C7F8(Buf *src) {
    Buf a, b, c;
    Buf *pb = &b;
    u8 ten = 10;
    Buf *pc = &c;
    unsigned n = src->size;
    unsigned sz = (n + 15) >> 4 << 4;
    a.size = n;
    a.p = (u8 *)__builtin_alloca(sz);
    pb->p = (u8 *)__builtin_alloca(sz);
    b.size = n;
    pc->p = (u8 *)__builtin_alloca(sz);
    c.size = n;
    func_005A48D8(pb->p, 0, b.size);
    pb->p[0] = ten;
    pb->p[1] = 0;
    pb->p[2] = 0;
    pb->p[3] = 0;
    func_005A4724(a.p, src->p, a.size);
    func_0044C2F0(src, &a, pb, pc);
    func_0044BFA8(pc);
}
