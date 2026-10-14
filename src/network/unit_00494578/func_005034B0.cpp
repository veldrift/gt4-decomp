/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
struct Obj { char pad0[0x38]; s32 unk38; char pad3C[0x2180 - 0x3C]; s32 unk2180; s32 unk2184; s32 unk2188; };
struct A { void *fn; Obj *obj; s32 x[6]; };
struct B { void *p; s32 size; };
extern char D_00851480[];
extern "C" void func_00503780(void);
extern "C" void func_00503688(void);
extern "C" s32 func_005782E8(s32, s32);
extern "C" u8 *func_00578610(u8 *);
extern "C" s32 func_005788B8(s32);
extern "C" s32 func_00578968(A *, B *, u8 *);
extern "C" u8 *func_00578B50(u32 mode, s32 c);
extern "C" s32 func_005AD990(s32, void *, s32, Obj *);

extern "C" void func_005034B0(Obj *arg0) {
    A a;
    B b;
    arg0->unk2180 = func_005782E8(0, 0xFF);
    arg0->unk2188 = 0;
    a.fn = (void *)func_00503780;
    a.obj = arg0;
    B *pb = &b;
    pb->p = D_00851480;
    s32 sz = 0x2000;
    pb->size = sz;
    u8 *t = func_00578B50(4, 1);
    t = func_00578610(t);
    s32 r = func_00578968(&a, pb, t);
    arg0->unk38 = r;
    func_005788B8(r);
    arg0->unk2184 = func_005AD990(2, (void *)func_00503688, 0, arg0);
}
