typedef int s32;

struct Out {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_00461E50(Out *arg0, s32 arg1);

extern "C" s32 func_00460BF0(void) {
    Out sp;
    func_00461E50(&sp, 0xC);
    return sp.unk4;
}
