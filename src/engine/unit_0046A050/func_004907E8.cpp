typedef short s16;
typedef unsigned short u16;
typedef int s32;

struct Tbl004907E8 {
    char pad0[0x12];
    u16 cnt;
    char pad1[0x4];
    char *base;
};

struct Obj004907E8 {
    char pad0[0xC];
    Tbl004907E8 *unkC;
    char pad1[0x1C];
    s32 unk2C;
};

extern "C" void func_00491EA8(void *arg0);

extern "C" void func_004907E8(struct Obj004907E8 *arg0) {
    Tbl004907E8 *t = arg0->unkC;

    if (t != 0) {
        s32 i = arg0->unk2C;
        s32 n = t->cnt;
        s32 idx = (i < n) ? i : n - 1;

        func_00491EA8(t->base + (idx << 6));
    }
}
