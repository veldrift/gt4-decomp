/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Obj { char pad[0x3E8]; void *f3E8; };
extern "C" int func_0054FE98(void);
extern "C" int func_0054FEA8(void *);
extern int D_0064C4B0;
extern "C" float func_0054EDD0(Obj *o) {
    float r = 0.0f;
    if (D_0064C4B0 != 0) {
        u32 a = func_0054FEA8(o->f3E8);
        u32 b = func_0054FE98();
        r = (float)a;
        r /= (float)b;
    }
    return r;
}
