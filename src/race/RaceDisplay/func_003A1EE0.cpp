typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

struct Obj {
    char pad0[0x1C];
    s32 f1C;
    char pad1[0x46 - 0x20];
    u8 f46;
    char pad2[0x48 - 0x47];
    s8 f48;
    char pad3[0x58 - 0x49];
    s32 f58;
};

extern "C" s32 func_003A1EE0(Obj *self) {
    s32 v = self->f1C;
    if (v < 10) {
        if (!(v < 8))
            return 0;
    }
    s32 a = self->f46;
    if (a != 0) {
        s8 t = self->f48;
        if (t == 0 || t == 3)
            return (self->f58 >> 2) & 1;
    }
    return 0;
}
