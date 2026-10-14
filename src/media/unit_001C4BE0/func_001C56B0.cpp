/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Obj { char p0[0x30]; s32 u30; s32 u34; s32 u38; char p3c[4]; s32 u40; };
struct Cb { void (*fn)(void*); void *arg; };
extern s32 D_006182A4; extern s32 D_006182A8;
extern char D_001C0000[]; extern char D_00693CE0[]; extern char D_00693CF0[];
extern "C" void *func_00575098(Cb *a, s32 b);
extern "C" s32 func_005775B0(s32, char*, s32, char*);
extern "C" u8 *func_00578610(u8 *);
extern "C" s32 func_005788B8(void *);
extern "C" int func_00578B50(unsigned int, int);
extern "C" int func_0058BF60();
extern "C" void func_001C59A8(void*);

extern "C" void func_001C56B0(Obj *o) {
    Cb cb;
    void *r;
    if (o->u34 != 0) return;
    o->u34 = 1;
    if (o->u40 < 0) {
        o->u40 = func_005775B0(D_006182A4, D_00693CE0, D_006182A8, D_00693CF0);
    }
    func_0058BF60();
    if (o->u30 != 0) return;
    o->u38 = 0;
    cb.fn = func_001C59A8;
    cb.arg = o;
    r = func_00575098(&cb, (s32)func_00578610((u8*)func_00578B50(1, -1)));
    func_005788B8(r);
    o->u30 = (s32)r;
}
