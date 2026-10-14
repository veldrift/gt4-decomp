typedef int s32;
typedef long long s64;
struct __attribute__((packed)) B32 { s64 a, b, c, d; };
struct A8 { s32 p0; };
struct B60 { char pad[8]; A8 *p8; };
struct Obj { char pad[0x60]; B60 *p60; };
extern char *D_00622F4C;
extern "C" void func_003C0DF8(void *, s32, void *);
extern "C" s64 *func_00441248(void *);

extern "C" void func_0010F948(Obj *arg0) {
    char *base = D_00622F4C;
    char *src = base + 0x13938;
    s32 f = ~*func_00441248(src) == 0;
    if (!f) {
        func_003C0DF8(arg0, 0, func_00441248(src));
        char *dst = (char *)arg0->p60->p8->p0;
        *(B32 *)(dst + 0x3468) = *(B32 *)(base + 0x13DD8);
    }
}
