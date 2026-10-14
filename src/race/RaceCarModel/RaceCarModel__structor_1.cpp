typedef int s32;

extern "C" void RaceCarModel__virtual_01(s32 *arg0);
extern "C" void RaceDriverModel__structor_1(void *arg0, s32 arg1);
extern "C" void func_004574A0(void *arg0, s32 arg1);
extern "C" void func_005C1628(char *arg0);

extern char RaceCarModel__vtable[];
extern char RaceCrewModel__vtable[];
extern char D_006885F0[];
extern char D_00688628[];
extern char VehicleModel__vtable[];

struct func_0038F9B8_a {
    char pad0[8];
    s32 unk8;
};

struct func_0038F9B8_b {
    s32 unk0;
};

struct func_0038F9B8_c {
    char pad0[0x7DC];
    s32 unk7DC;
};

extern "C" void RaceCarModel__structor_1(char *arg0, s32 arg1) {
    char *temp;
    struct func_0038F9B8_b *tb;

    ((struct func_0038F9B8_a *)arg0)->unk8 = (s32)RaceCarModel__vtable;
    RaceCarModel__virtual_01((s32 *)arg0);
    temp = arg0 + 0xE20;
    ((struct func_0038F9B8_c *)temp)->unk7DC = (s32)RaceCrewModel__vtable;
    RaceDriverModel__structor_1(temp, 0);
    RaceDriverModel__structor_1(arg0 + 0x5E0, 2);
    tb = (struct func_0038F9B8_b *)(arg0 + 0x24);
    tb->unk0 = (s32)D_006885F0;
    func_004574A0(tb, 0);
    tb = (struct func_0038F9B8_b *)(arg0 + 0x1C);
    tb->unk0 = (s32)D_00688628;
    func_004574A0(tb, 0);
    ((struct func_0038F9B8_a *)arg0)->unk8 = (s32)VehicleModel__vtable;
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
