typedef unsigned char u8;
typedef int s32;

extern "C" s32 func_001C1EF8(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 stride = (arg1 + 0xF) & ~0xF;
    s32 sum = 0;
    u8 *row = arg0;

    if (arg2 != 0) {
        do {
            s32 n = arg1;
            u8 *p = row;
            if (n != 0) {
                do {
                    __asm__ volatile("pref 0x0, 0x40(%0)" : : "r"(p));
                    sum += *p;
                    p++;
                    n--;
                } while (n != 0);
            }
            arg2 -= 1;
            row += stride;
        } while (arg2 != 0);
    }
    return sum;
}
