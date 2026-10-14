struct P { int a, b; };
struct V { char pad[0x6c]; void (*f6c)(struct P *); };
struct O { char pad[0x10c]; struct P m10c; };
extern struct V *D_0064B4B0;
struct P func_00535D78(struct O *o) {
    struct P r;
    D_0064B4B0->f6c(&r);
    if (o) r = o->m10c;
    return r;
}
