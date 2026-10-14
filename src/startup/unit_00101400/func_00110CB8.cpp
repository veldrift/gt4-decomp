typedef int s32;
struct E { char pad0[0x14]; unsigned char b14; };
struct Obj2 { char pad0[0x70]; void *f70; };
struct Self { char pad0[0x494]; s32 f494; };

extern "C" long SPEC_DATABASE__RaceSpec__getCourseCode(void *a0);
extern "C" s32 SPEC_DATABASE__RaceSpec__getCourseType(void *a0);
extern "C" int func_00447F48(unsigned long key, E *out);

extern "C" void func_00110CB8(Self *arg0, Obj2 *arg1) {
    s32 s0 = (SPEC_DATABASE__RaceSpec__getCourseType(arg1->f70) == 0);
    E e;
    func_00447F48(SPEC_DATABASE__RaceSpec__getCourseCode(arg1->f70), &e);
    arg0->f494 = (e.b14 == 0) ? 0 : s0;
}
