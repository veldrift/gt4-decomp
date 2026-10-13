typedef unsigned char u8;
typedef int s32;

struct Obj {
    u8 *unk0;
};

extern "C" s32 func_0057AB48(struct Obj *arg0) {
    u8 *p = arg0->unk0 + 0xC;
    return (p[0] | (p[1] << 8) | (p[2] << 16)) | (p[3] << 24);
}
