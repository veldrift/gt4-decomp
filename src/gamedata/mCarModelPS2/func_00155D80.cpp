/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Sub {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
};
struct Arg1 {
    char pad0[0x4C];
    Sub *unk4C;
    char pad50[0x84 - 0x50];
    s32 unk84;
};
extern "C" s32 func_001564D8(void *);
extern "C" void *func_00450B20(void *, s32, s32);
extern "C" void func_00454410(void *);
extern "C" void func_004AFD50(void *);
extern "C" void free(s32) throw();
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void *func_005A4724(void *, void *, s32);
extern "C" void func_005ADF20(s32);

extern "C" void func_00155D80(char *arg0, Arg1 *arg1, u32 arg2) {
    char *s5 = arg0 + 0xEC;
    func_00576788(s5);
    *(s32 *)(arg0 + 0x150) = 0;
    Sub *sub = arg1->unk4C;
    if (arg1->unk84 == 0) {
        s32 n = sub->unk34;
        s32 p = sub->unk30;
        void *o = func_00450B20(arg0 + 0x2A4, arg2 == 0, n);
        func_005A4724(o, (void *)p, n);
        free(p);
        func_00454410(o);
        func_005ADF20(0);
        *(s32 *)(arg0 + arg2 * 4 + 0x1C8) = 1;
        if (*(s32 *)(arg0 + 0x1D8) != 0) {
            func_001564D8(arg0);
        }
    } else {
        func_004AFD50(sub);
    }
    func_005767C0(s5);
}
