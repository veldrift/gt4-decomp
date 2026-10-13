typedef int s32;

struct Obj {
    char pad0[0x8C];
    s32 unk8C;
    s32 unk90;
};

extern char *D_00622F4C;

extern "C" s32 func_004395E8(void) {
    Obj *p = (Obj *)((char *)D_00622F4C + 0x39FF4);
    s32 v = p->unk90 - 1;
    s32 a = p->unk8C - 1;
    s32 r = (v == 0);

    if (a != 0) {
        r = 0;
    }
    return r;
}
