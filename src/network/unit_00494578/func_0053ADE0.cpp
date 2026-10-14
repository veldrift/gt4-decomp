struct Pair { int a, b; };
extern Pair D_0086B400;
extern "C" int func_0053B3C0();
extern "C" int func_0053ADE0(Pair *p) {
    if (!p) return 2;
    int r = func_0053B3C0();
    if (r) return 0x640;
    Pair *src = &D_0086B400;
    p->a = src->a;
    p->b = src->b;
    return r;
}
