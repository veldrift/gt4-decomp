extern "C" int func_00462998(void *holder);
extern "C" void func_00462738(void *holder, void *str, void *zero);
extern "C" void func_00462798(int value);
extern "C" void func_004627B0(void *buf, int size);
extern "C" void func_00462900(void *holder);
extern "C" char D_0084862C[];
extern "C" char D_00846980[];
extern "C" char D_006AB850[];

extern "C" void func_00462E18(void)
{
    void *h = D_0084862C;

    if (func_00462998(h) == 0) {
        func_004627B0(D_00846980, 0x800);
        func_00462798(0x18D000);
        func_00462738(h, D_006AB850, 0);
        func_00462900(h);
    }
}
