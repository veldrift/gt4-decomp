typedef int s32;
typedef unsigned short u16;

extern char RaceShiftPositionDisplay__vtable[];
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void func_003A9608(void *);
extern "C" s32 func_003A9758(void *);

extern "C" s32 RaceShiftPositionDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = RaceShiftPositionDisplay__vtable;
    func_003A9608((char *)arg0 + 0x18);
    s32 r = func_003A9758((char *)arg0 + 0x38);
    *(signed char *)((char *)arg0 + 0x54) = 0;
    *(signed char *)((char *)arg0 + 0x55) = 0;
    *(s32 *)((char *)arg0 + 0x54) = (s32)*(u16 *)((char *)arg0 + 0x54);
    return r;
}
