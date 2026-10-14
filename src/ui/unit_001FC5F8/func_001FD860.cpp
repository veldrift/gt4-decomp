typedef int s32;
struct S {
    s32 f0; s32 f4; s32 f8; char pad0c[0x74];
    s32 f80; char pad84[4]; s32 f88; s32 f8c; s32 f90; s32 f94; char pad98[0x1c]; s32 fb4;
};
extern "C" void func_00105460(S *, s32, s32);
extern "C" s32 func_00105528(S *);
extern "C" void func_004A4550(s32, s32);
extern "C" void func_004A4910(void);
extern "C" void func_004A4DE0(s32, s32, s32, s32, s32, s32, s32, s32);

extern "C" void func_001FD860(S *self) {
    s32 y;
    if (self->fb4 != 0) {
        y = 0;
        func_00105460(self, self->f90, self->f94);
        self->f4 = 0;
        func_00105528(self);
        self->f80 = 1;
        s32 p = self->f88;
        if (self->f90 > 0) {
            do {
                s32 x = 0;
                if (self->f94 > 0) {
                    do {
                        func_004A4DE0(self->f0, self->f4, (self->f8 + 0x3F) & ~0x3F, y, x, 0x10, 0x10, p);
                        x += 0x10;
                        p += 0x400;
                    } while (x < self->f94);
                }
                y += 0x10;
            } while (y < self->f90);
        }
        func_004A4910();
        func_004A4550(2, 1);
        func_004A4550(3, 1);
    }
}
