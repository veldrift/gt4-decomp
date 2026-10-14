/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Sub { char p0[4]; s32 f4; char p8[0x20]; void *f28; char pc[0x3F0]; };
struct Rec { char p[4]; short s4; short s6; };
struct Obj { Sub subs[2]; char pad[0x858 - 2 * 0x41C]; s32 f858; };
extern char D_006B04A8[];
extern "C" s32 func_004B4628(void *, s32, s32, s32, void *);
extern "C" void func_004B5D48(void *, s32, void *);
extern "C" void func_004B5F50(Obj *o, Rec *r) {
    s32 idx = 1 - o->f858;
    Sub *e = o->subs + idx;
    void *p = e->f28;
    s32 one = 1;
    if (r->s6 - r->s4 < one) return;
    s32 x = func_004B4628(p, o->subs[0].f4, r->s6 - 1, one, D_006B04A8);
    func_004B5D48(o, x, r);
}
