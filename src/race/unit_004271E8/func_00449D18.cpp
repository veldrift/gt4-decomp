typedef unsigned int u32;
typedef unsigned short u16;

struct Ent_00449D18 {
    u32 unk0;
    u32 unk4;
};

struct Tab_00449D18 {
    char pad0[4];
    u32 count;
};

struct Self_00449D18 {
    struct Tab_00449D18 *unk0;
};

extern "C" u16 func_00449D18(struct Self_00449D18 *arg0, u32 arg1) {
    struct Tab_00449D18 *t = arg0->unk0;
    if (arg1 >= t->count) {
        return 0;
    }
    struct Ent_00449D18 *tab = (struct Ent_00449D18 *)((char *)t + 0x10);
    char *base = (char *)tab + (t->count * 4);
    char *e = (char *)tab + (arg1 * 4);
    return *(u16 *)(base + *(u32 *)(char *)e);
}
