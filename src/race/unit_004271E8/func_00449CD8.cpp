/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;

struct Ent_00449CD8 {
    u32 unk0;
    u32 unk4;
};

struct Tab_00449CD8 {
    char pad0[4];
    u32 count;
};

struct Self_00449CD8 {
    struct Tab_00449CD8 *unk0;
};

extern "C" char * func_00449CD8(struct Self_00449CD8 *arg0, u32 arg1) {
    struct Tab_00449CD8 *t = arg0->unk0;
    if (arg1 >= t->count) {
        return 0;
    }
    struct Ent_00449CD8 *tab = (struct Ent_00449CD8 *)((char *)t + 0x10);
    char *base = (char *)tab + (t->count * 4);
    char *e = (char *)tab + (arg1 * 4);
    return base + *(u32 *)(char *)e + 2;
}
