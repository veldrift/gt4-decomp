typedef int s32;

struct Blk { char b[32]; };

extern "C" void func_00335D18(char *arg0, char *arg1, const char *arg2) {
    if (arg2 != 0) {
        *(s32 *)(arg0 + 0x1E0) = 1;
        *(struct Blk *)(arg0 + 0x1E4) = *(const struct Blk *)arg2;
    }
    *(struct Blk *)arg1 = *(struct Blk *)(arg0 + 0x150);
}
