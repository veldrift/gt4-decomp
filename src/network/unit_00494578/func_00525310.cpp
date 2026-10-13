typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

struct func_00525310_obj {
    char pad0[0x88];
    char *p88;          /* 0x88: entry table base (lw, t0) */
    char pad8C[0x9C - 0x8C];
    u16 n9C;            /* 0x9C: count (lhu) */
    char pad9E[0xBC - 0x9E];
    u32 nBC;            /* 0xBC: count (lw) */
};

extern "C" s32 func_00525310(struct func_00525310_obj *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    u32 a1 = arg1 & 0xFF;
    u32 a2 = arg2 & 0xFFFF;
    char *t;
    u32 off;
    u32 off4;
    s32 w;

    if (arg3 == 0) {
        return 2;
    }
    *arg3 = 0;
    if (arg0 == 0) {
        return 2;
    }
    if (a1 >= arg0->nBC) {
        return 2;
    }
    t = arg0->p88;
    if (t == 0) {
        return 3;
    }
    if (a2 >= (u32)arg0->n9C) {
        return 2;
    }
    off = a1 * 0x18;
    off4 = a2 * 4;
    w = *(s32 *)(off + (u32)t);
    off4 += (u32)w;
    if (*(s32 *)off4 != 0) {
        *arg3 = 1;
    }
    return 0;
}
