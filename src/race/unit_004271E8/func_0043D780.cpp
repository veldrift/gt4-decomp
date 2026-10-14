typedef int s32;
typedef unsigned int u32;

extern char D_006A5E10[];
extern char D_006A5E20[];
extern "C" int func_0057F238(void *a, const char *b);
extern "C" void func_0043C160(char *a, s32 b, s32 c);
extern "C" void func_0043C5F8(char *a, s32 b, s32 c);
extern "C" void func_0043C8E0(char *a, s32 b, s32 c);
extern "C" void func_0043CBF8(s32 a, u32 b, s32 c);

extern "C" void func_0043D780(char *self, s32 arg1, s32 arg2) {
    if (func_0057F238((void *)arg1, D_006A5E10) == 0) {
        return func_0043C160(self + 0x18, 0, arg2);
    }
    if (func_0057F238((void *)arg1, D_006A5E20) == 0) {
        func_0043C5F8(self + 0x48, 0, arg2);
        func_0043C8E0(self + 0x64, 0, arg2);
        return func_0043CBF8((s32)(self + 0x8C), 0, arg2);
    }
}
