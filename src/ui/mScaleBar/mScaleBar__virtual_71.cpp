/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Ev {
    char pad0[0x20];
    s32 f20;
    char pad1[0x30 - 0x24];
    s32 f30;
};

struct Obj {
    char pad0[0xC4];
    f32 fC4;
    char pad1[0xD8 - 0xC8];
    f32 fD8;
    char pad2[0xF0 - 0xDC];
    s32 fF0;
    char pad3[0x100 - 0xF4];
    s32 f100;
    s32 f104;
};

extern "C" void func_00238978(Obj *, s32);
extern "C" void func_00238A10(Obj *, s32);
extern "C" s32 func_00238A70(Obj *, s32);
extern "C" s32 func_00238B28(Obj *, s32);
extern "C" void func_00238BE0(Obj *, s32);
extern "C" void func_00238C60(Obj *, s32);
extern "C" void func_00238FF0(Obj *, f32);
extern "C" s32 func_00239048(Obj *, f32);
extern "C" s32 func_00239098(Obj *, s32, f32);
extern "C" s32 mWidget__onKeyPress(Obj *, s32, Ev *);

extern "C" s32 mScaleBar__virtual_71(Obj *self, s32 arg1, Ev *ev) {
    s32 s1;
    s32 s2;
    s32 s3;
    if (self->fF0 != 0) {
        s1 = ev->f20;
        if (s1 == 0xFF0D) {
            if (self->f100 == 0) {
                func_00238BE0(self, arg1);
            } else {
                self->f104 = 0;
                func_00238C60(self, arg1);
            }
            return 1;
        }
        if (s1 == 0xFF1B && self->f100 != 0) {
            self->f104 = 1;
            func_00238C60(self, arg1);
            return 1;
        }
    } else {
        s1 = ev->f20;
    }
    if ((func_00238A70(self, s1) != 0 || func_00238B28(self, s1) != 0) && ev->f30 == 0) {
        func_00238FF0(self, self->fC4);
        func_00238A10(self, arg1);
    }
    s2 = mWidget__onKeyPress(self, arg1, ev);
    if (s2 == 0) {
        if (self->f100 != 0 || self->fF0 == 0) {
            s3 = 0;
            if (func_00238A70(self, s1) != 0) {
                s3 = func_00239098(self, s1, self->fD8);
            } else if (func_00238B28(self, s1) != 0) {
                s3 = func_00239048(self, self->fD8);
            }
            if (self->f100 != 0) s2 = 1;
            if (s3 != 0) {
                func_00238978(self, arg1);
                func_00238A10(self, arg1);
                s2 = 1;
            }
        }
    }
    return s2;
}
