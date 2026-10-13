typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(char *);
};

extern "C" s32 func_0034C190(s32 arg0, s32 arg1);
extern "C" int func_003F6320(void *o);
extern "C" void func_0035E6B0(s32 *arg0, void *arg1, s32 arg2, char **arg3);
extern "C" void func_0035E428(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

extern "C" void func_003F63A0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    char *s5 = (char *)func_0034C190((s32)arg0, arg1);
    u8 *a;
    char *q;
    char *v1;
    s32 k;

    if (func_003F6320(arg0) == 0) {
        return;
    }
    q = (char *)arg0 + 0x10000;
    v1 = *(char **)(q + 0x140) + 0x150;
    k = (arg2 - 1) * ((VEntry *)v1)->fn((char *)arg0 + ((VEntry *)v1)->delta) + arg3;
    if (k >= 0x10) {
        return;
    }
    a = (u8 *)((char *)arg0 + 0xF818);
    if (a[0x40] != 0) {
        if (a[2] != 6) {
            return;
        }
    }
    func_0035E6B0((s32 *)arg0, (void *)arg1, k, (char **)arg6);
    return func_0035E428(arg0, arg1, 1, k, arg5, arg6, (u8)s5[0x5B7]);
}
