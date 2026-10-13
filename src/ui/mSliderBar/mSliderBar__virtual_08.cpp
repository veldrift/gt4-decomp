typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" void func_00201700(void *arg0, void *arg1);
extern "C" void *func_005C0FC8(s32, s32, s32, void *, s32, void *);

extern char D_005EA490[];
extern char D_005EFF90[];

extern "C" void func_002E0190(void *arg0, void *arg1) {
    char *var_a3;
    char *temp_v0;
    char *src;
    char *dst;

    func_00201700(arg0, arg1);
    var_a3 = 0;
    if (arg1 != 0) {
        temp_v0 = *(char **)((char *)arg1 + 4);
        var_a3 = (char *)func_005C0FC8(*(s32 *)(temp_v0 + 4), (s32)D_005EA490, 0,
                                       (char *)arg1 + *(s16 *)temp_v0, (s32)D_005EFF90, arg1);
    }
    if (var_a3 != 0) {
        src = var_a3 + 0xCC;
        dst = (char *)arg0 + 0xCC;
        *(s32 *)((char *)arg0 + 0x104) = *(s32 *)(var_a3 + 0x104);
        *(s32 *)(dst + 0x0) = *(s32 *)(src + 0x0);
        *(s32 *)(dst + 0x4) = *(s32 *)(src + 0x4);
        *(s32 *)(dst + 0x8) = *(s32 *)(src + 0x8);
        *(s32 *)(dst + 0xC) = *(s32 *)(src + 0xC);
        *(s32 *)(dst + 0x10) = *(s32 *)(src + 0x10);
        *(s32 *)((char *)arg0 + 0xC0) = *(s32 *)(var_a3 + 0xC0);
        *(s32 *)((char *)arg0 + 0xE0) = *(s32 *)(var_a3 + 0xE0);
        *(s32 *)((char *)arg0 + 0xE4) = *(s32 *)(var_a3 + 0xE4);
        *(s32 *)((char *)arg0 + 0xE8) = *(s32 *)(var_a3 + 0xE8);
    }
}
