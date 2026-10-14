/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

extern "C" char RaceEntryCar__vtable[];
extern "C" char D_00682F98[];

extern "C" void func_00343490(void *);
extern "C" void *RaceCarModel__structor_0(void *);
extern "C" void func_00391FD0(void *);
extern "C" void RaceEntryInformation__structor_0(void *) throw();
extern "C" void func_003B52E8(void *);
extern "C" void func_003BB840(void *);
extern "C" void RaceLapTime__structor_0(void *);
extern "C" s32 func_003DD768(void *);
extern "C" s32 func_005792D8(void *);
extern "C" void *func_005A48D8(void *, int, unsigned int);

static inline void setv(f32 *p, f32 x, f32 y, f32 z) { p[0] = x; p[1] = y; p[2] = z; }

struct Sub { s32 vt, i4, i8; char pad[0x5C]; char b68[1]; };

#define I(off) (*(s32 *)((char *)self + (off)))

extern "C" void *RaceEntryCar__structor_0(char *self) {
    Sub *sub = (Sub *)(self + 0x2890);
    I(0x35CC) = (s32)RaceEntryCar__vtable;
    RaceEntryInformation__structor_0(self + 0x20);
    RaceLapTime__structor_0(self + 0x1A0);
    func_003BB840(self + 0x1158);
    func_003BB840(self + 0x119C);
    func_003DD768(self + 0x11E0);
    RaceCarModel__structor_0(self + 0x11F0);
    sub->vt = (s32)D_00682F98;
    sub->i8 = 1;
    f32 *p = (f32 *)(self + 0x28A0);
    s32 n = 3;
    do {
        n--;
        setv(p, 0.0f, 1.0f, 0.0f);
        p += 5;
    } while (n != -1);
    func_005792D8(sub->b68);
    sub->i4 = 0;
    func_00391FD0(self + 0x2900);
    func_00343490(self + 0x3468);
    I(0x0) = 0;
    I(0x14) = -1;
    I(0x2888) = 1;
    I(0x4) = 0;
    I(0x8) = 0;
    I(0x18) = 0;
    I(0x343C) = 0;
    I(0x2880) = 0;
    I(0x2884) = 0;
    I(0x288C) = 0;
    func_003B52E8(self);
    I(0x28FC) = 0;
    I(0x3440) = -1;
    I(0x3450) = 1;
    I(0x3454) = 1;
    I(0x3458) = 1;
    I(0x11E4) = 0x157529FF;
    I(0x11E8) = 0x157529FF;
    I(0x345C) = 2;
    I(0x11EC) = 0;
    I(0x3444) = 0;
    I(0x3448) = 0;
    I(0x344C) = 0;
    I(0x3460) = 0;
    I(0x3464) = 0;
    I(0x3488) = 0;
    func_005A48D8(self + 0x348C, 0, 0x80);
    func_005A48D8(self + 0x350C, 0, 0x80);
    func_005A48D8(self + 0x358C, 0, 0x20);
    func_005A48D8(self + 0x35AC, 0, 0x10);
    return func_005A48D8(self + 0x35BC, 0, 0x10);
}
