typedef int s32;

extern "C" void func_0057D9C0(const char *fmt, ...);

extern void *D_0064A55C;
extern s32 D_0064A560;
extern char D_006C2200[];

struct func_0050F960_obj {
    char pad0[0xC];
    void (*unkC)(void *, void *);
    char pad1[0xC];
    void (*unk1C)(void *, s32);
    char pad2[4];
    s32 (*unk24)(void *, s32, void *);
};

extern "C" s32 func_0050F960(s32 arg0) {
    s32 sp[8];
    s32 result;

    result = ((struct func_0050F960_obj *)D_0064A55C)->unk24(D_0064A55C, arg0, &sp[4]);
    if (result != 0) {
        func_0057D9C0(D_006C2200, result);
        return -13;
    }
    ((struct func_0050F960_obj *)D_0064A55C)->unk1C(D_0064A55C, arg0);
    ((struct func_0050F960_obj *)D_0064A55C)->unkC(D_0064A55C, sp);
    D_0064A560 = sp[0];
    return 0;
}
