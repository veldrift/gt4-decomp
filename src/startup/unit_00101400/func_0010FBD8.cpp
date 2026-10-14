/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad0[4];
    char name[0x40];
    char code[0x20];
};

extern Obj *D_00622F4C;

extern "C" s32 QUICK_MENU__GetNextLicenseCode(const char *, char *);
extern "C" s32 func_00114E38(void);
extern "C" s32 func_0011CB38(void);
extern "C" s32 RaceBase__getLicenseSubNumber(const char *);
extern "C" s32 RaceBase__getLicenseSubMode(const char *);
extern "C" void func_0043A220(char *, char *);

extern "C" void func_0010FBD8(void) {
    char buf[0x10];
    for (;;) {
        const char *code = D_00622F4C->code;
        s32 flag = 0;
        s32 n = RaceBase__getLicenseSubNumber(code);
        if (RaceBase__getLicenseSubMode(code) - 4 < 4u) {
            if (n == 5 || n == 10 || n == 15) {
                flag = 1;
            }
        }
        s32 r;
        if (flag) {
            r = func_00114E38();
        } else {
            r = func_0011CB38();
        }
        if (r != 0 && QUICK_MENU__GetNextLicenseCode(code, buf) != 0) {
            func_0043A220(D_00622F4C->name, buf);
            continue;
        }
        break;
    }
}
