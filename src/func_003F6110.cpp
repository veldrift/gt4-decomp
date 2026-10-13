typedef int s32;
typedef unsigned char u8;

struct Obj {
    u8 unk0;
    u8 unk1;
    u8 unk2;
};

extern "C" s32 func_003F6110(s32 arg0) {
    struct Obj *p = (struct Obj *)(arg0 + 0xF818);
    if (p->unk2 != 3) {
        return 0;
    }
    return p->unk1 != 1;
}
