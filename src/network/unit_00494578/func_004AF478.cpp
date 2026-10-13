typedef int s32;

struct func_004AF478_blk {
    s32 (*fn)(s32, void *);
    s32 arg;
};

extern "C" void func_004AF478(void *arg0) {
    func_004AF478_blk *p = (func_004AF478_blk *)((char *)arg0 + 0x6C);
    s32 (*temp_v0)(s32, void *);

    temp_v0 = p->fn;
    if (temp_v0 != 0) {
        temp_v0(p->arg, arg0);
    }
}
