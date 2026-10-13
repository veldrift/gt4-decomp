typedef int s32;

extern char D_00622E00;
extern char D_00687C60;

struct func_004383B0_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" void func_004383B0(struct func_004383B0_arg0 *arg0) {
    s32 hi = (s32)&D_00687C60;
    s32 lo = (s32)&D_00622E00;
    arg0->unk0 = lo;
    arg0->unkC = hi;
    arg0->unk4 = lo;
    arg0->unk8 = lo;
}
