typedef int s32;

struct func_0021C5A8_obj {
    s32 magic;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
};

extern "C" s32 func_0021C5A8(struct func_0021C5A8_obj *arg0, s32 arg1) {
    struct func_0021C5A8_obj *p = arg0;
    s32 *q;
    s32 v;
    s32 sum;

    if (p->magic != 0x564F4D4C) {
        return 0;
    }
    if (p->f4 != 0) {
        return 0;
    }
    p->f4 = arg1;
    if (p->fC != 2) {
        return 0;
    }
    q = &p->f14;
    v = *q;
    if (v != 0) {
        sum = v + arg1;
        arg1 = sum;
        *q = arg1;
    }
    return 1;
}
