typedef int s32;
typedef unsigned int u32;

struct Struct_0057B5C8 {
    char pad0[4];
    u32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u32 unk14;
};

extern "C" s32 func_0057B5C8(struct Struct_0057B5C8 *r, s32 n) {
    u32 p = r->unk4 + n;
    u32 s = r->unk14;
    if (p >= s) {
        p -= s;
    }
    return r->unkC + ((s32)p * r->unk10);
}
