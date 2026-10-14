typedef int s32;
extern char *D_00622F4C;
extern "C" void func_003BB440(s32, char *);
extern "C" long *func_00441248(char *);
extern "C" void func_004452F8(s32, void *);

extern "C" void func_00115F58(s32 arg0) {
    func_003BB440(arg0, D_00622F4C + 0x44);
    s32 sub = arg0 + 0x130;
    char *g = D_00622F4C + 0x13938;
    s32 f = (~*func_00441248(g) == 0);
    if (f == 0) {
        func_004452F8(sub, func_00441248(g));
    }
}
