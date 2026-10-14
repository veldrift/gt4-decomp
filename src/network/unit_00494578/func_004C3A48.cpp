/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Values { short x0, x2, x4, x6; };
struct Obj { char pad[0x10]; Values *values; short *p14; unsigned char *p18; int p1c; short *p20; };
static inline void reset(Values *v, int n) {
    v->x0 = 0;
    v->x2 = 0;
    v->x4 = n;
    v->x6 = n;
}
extern "C" void func_004C3A48(Obj *p) {
    reset(p->values, -1);
    *p->p18 = 1;
    *p->p14 = 0x1FFF;
    *p->p20 = 0;
}
