typedef int s32;

struct func_0050F270_obj {
    char pad0[0xC];
    void (*unkC)(void *, void *);
    char pad1[0xC];
    void (*unk1C)(void *, s32);
    char pad2[4];
    s32 (*unk24)(void *, s32, void *);
};

extern "C" void func_0057D9C0(const char *fmt, ...);

extern char D_0064A550[];
extern char D_006C2078[];
extern s32 D_0064A554;

extern "C" s32 func_0050F270(s32 arg0) {
    s32 sp[8];
    s32 temp_v0;
    void **g = (void **)D_0064A550;

    temp_v0 = ((struct func_0050F270_obj *)*g)->unk24(*g, arg0, &sp[4]);
    if (temp_v0 != 0) {
        func_0057D9C0(D_006C2078, temp_v0);
        return -0xD;
    }
    ((struct func_0050F270_obj *)*g)->unk1C(*g, arg0);
    ((struct func_0050F270_obj *)*g)->unkC(*g, &sp[0]);
    D_0064A554 = sp[0];
    return 0;
}
