typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

struct Obj {
    char pad0[0x84];
    char *p84;        /* 0x84: entry table base */
    char pad1[0x9C - 0x88];
    u16 n9C;          /* 0x9C: entry count (lhu) */
};

extern "C" s32 func_00523BB0(Obj *arg0, s32 arg1, s32 *arg2) {
    u32 idx = (u16)arg1;
    *arg2 = -1;
    if (arg0 == 0)
        return 2;
    if (idx >= arg0->n9C)
        return 0xD4E6;
    u32 off = idx * 0x44;
    s32 *e = (s32 *)(off + (u32)arg0->p84);
    if (e[1] != 0) {
        *arg2 = 0;
    } else {
        if (e[2] != 0)
            *arg2 = 1;
    }
    return 0;
}
