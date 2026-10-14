/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Ev { char pad[0x968]; u32 t; };
struct Car { char pad[0x5B7]; u8 f; };
struct Car2 { char pad[0x104 + 0x614]; s32 v; };

extern "C" s32 func_0034C190(void *, s32);
extern "C" void func_0035E000(void *, s32, s32);
extern "C" void RaceDisplayTimeDiffEvent__structor_0(void *, s32, s32);
extern "C" void RaceDisplayGeneralTimeEvent__structor_1(void *, s32, s32, s32, u32, u32);
extern "C" void func_00363528(void *);

extern "C" void DynamicsConductorFreePractice__ProcessControlLine(Ev **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    Ev *ev = *arg0;
    Car *c = (Car *)func_0034C190(arg0, arg1);
    char *q = (char *)c + 0x104;
    u32 f = c->f;
    if (f == 0) {
        u32 t = ev->t;
        if (t != 0x157529FF) {
            RaceDisplayTimeDiffEvent__structor_0(ev, arg1, arg5 - t);
        }
        if (arg5 < t) {
            func_0035E000(ev, arg1, 2);
        }
    }
    RaceDisplayGeneralTimeEvent__structor_1(arg0, arg1, arg2, arg4, arg5, c->f);
    func_00363528(c);
    *(s32 *)(q + 0x614) = arg4;
}
