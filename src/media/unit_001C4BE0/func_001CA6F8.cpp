typedef int s32;

struct Self6F8 {
    s32 f0;
    char pad4[0x3C - 4];
    s32 f3c;
};

extern char D_00693F60[];
extern "C" s32 func_001CA7B0(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" s32 func_001CA6F8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Self6F8 *self = (Self6F8 *)arg0;
    if (self->f3c != 0) {
        return (s32)D_00693F60;
    }
    self->f0 = arg1;
    return func_001CA7B0(arg0, arg2, arg3, 0);
}
