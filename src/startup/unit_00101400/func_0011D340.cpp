typedef int s32;
struct Spec { char pad[0x75]; unsigned char f75; };
struct Inner { char pad[0x70]; s32 spec; };
struct Src { char pad[0x6C]; s32 inner; };
#define SPEC(a) ((Spec *)((Inner *)(a)->inner)->spec)
struct Dst {
    char pad[0x3C8]; char name[0x40]; char name2[0x40]; s32 f448; s32 f44C; s32 f450;
    char pad2[0x46C - 0x454]; s32 f46C; s32 f470; s32 f474;
    char pad3[0x4B0 - 0x478]; s32 f4B0; s32 f4B4;
};
extern char *D_00622F4C;
extern "C" void func_0011D400(Dst *, Src *);
extern "C" char *func_004472A0(Spec *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getBronzeTime(Spec *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getGoldTime(Spec *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getSilverTime(Spec *);
extern "C" char *func_005A609C(char *, const char *);

extern "C" void func_0011D340(Dst *arg0, Src *arg1) {
    arg0->f470 = 1;
    arg0->f46C = 0;
    arg0->f474 = 0;
    arg0->f4B0 = 0;
    arg0->f4B4 = 0;
    if (SPEC(arg1)->f75 != 0) {
        arg0->f470 = 0;
    }
    func_005A609C(arg0->name, D_00622F4C + 0x46);
    func_005A609C(arg0->name2, func_004472A0(SPEC(arg1)));
    arg0->f448 = SPEC_DATABASE__RaceSpec__getBronzeTime(SPEC(arg1));
    arg0->f44C = SPEC_DATABASE__RaceSpec__getGoldTime(SPEC(arg1));
    arg0->f450 = SPEC_DATABASE__RaceSpec__getSilverTime(SPEC(arg1));
    func_0011D400(arg0, arg1);
}
