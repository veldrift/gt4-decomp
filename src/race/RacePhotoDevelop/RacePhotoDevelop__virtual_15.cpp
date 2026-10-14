/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Self {
    char pad[0x2EF34];
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
};

extern char D_006184D0[];

extern "C" void func_001056A0(s32);
extern "C" void func_001063A8(void *);
extern "C" void func_00106A68(void *, s32, s32, s32);
extern "C" s32 func_00333A00(s32, s32);
extern "C" s32 func_00333E50(s32, s32);
extern "C" void func_003C8808(void);
extern "C" void func_004A2980(s32);
extern "C" void func_004A3078(s32);
extern "C" void func_004A3230(s32);

extern "C" void RacePhotoDevelop__virtual_15(Self *self, s32 arg1) {
    if (self->f3C == 0) {
        if (self->f40 == 2) {
            func_00106A68(D_006184D0, 2, 0x100, 0x180);
            func_003C8808();
        }
    }
    if (self->f40 != 0) {
        func_004A3078(0);
        func_004A2980(-1);
        func_001056A0(arg1);
        func_004A3230(1);
        self->f40 = self->f40 - 1;
        return;
    }
    s32 a = self->f3C;
    if (a >= 0) {
        s32 r;
        if (self->f34 != 0) {
            r = func_00333E50(self->f38, a);
        } else {
            r = func_00333A00(self->f38, a);
        }
        self->f3C = self->f3C + 1;
        if (r == 0) {
            func_001063A8(D_006184D0);
            func_003C8808();
            self->f40 = 2;
            self->f3C = -1;
        }
    }
}
