typedef int s32;
typedef signed char s8;

extern char D_00645570[];

struct Rec001F6EF0 {
    char pad0[0x39];
    char text[0x40];
};

extern "C" char *func_004FA008(char *arg0);
extern "C" void func_004FA048(char *arg0, char *arg1);
extern "C" void func_005A609C(void *arg0, char *arg1);

extern "C" void func_001F6EF0(void *unused, char *arg1, s32 arg2) {
    char *base = D_00645570;
    char *s1 = func_004FA008(base);
    if (s1 != 0) {
        func_005A609C(s1 + 0x39, arg1);
        s1[0x79] = arg2;
    }
    func_004FA048(base, s1);
}
