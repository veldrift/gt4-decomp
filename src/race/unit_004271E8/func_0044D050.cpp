struct VE { short off; short pad; int (*fn)(void *); };
struct Obj { int vt; };
union HW { short h[2]; int w; };
struct Out { int size; int a; HW hw; int pad; char name[1]; };
extern "C" int func_0044D020(void);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" char *func_005A609C(char *, const char *);
extern const char *D_0062382C;
static inline int vcall(Obj *o, int off) {
    VE *e = (VE *)(o->vt + off);
    return e->fn((char *)o + e->off);
}
extern "C" void *func_0044D050(Obj *o, Out *out) {
    int n = func_0044D020();
    func_005A48D8(out, 0, n);
    out->size = n;
    out->a = vcall(o, 0x18);
    out->hw.h[0] = vcall(o, 0x28);
    out->hw.h[1] = vcall(o, 0x20);
    func_005A609C(out->name, D_0062382C);
    return (char *)out + out->size;
}
