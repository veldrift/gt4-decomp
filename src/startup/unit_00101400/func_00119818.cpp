typedef int s32;

extern "C" char *D_00622F4C;
extern "C" void *func_00441248(void *arg0);
extern "C" void func_003EF310(void *arg0, void *arg1);

extern "C" void func_00119818(void *arg0) {
    char *p = D_00622F4C + 0x13938;
    s32 same = *(long long *)func_00441248(p) == -1;
    if (!same) {
        func_003EF310(arg0, func_00441248(p));
    }
}
