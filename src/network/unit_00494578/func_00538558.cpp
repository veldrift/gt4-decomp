typedef int s32;
typedef unsigned int u32;

struct Obj {
    u32 lo;      /* 0x0 */
    u32 hi;      /* 0x4 */
    s32 unk8;    /* 0x8 */
    s32 c;       /* 0xC */
};

extern "C" s32 func_00538558(Obj *p, s32 *out) {
    s32 ret = 2;
    if (p != 0 && out != 0) {
        if (p->c != 0) {
            u32 a = p->lo;
            u32 b = p->hi;
            if (a < b) {
                *out = b - a;
            } else {
                *out = p->unk8 - a;
            }
        } else {
            *out = 0;
        }
        ret = 0;
    }
    return ret;
}
