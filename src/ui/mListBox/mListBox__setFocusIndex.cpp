typedef int s32;

struct Obj {
    char pad0[0x108];
    s32 unk108;
    char pad10C[0x18];
    s32 idx;
    char pad128[4];
    s32 unk12C;
    char pad130[0x1C];
    s32 unk14C;
};

extern "C" s32 mListBox__getTotalItemCount(Obj *arg0) throw();
extern "C" void mListBox__setItemActive(void *list, s32 i, s32 on) throw();

extern "C" void mListBox__setFocusIndex(Obj *arg0, s32 arg1) {
    if (arg0->idx >= 0 && arg0->unk12C < 0) {
        mListBox__setItemActive(arg0, arg0->idx, 0);
    }
    arg0->idx = arg1;
    if (arg1 < 0) {
        if (mListBox__getTotalItemCount(arg0) > 0) {
            arg0->idx = 0;
        }
    } else {
        if (arg0->idx >= mListBox__getTotalItemCount(arg0)) {
            arg0->idx = mListBox__getTotalItemCount(arg0) - 1;
        }
    }
    arg0->unk14C = 1;
    if (arg0->idx >= 0 && arg0->unk12C < 0) {
        mListBox__setItemActive(arg0, arg0->idx, arg0->unk108);
    }
}
