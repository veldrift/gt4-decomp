typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long s64;

struct Cfg { char pad[0x5B6]; u8 b5B6; };
struct C0 { char pad[0x18]; Cfg *p18; };
struct B8 { C0 *p0; };
struct A60 { char pad[8]; B8 *p8; };
struct S1 { char pad[0x60]; A60 *p60; char pad64[0xC]; void *p70; };
struct Arg1 { char pad[0x6C]; S1 *p6C; };
struct Arg1b { char pad[0xCC8]; s32 fCC8; };
struct Arg0 { char pad[0x4A4]; s32 f4A4; };
struct Rec { char pad[0x48]; s64 f48; };
struct G { char pad4[4]; };

extern char *D_00622F4C;
extern char D_0068D568[];

extern "C" s32 func_00110570(S1 *, s32);
extern "C" void func_00110898(Arg0 *, S1 *);
extern "C" void func_00114390(Arg0 *, Arg1 *);
extern "C" s32 func_0035E3F0(Cfg *);
extern "C" void RaceEntryBase__sortByRank(A60 *);
extern "C" u8 RaceOrganization__getScore(S1 *, s32);
extern "C" void func_0042F270(void *, s32, u8, u8, s32);
extern "C" void func_0042F448(void *, void *, s32, u8, u8, s32);
extern "C" s32 func_00430A20(void *, s32);
extern "C" void func_00430A58(void *, s32, u8);
extern "C" void *func_00430D20(void *, s32);
extern "C" void func_0043AFF0(void *, u32);
extern "C" s32 SPEC_DATABASE__RaceSpec__getRaceLabel(void *);
extern "C" s32 func_004475A8(void *, u32);
extern "C" s32 func_0057F238(s32, const char *);

extern "C" void func_00114498(Arg0 *arg0, Arg1 *arg1, u8 *arg2) {
    s32 flag = 0;
    S1 *s1;
    s32 name;
    char *g;
    char *s4, *s2;
    void *s7;
    s32 cc8 = ((Arg1b *)arg1)->fCC8;
    if (cc8 == 0 || cc8 == 2) flag = 1;
    s1 = arg1->p6C;
    name = SPEC_DATABASE__RaceSpec__getRaceLabel(s1->p70);
    g = D_00622F4C;
    s2 = g + 0x348;
    s7 = func_00430D20(g + 0x13E28, name);
    s4 = g + 0x568;
    if (s1->p60->p8->p0->p18->b5B6 == 0) {
        func_00110898(arg0, s1);
        func_0043AFF0(s2, 0);
        if (func_0057F238(name, D_0068D568) == 0) {
            return func_0042F448(s4, D_00622F4C + 4, 2, 0xF, 0xE, 0x157529FF);
        }
        return func_0042F270(s4, name, 0xF, 0xE, 0x157529FF);
    } else {
        A60 *a = s1->p60;
        s32 fp, s0, sp8;
        RaceEntryBase__sortByRank(a);
        fp = func_0035E3F0(s1->p60->p8->p0->p18);
        s0 = func_00110570(s1, 0);
        sp8 = func_004475A8(s1->p70, s0);
        func_0043AFF0(s2, s0 + 1);
        ((Rec *)s2)->f48 += sp8;
        if (flag) func_00430A20(s7, RaceOrganization__getScore(s1, 0));
        u8 c = s0;
        if (c < *arg2) {
            func_00430A58(s7, 2, c);
            *arg2 = c;
        }
        if (func_0057F238(name, D_0068D568) == 0) {
            func_0042F448(s4, D_00622F4C + 4, 2, c, 0xE, fp);
        } else {
            func_0042F270(s4, name, c, 0xE, fp);
        }
        arg0->f4A4 = sp8;
        func_00114390(arg0, arg1);
    }
}
