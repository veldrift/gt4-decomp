typedef int s32;

struct func_005061D8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

typedef s32 (*func_005061D8_fn)(s32, s32, s32);

extern "C" {
s32 func_00504AA8(void);                        /* extern */
s32 func_00504AB8(void);                        /* extern */
void func_0057D9C0(const char *fmt, ...);       /* extern */

extern s32 D_0064A150;
extern char D_006C1310[];

void func_005061D8(struct func_005061D8_arg0 *arg0) {
    s32 var_s2;
    s32 temp_s0;

    if (arg0->unk4 == 1) {
        var_s2 = 0;
        D_0064A150 = arg0->unk0;
    } else {
        var_s2 = -2;
        D_0064A150 = arg0->unk0;
        func_0057D9C0(D_006C1310, arg0->unkC, arg0->unk8);
    }
    if (func_00504AA8() != 0) {
        temp_s0 = func_00504AB8();
        ((func_005061D8_fn)func_00504AA8())(D_0064A150, var_s2, temp_s0);
    }
}
}
