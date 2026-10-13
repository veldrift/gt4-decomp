typedef int s32;

extern char D_00688990[];

struct Buf {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0C[0x14];
    void *unk20;
};

extern "C" void func_004720B8(struct Buf *b);

extern "C" void func_00472028(struct Buf *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk20 = D_00688990;
    arg0->unk8 = 0;
    return func_004720B8(arg0);
}
