struct VObj {
    char pad0[0x6C];
    void (*fn)(char *);
};

struct Ctx {
    char pad0[0x68];
    int f68;
};

extern VObj *D_0064B4B0;
extern Ctx *D_0064B47C;

extern "C" int func_00536B40();
extern "C" void func_005325C8(int arg0, char *arg1, int arg2, int arg3, int arg4);

extern "C" void func_00532FF8(char *arg0, int arg1, int arg2, int arg3)
{
    if (arg3 != 0) {
        D_0064B4B0->fn((char *)D_0064B47C + 0x60);
        D_0064B47C->f68 = 0;
        return func_005325C8(func_00536B40(), arg0, arg1, arg2, arg3);
    }
}
