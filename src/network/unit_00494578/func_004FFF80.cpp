/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct P { char p[0x18]; s32 f18, f1C, f20; };
struct Obj { char p[0x40]; s32 f40; char p44[0x564]; P *f5A8; };
extern "C" s32 func_004F0C88(Obj *);
extern "C" s32 func_004F0CD0(Obj *, s32);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" s32 func_004FFF80(Obj *o) {
    s32 r = func_004F0C88(o);
    if (r != 0) {
        func_005A48D8(o->f5A8, 0, 0x38);
        P *p = o->f5A8;
        p->f18 = 0;
        p->f1C = o->f40;
        p->f20 = 2;
        return func_004F0CD0(o, 0x10);
    }
    return r;
}
