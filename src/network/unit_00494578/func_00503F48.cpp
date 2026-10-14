/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Ring { char p[8]; u32 f8; char pc[8]; u32 f14; };
struct Obj { char p[0x1C]; Ring r; char p2[0x38 - 0x1C - sizeof(Ring)]; char g[4]; };
extern "C" Obj *func_00503ED0(s32, s32);
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" u32 func_0057B500(Ring *, char *, u32);
struct Guard {
    void *p;
    Guard(void *q) : p(q) { func_00576100(q); }
    ~Guard() { func_00576140(p); }
};
extern "C" void func_00503F48(s32 a0, s32 a1, char *src, u32 n, s32 t0, s32 t1) {
    Obj *o = func_00503ED0(t1, a1);
    if (o != 0) {
        Ring *r = &o->r;
        if (n < r->f14 - r->f8) {
            Guard g(o->g);
            func_0057B500(r, src, n);
        }
    }
}
