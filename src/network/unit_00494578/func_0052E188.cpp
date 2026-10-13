typedef int s32;
typedef unsigned int u32;

struct Range {
    u32 lo;
    u32 hi;
    u32 len;
};

extern "C" s32 func_0052E188(Range *r, s32 *out) {
    s32 ret = 2;
    if (out != 0) {
        u32 b = r->hi;
        u32 a = r->lo;
        if (a < b) {
            *out = r->len - b;
        } else if (b < a) {
            *out = a - b;
        } else {
            *out = 0;
        }
        ret = 0;
    }
    return ret;
}
