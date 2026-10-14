typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_0015F3E0(void *arg0, void *arg1);
extern "C" void func_0015F388(void *arg0, int arg1);

extern "C" void MGame__abandonRace(void *arg0, void *arg1) {
    s32 sp0[4];
    Obj *o;
    char *s;

    func_0015F3E0(sp0, arg1);
    o = (Obj *)sp0[0];
    s = (char *)(0x38BF8 + o->unk10);
    func_0015F388(sp0, 2);
    if (s[0x28] != 0) {
        s[0x28] = 0;
    }
}
