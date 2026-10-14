/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
class Ctl {
public:
    char pad[0x974];
    virtual void v0(s32);
};
class DemB {
public:
    char pad0[0x64];
    virtual void v0(s32);
#define V4(n) virtual void a##n(s32); virtual void b##n(s32); virtual void c##n(s32); virtual void d##n(s32);
#define V20(n) V4(n##0) V4(n##1) V4(n##2) V4(n##3) V4(n##4)
    V20(p) V20(q) V20(r) V20(s) V4(t0) V4(t1) V4(t2) V4(t3)
    virtual void v97(s32); virtual void v98(s32); virtual void v99(s32);
    virtual void v100(s32);
};
class Dem : public DemB {
public:
    char pad1[0x6C - 0x68];
    void *p6c;
    char pad2[0xCE0 - 0x70];
    s32 stateCE0;
    char pad3[0xD6C - 0xCE4];
    s32 flagD6C;
};
struct Info { char pad[0x120]; s32 f120; char pad2[0x2D0 - 0x124]; };
extern "C" void func_0010AF40(int);
extern "C" void func_0010B9C8(void *, int);
extern "C" void RaceArcadeDemoInformation__structor_0(void *);
extern "C" void RaceArcadeDemoInformation__structor_1(void *, s32);
extern "C" void RaceArcadeDemo__structor_0(void *);
extern "C" Ctl *func_003B7850(void *);
extern "C" void func_003BB440(void *, int);
extern "C" void func_0044CA98(int, int, int, int);
extern "C" void func_0044CB10(void);
extern "C" void *exception__structor_0(s32);

static inline s32 getState(Dem *d) { return d->stateCE0; }
extern "C" s32 func_0010BA28(int arg0, int arg1, int arg2, int arg3) {
    Info info;
    s32 r = 1;
    func_0010AF40(0);
    func_0044CA98(0x30000, 2, 6, 0xBC8000);
    RaceArcadeDemoInformation__structor_0(&info);
    func_003BB440(&info, arg0);
    info.f120 = arg1;
    Ctl *c = func_003B7850(&info);
    Dem *d = (Dem *)exception__structor_0(0x24140);
    RaceArcadeDemo__structor_0(d);
    d->flagD6C = r;
    d->p6c = c;
    if (arg2 != 0) func_0010B9C8(d, arg3);
    d->v100(4);
    s32 st = getState(d);
    s32 *p = &st;
    r = *p == 6;
    if (d != 0) d->v0(3);
    if (c != 0) c->v0(3);
    RaceArcadeDemoInformation__structor_1(&info, 2);
    func_0044CB10();
    return r;
}
