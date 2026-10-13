typedef int s32;

extern "C" void *func_00575F70(void *a, s32 b, s32 c);

struct Blk {
    Blk *next;
    s32 index;
    s32 size;
    s32 z0;
    s32 z1;
};

struct Pool {
    char pad[0x4C];
    Blk **table;
};

extern "C" Blk *func_005AC4D8(Pool *arg0, s32 arg1) {
    Blk **tab;
    Blk **slot;
    Blk *r;
    s32 temp_s0;

    tab = arg0->table;
    if (tab == 0) {
        tab = (Blk **)func_00575F70(arg0, 4, 0x10);
        arg0->table = tab;
        if (tab == 0) {
            return 0;
        }
    }
    slot = (Blk **)(arg1 * 4 + (s32)tab);
    r = *slot;
    if (r != 0) {
        *slot = r->next;
    } else {
        temp_s0 = 1 << arg1;
        r = (Blk *)func_00575F70(arg0, 1, temp_s0 * 4 + 0x14);
        if (r == 0) {
            return 0;
        }
        r->index = arg1;
        r->size = temp_s0;
    }
    r->z1 = 0;
    r->z0 = 0;
    return r;
}
