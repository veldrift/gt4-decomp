typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x50];
    s32 unk50;
    char pad54[0xBC - 0x54];
    f32 unkBC;
};

struct Src {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

struct Sub {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

extern "C" s32 RaceDisplay__is_play_mode(Obj *arg0);
extern "C" void func_003A3AA8(s32 arg0, f32 fparg0);
extern "C" s32 func_003A4A78(void *arg0);
extern "C" void func_003AE538(char *arg0, f32 fparg0, f32 fparg1);

extern "C" void RaceDisplay__virtual_23(Obj *arg0, Src *arg1) {
    s32 temp_s1;
    Sub *temp_v1;
    s32 r2;

    if (RaceDisplay__is_play_mode(arg0) == 0) {
        temp_s1 = arg1->unk8;
        if (temp_s1 != arg0->unk50) {
            func_003A3AA8((s32)((char *)arg0 + 0x1170), 0x1.6p3f);
            if (!(arg0->unkBC < 0x1.0p0f) && (func_003A4A78((char *)arg0 + 0x23DC) == 0)) {
                r2 = func_003A4A78((char *)arg0 + 0x291C);
                temp_v1 = (Sub *)((char *)arg0 + 0x3EEC);
                if (r2 == 0) {
                    arg0->unk50 = temp_s1;
                    temp_v1->unk18 = temp_s1;
                    temp_v1->unk1C = arg1->unkC;
                    func_003AE538((char *)temp_v1, 0x1.4p3f, 0x1.0p-1f);
                }
            }
        }
    }
}
