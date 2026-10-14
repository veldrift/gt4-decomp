/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Mid { char pad[0x70]; void *f70; };
struct Self { char pad[0x6C]; Mid *mid; };
extern char *D_00622F4C;
extern "C" void func_0042F198(char *);
extern "C" void func_0042F2E0(char *, const char *, u8, u8, s32);
extern "C" const char *SPEC_DATABASE__RaceSpec__getRaceLabel(void *);

extern "C" void func_00110800(Self *arg0, s32 *arg1, s32 *arg2) {
    Mid *mid = arg0->mid;
    if (*arg1 != 0xD) {
        char *g = D_00622F4C;
        return func_0042F2E0(g + 0x568, SPEC_DATABASE__RaceSpec__getRaceLabel(mid->f70), *(u8 *)arg1, 0xE, *arg2);
    }
    func_0042F198(D_00622F4C + 0x568);
}
