typedef int s32;
extern "C" void *memcpy(void *, const void *, unsigned);
struct Glob { char pad[0x39E1C]; s32 f39E1C; };
extern Glob *D_00622F4C;
extern const short D_006A5818[];
extern const char D_006A5828[], D_006A5830[];
struct Demo {
    s32 f0;
    short name1[6];
    char pad10[0x14];
    char name2[8];
    char pad2C[0x1C];
    s32 f48, f4C, f50, f54;
    char pad58[0x14];
    s32 f6C;
};
extern "C" void func_0030BB18(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" s32 func_00329CB0(void *, const char *, s32, void *);

extern "C" s32 GranTurismo4__Demonstration__next(Demo *self) {
    s32 buf0[4];
    s32 buf1[4];
    s32 sp20;
    s32 r = 1;
    if (self->f6C <= 0 && D_00622F4C->f39E1C > 0) {
        self->f0 = 2;
        memcpy(self->name1, D_006A5818, 11);
        memcpy(self->name2, D_006A5828, 8);
    } else {
        func_0030BB18(buf0);
        s32 *p = buf1;
        func_002FE278(p, self->f48);
        if (buf0 != p) {
            s32 nv = *p;
            if (nv != 0) func_003285A8(nv);
            if (buf0[0] != 0) func_003285F8(buf0[0]);
            buf0[0] = nv;
        }
        func_002FC870(p, 2);
        sp20 = 1;
        func_00329CB0(&sp20, D_006A5830, 1, buf0);
        s32 n = self->f48 + 1;
        s32 below = n < self->f4C;
        self->f48 = n;
        r = sp20 != 0;
        if (!below) self->f48 = 0;
        if (buf0 != &buf0[1]) func_00309378(buf0, 2);
    }
    s32 v = self->f6C - 1;
    self->f6C = v;
    if (v < 0) self->f6C = D_00622F4C->f39E1C - 1;
    s32 w = self->f54 - 1;
    self->f54 = w;
    if (w <= 0) {
        r = 0;
        self->f54 = self->f50;
    }
    return r;
}
