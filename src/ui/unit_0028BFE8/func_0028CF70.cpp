typedef int s32;
typedef unsigned int u32;

struct Str { char *p; char pad[0xC]; };

extern char D_0069B040[];

extern "C" void func_004AE230(void *a, char *b, s32 c);
extern "C" void func_002ED5C0(void *a, s32 b);
extern "C" void *func_002EFCE0(void *a, s32 b);
extern "C" void func_002FC8C8(void *a, void *b);
extern "C" s32 func_002FE250(void *a);
extern "C" void func_002FC870(void *a, s32 b);
extern "C" s32 func_0032EE60(void *a, s32 b, void *c, s32 d, s32 e, s32 f);
extern "C" void func_00575DA0(s32 a);

extern "C" s32 func_0028CF70(char *arg0, void **arg1, void *arg2, s32 arg3, s32 arg4) {
    s32 tab[8];
    char arr[8];
    Str s;
    char *str;
    s32 val;
    s32 i;
    s32 res;

    char *p = (char *)*arg1;
    s32 len = *(s32 *)(p - 0x10);
    if (len == 0) {
        str = D_0069B040;
    } else {
        p[len] = 0;
        str = (char *)*arg1;
    }
    func_004AE230(tab, str, 1);
    val = tab[4];
    if (tab[0] != 0) {
        func_002ED5C0(arg2, 2);
        return 0;
    }
    i = 0;
    char *pa = arr;
    Str *ps = &s;
    for (; i < 8; i++) {
        func_002FC8C8(ps, func_002EFCE0(arg2, i));
        pa[i] = func_002FE250(ps->p);
        func_002FC870(ps, 2);
    }
    res = func_0032EE60(arg0 + 0x10, val, pa, arg3, arg4, *(s32 *)(arg0 + 0x34));
    func_00575DA0(val);
    func_002ED5C0(arg2, 2);
    return res;
}
