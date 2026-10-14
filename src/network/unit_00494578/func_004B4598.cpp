/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Sub {
    s32 f0; s32 f4; short *f8; char pc[4]; short s10; char p12[0x1FE];
    s32 f210; s32 f214; char b218; char p219[3]; short s21C; short s21E;
    char p220[0x1F8]; s32 f418;
};
struct W { char b; char p1[3]; short s4; short s6; };
struct Obj {
    char p0[0x10]; s32 f10; short *f14; char p18[4]; s32 f1C;
    Sub subs[2];
    char pad[0x858 - 0x20 - 2 * sizeof(Sub)];
    s32 f858; s32 f85C; s32 f860;
};
extern "C" void *func_004B59C0(void *, s32);
extern "C" void func_004B8270(void *);
extern "C" void func_004B4598(Obj *o) {
    Sub *v = &o->subs[1];
    o->f10 = 0;
    *o->f14 = 0;
    o->f1C = 0;
    o->f858 = 0;
    o->f85C = 0;
    o->f860 = 0;
    v->f0 = 0;
    v->f4 = 0;
    *v->f8 = 0;
    v->s10 = 0;
    v->f210 = 0;
    v->f214 = 0;
    W *w = (W *)((char *)o + 0x654);
    w->b = 1;
    w->s6 = 0;
    w->s4 = 0;
    v->f418 = 0;
    func_004B59C0(o, 6);
    func_004B59C0(o, 6);
    func_004B8270(o);
}
