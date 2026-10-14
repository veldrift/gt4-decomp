typedef int s32;
typedef signed char s8;
typedef long long s64;

struct Blk8 {
    s64 q[47];
};

struct Blk4 {
    s32 w[8];
};

extern "C" void setCarEquipment(char *self, char *src) {
    char *d = self + 0x20;
    *(Blk8 *)d = *(Blk8 *)src;
    *(Blk4 *)(self + 0x3468) = *(Blk4 *)(src + 0x178);
    *(s32 *)(d + 0x178) = *(s32 *)(src + 0x198);
    *(s32 *)(self + 0x3444) = *(s32 *)(src + 0x19C);
    *(s32 *)(self + 0x3448) = *(s8 *)(src + 0x1A0) != 0;
    *(s32 *)(self + 0x344C) = *(s8 *)(src + 0x1A1);
    *(s32 *)(self + 0x3450) = *(s8 *)(src + 0x1A2) != 0;
    *(s32 *)(self + 0x3454) = *(s8 *)(src + 0x1A3) != 0;
    *(s32 *)(self + 0x3458) = *(s8 *)(src + 0x1A4) != 0;
    *(s32 *)(self + 0x345C) = *(s8 *)(src + 0x1A5);
}
