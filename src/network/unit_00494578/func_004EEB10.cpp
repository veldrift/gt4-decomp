typedef int s32;
typedef unsigned int u32;

struct func_004EEB10_self {
    s32 m0;
    char pad4[0x90];
    s32 m94;
};

extern "C" s32 func_004EF730(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 func_004EEB10(void *arg0, s32 arg1) {
    struct func_004EEB10_self *self = (struct func_004EEB10_self *)arg0;
    s32 r;

    if (self->m0 == 0) {
        return 0;
    }
    r = func_004EF730(arg0, self->m94, 0xA, arg1, 0x10);
    return (s32)((u32)~r >> 31);
}
