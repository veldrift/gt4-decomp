typedef unsigned char u8;
typedef short s16;
typedef int s32;

struct Sub {
    char pad0[0x43];
    u8 b43;
};

struct Obj {
    s32 m0;
    s32 m4;
    s32 m8;
    char pad0C[0x70 - 0x0C];
    struct Sub *m70;
    char pad74[0xC4 - 0x74];
    s32 mC4;
};

extern "C" s32 D_00622F4C;

extern "C" void func_0010F7D8(struct Obj *arg0) {
    s32 *pg = &D_00622F4C;
    s32 v;

    v = *(s32 *)((char *)*pg + 0x39D70);
    if (v < 0) {
        v = arg0->m70->b43;
    }
    arg0->m0 = v;
    arg0->mC4 = *(s16 *)((char *)*pg + 0x3A344);
    arg0->m8 = *(s32 *)((char *)*pg + 0x39D74);
    arg0->m4 = *(s32 *)((char *)*pg + 0x39D94);
}
