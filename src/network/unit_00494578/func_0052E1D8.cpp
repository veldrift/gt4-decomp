typedef int s32;
typedef unsigned int u32;

struct Range {
    u32 lo;
    u32 hi;
    u32 len;
};

extern "C" s32 func_0052E1D8(Range *r, s32 *out) {
    s32 ret = 2;
    if (out != 0) {
        u32 a = r->lo;
        u32 b = r->hi;
        if (a < b) {
            *out = r->len - b + a;
        } else if (b < a) {
            *out = a - b;
        } else {
            *out = 0;
        }
        ret = 0;
    }
    return ret;
}
