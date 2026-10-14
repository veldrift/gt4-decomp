/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

struct Slot { char pad[0x6C8]; f32 a; f32 b; };
struct Ev { char pad[0xDC]; s32 f; };

extern "C" Slot *func_0034C190(void *arg0, s32 arg1);
extern "C" void func_00343D78(void *p, s32 n);
extern "C" s32 DynamicsConductorMachineTest__getTestMode(void *p) throw();
extern "C" s32 func_00358000(void *self, s32 a, u32 b);
extern "C" void RaceDisplayGeneralTimeEvent__structor_1(void *self, s32 v, s32 w, s32 x, s32 t, s32 f);
extern "C" void func_0035E7C0(void *self, s32 a, f32 c, u8 b);
extern "C" void func_0035DF80(void *p, s32 a, s32 b, s32 c);

extern "C" s32 DynamicsConductorMachineTest__ProcessGoalLine(Ev **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    Slot *s0 = func_0034C190(arg0, arg1);
    Ev *ev = *arg0;
    char *q = (char *)s0 + 0x104;
    s32 m;
    if (s0->b < s0->a) {
        s0->b = s0->a;
    }
    if (ev->f != 0) {
        return 0;
    }
    func_00343D78(s0, 1);
    if (*(u8 *)(q + 0x441) == 0 && *(u8 *)((char *)arg0 + 0xCBDC) == 0) {
        m = DynamicsConductorMachineTest__getTestMode(arg0);
        if (m < 3) {
            if (m > 0) {
                func_00358000(arg0, arg1, arg5);
            }
        }
    }
    m = DynamicsConductorMachineTest__getTestMode(arg0);
    switch (m) {
    case 1:
    case 2:
        RaceDisplayGeneralTimeEvent__structor_1(arg0, arg1, arg2, arg4, arg5, *(u8 *)((char *)s0 + 0x5B7));
        break;
    case 0:
    case 3:
        func_0035E7C0(arg0, arg1, s0->b, *(u8 *)((char *)s0 + 0x5B7));
        break;
    }
    if (arg1 == 0) {
        func_0035DF80(*arg0, 5, 0, 2);
    }
    return 1;
}
