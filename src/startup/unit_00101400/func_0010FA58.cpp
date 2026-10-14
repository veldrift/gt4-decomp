typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct B32 { char b[0x20]; };
struct Tail { char pad[0x6DC]; B32 blk; };
struct Obj18 { char pad[0x18]; Tail *t; };
struct N0 { char pad[0x18]; Tail *p18; };
struct N8 { N0 *p0; };
struct N60 { char pad[8]; N8 *p8; };
struct A0 { char pad[0x60]; s32 p60; };
struct G { char pad4[4]; char pad[0x13934]; char pad2[0]; };
struct GG { char pad[0x13938]; char x[1]; };
struct Dst { char pad[0x13DD8]; B32 blk; };

extern Dst *D_00622F4C;
extern "C" s32 func_00441248(void *);
extern "C" f32 Automobile__getTripMeter(void *, s32);

extern "C" void func_0010FA58(A0 *arg0, u32 *arg1, u32 *arg2) {
    Dst *d = D_00622F4C;
    func_00441248((char *)d + 0x13938);
    Tail *t = ((N60 *)arg0->p60)->p8->p0->p18;
    d->blk = t->blk;
    *arg1 = (u32)Automobile__getTripMeter(((N60 *)arg0->p60)->p8->p0->p18, 0);
    *arg2 = (u32)Automobile__getTripMeter(((N60 *)arg0->p60)->p8->p0->p18, 1);
}

struct Gl { char pad0[4]; char a[0x40]; };
extern Gl *D_00622F4C_;
