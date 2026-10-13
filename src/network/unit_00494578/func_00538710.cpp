typedef int s32;
typedef unsigned int u32;

struct Obj {
    u32 a;
    u32 b;
    s32 pad8;
    s32 c;
};

extern "C" s32 func_00538710(Obj *p, s32 *out) {
    s32 ret = 2;
    s32 f = (p != 0);
    if (p != 0) {
        if (out != 0) {
            u32 v = p->a;
            if (v < p->b || p->c == 0 || v == 0) {
                *out = 0;
            } else {
                *out = f;
            }
            ret = 0;
        }
    }
    return ret;
}
