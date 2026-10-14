typedef int s32;
typedef unsigned char u8;

struct Obj00373DD8 {
    u8 pad[0x9BC];
    s32 unk9BC;
};

extern "C" s32 func_003FC598(void *arg0, s32 arg1);

extern "C" s32 DevelopCamera__virtual_44(struct Obj00373DD8 *arg0, s32 arg1) {
    s32 temp_a2 = arg0->unk9BC * 0x19C;
    return func_003FC598((void *)(temp_a2 + (s32)arg0 + 0x10), arg1);
}
