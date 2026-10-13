typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;
struct Source {
    union {u64 word0;struct {u32 low0,high0;};};
    union {
        u64 word8;
        struct { u32 lo8; u32 hiC; };

    };
    s32 member10;
    s32 member14;
    u32 member18;
};
struct Target {
    char pad0[0x14];
    s32 car;
    char pad18[0x15C];
    s32 value174;
    s32 value178;
    s32 value17C;
    s32 value180;
    char pad184[4];
    s32 value188;
};
extern "C" s32 func_00435110(const Source *);
extern "C" s32 func_00440EC8(s32, u64);
extern "C" void func_00441298(s32, s32);
extern "C" void func_003434A8(s32, s32);
extern "C" void func_00440F78(s32);
extern "C" s32 func_00145B20(Target *self, const Source *src, s32 index) {
    s32 result = 0;
    self->value180 = index;
    if (index >= 0) {
        self->value174 = (s32)(src->word8 >> 32) & 0x1FFF;
        self->value178 = (s32)((src->word8 << 23) >> 32) & 0x3FFFF;
        self->value17C = func_00435110(src);
        self->value188 = src->member18 & 0x3FF;
        result = func_00440EC8(self->car, src->word0);
        if (result != 0) {
            func_00441298(self->car, (s32)(src->word8 << 30 >> 32) & 0x7F);
            func_003434A8(self->car + 0x4A0, src->member14);
            func_00440F78(self->car);
            result = 1;
        }
    }
    return result;
}
