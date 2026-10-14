typedef int s32;
typedef unsigned char u8;
struct RacePanel {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    union { s32 unk1C; u8 b[8]; };
    s32 unk24;
    s32 unk28;
};
extern char RacePanel__vtable[];
extern "C" s32 RaceDisplayObjectBase__structor_0(void *);
extern "C" void RacePanel__structor_1(struct RacePanel *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    arg0->unk14 = (s32)RacePanel__vtable;
    arg0->unk18 = 0;
    arg0->unk1C = arg0->unk1C & ~0xFF;
    arg0->b[1] = 0;
    arg0->b[2] = 0;
    arg0->b[3] = 0;
    arg0->b[4] = 0;
    arg0->b[5] = 0;
    arg0->b[6] = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
}
