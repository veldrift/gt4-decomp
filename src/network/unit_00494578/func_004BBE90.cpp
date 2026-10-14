/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct G {
    char pad0[0x24];
    unsigned char *unk24;
    void *unk28;
    s32 *unk2C;
    s32 unk30;
    char pad34[4];
    s32 *unk38;
    char *unk3C;
};
extern G *D_006452D4;
extern "C" void func_004BC098(void);
extern "C" void func_004BC6E8(G *);
extern "C" void func_004C3A48(G *);
extern "C" void *func_004C3E98(unsigned char *, int, u32);
extern "C" void func_004C3F90(void *, s32);
extern "C" void func_004C4BB8(s32);
extern "C" s32 func_004BBE90(u32 arg0) {
    s32 ret = 0x80000449;
    s32 ok = arg0 < 2;
    if (ok) {
        s32 i;
        func_004C4BB8(ok);
        func_004C3A48(D_006452D4);
        func_004BC6E8(D_006452D4);
        D_006452D4->unk30 = 0;
        *D_006452D4->unk2C = 0;
        func_004C3F90(D_006452D4->unk28, 4);
        for (i = 0; i < 6; i++) D_006452D4->unk3C[i] = 0;
        func_004BC098();
        *D_006452D4->unk38 = 0;
        func_004C3E98(D_006452D4->unk24, 0, 0xB4);
        ret = 0;
    }
    return ret;
}
