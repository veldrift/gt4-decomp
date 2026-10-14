typedef int s32;
typedef unsigned int u32;

struct S42F060 {
    char pad0[0xB6C0];
    s32 total;
};

struct B42F060 {
    s32 p0;
    s32 f0C;
    s32 f10;
};

extern "C" s32 func_005797A8(s32 a, s32 b, s32 c);

extern "C" void *func_0042F060(struct S42F060 *self, s32 arg1, s32 arg2, s32 arg3) {
    s32 ret;
    s32 a0;
    struct B42F060 *b;
    ret = func_005797A8(arg1, arg2, arg3);
    b = (struct B42F060 *)((char *)self + 8);
    a0 = self->total - ret;
    if (a0 > 0) {
        s32 v1 = b->f10;
        if (v1 >= a0) {
            u32 v0 = (u32)b->f0C + (u32)(v1 - a0);
            u32 c = (v0 < 0xB6A);
            u32 t = v0 - 0xB6A;
            v0 = c ? v0 : t;
            return (char *)b + (v0 << 4) + 0x10;
        }
    }
    return 0;
}
