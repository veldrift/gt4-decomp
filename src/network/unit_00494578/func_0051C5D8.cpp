typedef int s32;
typedef unsigned int u32;

struct Item {
    char pad0[0x4C];
    u32 f4C;
    u32 f50;
    char blk54[0x6C - 0x54];
    char blk6C[1];
};
struct Tab {
    char pad0[0x78];
    Item *items[2];
};

extern "C" {
s32 func_0051BE28() throw();
void func_0051BE60() throw();
Tab *func_0051DD88(s32);
s32 func_00538530(void *, s32 *);
}

extern "C" s32 func_0051C5D8(s32 a0, u32 *o1, u32 *o2, u32 *o3, u32 *o4)
{
    s32 sp0;
    s32 sp4;
    s32 sp10;
    u32 t3, t2, t6, t5;
    u32 i;
    Tab *tab;
    Item **p;
    s32 r;

    sp10 = 0;
    r = func_0051BE28();
    if (r != 0) {
        return r;
    }
    t3 = 0;
    tab = func_0051DD88(a0);
    t2 = 0;
    t6 = 0;
    t5 = 0;
    i = 0;
    p = tab->items;
    if (tab == 0) {
        sp10 = 2;
        goto done;
    }
    do {
        Item *it = *p;
        p++;
        if (it != 0) {
            sp0 = 0;
            sp4 = 0;
            func_00538530(it->blk6C, &sp0);
            t2 += sp0;
            t3 += it->f4C;
            func_00538530(it->blk54, &sp4);
            t5 += sp4;
            t6 += it->f50;
        }
        i++;
    } while (i < 2);
    *o1 = t2;
    *o2 = t5;
    if (t3 != 0) {
        u32 v = t2 * 100 / t3;
        *o3 = v;
        if (v > 100) {
            *o3 = 100;
        }
    } else {
        *o3 = 0;
        sp10 = 0xCB20;
    }
    if (t6 != 0) {
        u32 v = t5 * 100 / t6;
        *o4 = v;
        if (v > 100) {
            *o4 = 100;
        }
    } else {
        *o4 = 0;
        sp10 = 0xCB20;
    }
done:
    func_0051BE60();
    return sp10;
}
