typedef int s32;

struct Obj_00460388 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

extern "C" void func_00460388(Obj_00460388 *arg0, s32 arg1, s32 arg2) {
    s32 *p4 = &arg0->unk4;
    s32 *p8 = &arg0->unk8;
    s32 *pC = &arg0->unkC;
    s32 *p10 = &arg0->unk10;

    arg0->unk0 = arg0->unk0 + arg1;
    *p4 = *p4 + arg1;
    *p8 = *p8 + arg1;
    *pC = *pC + arg1;
    *p10 = *p10 + arg1;
    if (arg2 != 0) {
        arg0->unk14 = arg0->unk14 + arg1;
    }
}
