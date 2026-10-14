/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;
struct G {
    char pad0[0x30];
    char b30, b31, b32, b33, b34, b35;
    char pad36[4];
    char name[0x100];
    s32 f13C;
    char b140;
};
extern char D_0086C8D8[];
extern G D_0086C8E0;
extern "C" void func_00574EE8(void *);
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" char *func_005A609C(char *, const char *);
struct Guard {
    void *p;
    Guard(void *q) : p(q) { func_00576100(q); }
    ~Guard() { func_00576140(p); }
};
extern "C" void func_00547860(const char *name, s32 arg1, s32 arg2) {
    {
        Guard g(D_0086C8D8);
        D_0086C8E0.f13C = arg2;
        D_0086C8E0.b30 = 1;
        D_0086C8E0.b31 = 1;
        D_0086C8E0.b32 = 0;
        D_0086C8E0.b33 = 0;
        D_0086C8E0.b34 = 0;
        D_0086C8E0.b35 = 0;
        func_005A609C(D_0086C8E0.name, name);
        D_0086C8E0.b140 = arg1;
    }
    func_00574EE8(&D_0086C8E0);
}
