/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long U __attribute__((aligned(4)));
struct E { U v; char pad[0x18]; int f20; };
struct Obj { char pad[0x7C]; int (*f7C)(void *, U); };
extern Obj *D_0064B4B0;
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" E *func_00535C88(int, unsigned);
extern "C" int func_00531910(void *out, int a1, unsigned a2) {
    if (out == 0) return 0x17;
    func_005A48D8(out, 0, 0x10);
    E *e = func_00535C88(a1, a2);
    if (e == 0) return 8;
    if (e->f20 == 0) return 8;
    D_0064B4B0->f7C(out, e->v);
    return 0;
}
