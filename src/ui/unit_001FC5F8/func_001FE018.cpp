/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct S {
    char pad0[0x84];
    s32 f84; s32 f88; s32 f8c; char pad90[0x14];
    s32 fA4; s32 fA8; s32 fAC; s32 fB0; void *fB4;
};
extern long long D_00697118;
extern "C" double func_0057F470(long long);
extern "C" double dpmul(double, double);
extern "C" long long func_0057F3C0(double);
extern "C" void func_001FDE68(S *, s32) throw();
extern "C" s32 func_004A7C60(void);
extern "C" s32 func_0054EDA0(void *);
extern "C" s32 func_0054EF30(void *);
extern "C" s32 func_0054EF70(void *);
extern "C" void func_0054EFB0(void *);
extern "C" void func_0054F5E0(long long, long long);

extern "C" void func_001FE018(S *self) {
    if (self->fB4 != 0 && self->fAC == 0) {
        if (func_004A7C60() == 3) {
            if (func_0054EF30(self->fB4) >= 2) func_0054EFB0(self->fB4);
            long long s1 = self->fA4;
            s32 v = func_0054EF70(self->fB4);
            if (v != self->f84) {
                self->f84 = v;
                if (self->fB0 != 0 && v != 0) func_001FDE68(self, v);
                self->f8c = 0;
                self->fA4 = self->fA4 + 1;
            } else {
                self->f8c = 1;
            }
            if (self->f84 != 0) {
                if (s1 >= 0) {
                    if (self->fA8 != 0) {
                        func_0054F5E0(0, -1ULL >> 1);
                    } else {
                        double d = 33366.05431059392;
                        double m1 = (double)s1 * d;
                        double m2 = (double)(s1 + 5) * d;
                        func_0054F5E0((long long)m1, (long long)m2);
                    }
                }
            } else if (func_0054EDA0(self->fB4) != 0 && self->fA4 > 0) {
                func_0054F5E0(0, -1ULL >> 1);
            }
        } else {
            if (self->fB0 != 0) {
                s32 a = self->f88;
                if (a != 0) func_001FDE68(self, a);
            }
        }
        if (self->f84 != 0) self->f88 = self->f84;
    }
}
