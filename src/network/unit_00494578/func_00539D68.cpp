typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Obj00539D68 {
    char pad0[4];
    u32 unk4;
    u32 unk8;
    char pad1[4];
    s32 unk10;
};

extern "C" void func_00539D68(s32 arg0, struct Obj00539D68 *arg1, u8 *arg2) {
    if (arg1->unk10 == 0) {
        u32 end = arg1->unk4;
        u32 cur = arg1->unk8;
        if (!(cur < end) || cur == 0) {
            arg1->unk10 = 2;
            return;
        }
        if (end == cur) {
            arg1->unk10 = 8;
            return;
        }
        if (arg0 == 1) {
            *(u8 *)cur = *arg2;
            cur = arg1->unk8;
            arg1->unk8 = cur + 1;
        } else if (arg0 == 2) {
            *arg2 = *(u8 *)cur;
            cur = arg1->unk8;
            arg1->unk8 = cur + 1;
        } else {
            arg1->unk8 = cur + 1;
        }
    }
}
