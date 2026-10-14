/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Blk { s32 d[0x51]; };
struct Obj {
    char pad0[0x18];
    char sub[0x18];
    Blk blk;
    s32 f174, f178, f17C, f180, f184, f188;
};
extern "C" {
s32 func_00147D78(void *);
s32 func_00147D80(void *);
void func_0043DE40(s32, s32);
void func_00449EF0(void *, void *);
void func_00145970(Obj *a, Obj *b) {
    func_0043DE40(func_00147D80(a), func_00147D78(b));
    func_00449EF0(a->sub, b->sub);
    a->blk = b->blk;
    a->f174 = b->f174;
    a->f178 = b->f178;
    a->f17C = b->f17C;
    a->f180 = b->f180;
    a->f184 = b->f184;
    a->f188 = b->f188;
}
}
