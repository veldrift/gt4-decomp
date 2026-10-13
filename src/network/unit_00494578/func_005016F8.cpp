typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct List;
struct Node;
struct func_0057CB80_arg0;
struct func_0057CB80_arg1;

struct VEntry4 {
    s16 delta;
    s16 index;
    void (*fn)(char *, void *, s32, s32);
};

extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);
extern "C" void func_0057CB00(struct List *arg0, struct Node *arg1);
extern "C" void func_0057CB80(struct func_0057CB80_arg0 *arg0, struct func_0057CB80_arg1 *arg1);

extern "C" void func_005016F8(char *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    char **pp;
    char *var_s0;

    buf0[0] = (s32)(arg0 + 0x8);
    func_00576788(buf0[0]);
    pp = (char **)(arg0 + 0x1CC);
    if (arg3 != 0) {
        *(s32 *)(arg0 + 0xB4) = arg2;
        var_s0 = arg0 + 0xB8;
    } else {
        var_s0 = *pp;
        func_0057CB80((struct func_0057CB80_arg0 *)pp,
                      (struct func_0057CB80_arg1 *)var_s0);
    }
    {
        VEntry4 *e = (VEntry4 *)(*(char **)(var_s0 + 0x48) + 0x10);
        e->fn(var_s0 + e->delta, arg1, *(s32 *)(arg0 + 0xB0), arg2);
    }
    func_0057CB00((struct List *)(arg0 + 0x1D8), (struct Node *)var_s0);
    func_005767C0(buf0[0]);
}
