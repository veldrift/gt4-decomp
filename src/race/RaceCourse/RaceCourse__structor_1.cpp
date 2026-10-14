typedef int s32;

extern "C" void RaceCourse__clearData(char *arg0);
extern "C" void PitmenData__structor_1(char *arg0, s32 arg1);
extern "C" void func_004072F0(char *arg0, s32 arg1);
extern "C" void func_004574A0(void *arg0, s32 arg1);
extern "C" void func_005C1628(char *arg0);

extern char RaceCourse__vtable[];
extern char D_0067E1F0[];

struct func_00394CB0_a {
    char pad0[0xB8];
    s32 unkB8;
};

struct func_00394CB0_b {
    s32 unk0;
};

void RaceCourse__structor_1(char *arg0, s32 arg1) {
    struct func_00394CB0_b *temp;

    ((struct func_00394CB0_a *)arg0)->unkB8 = (s32)RaceCourse__vtable;
    RaceCourse__clearData(arg0);
    temp = (struct func_00394CB0_b *)(arg0 + 0x94);
    temp->unk0 = (s32)D_0067E1F0;
    func_004574A0(temp, 0);
    func_004072F0(arg0 + 0x8C, 2);
    PitmenData__structor_1(arg0 + 0x1C, 2);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
