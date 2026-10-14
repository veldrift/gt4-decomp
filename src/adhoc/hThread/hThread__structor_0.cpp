/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

extern char hThread__vtable[];
extern char D_0069E280[];

extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" int hObject__structor_0(void *arg0);
extern "C" void *func_0030BB18(void *arg0);
extern "C" void *func_00326750(u32 size, s32 align, const char *name);
extern "C" const char **HObject__tf(void);
extern "C" s32 func_005D84B0(s32 arg0, s32 arg1, void *arg2, s32 arg3);
extern "C" void func_005A48D8(void *arg0, s32 arg1, s32 arg2);

extern "C" void hThread__structor_0(char *arg0) {
    s32 sp[12];
    char *s0;
    char *s1;
    char *e;
    char *v;
    char *w;

    hObject__structor_0(arg0);
    *(void **)(arg0 + 4) = hThread__vtable;
    e = arg0 + 0x10;
    *(s32 *)(e + 4) = 0;
    *(s32 *)(e + 8) = 0;
    *(s32 *)(e + 0xC) = 0;
    *(s32 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x28) = 0;
    s0 = (char *)func_00326750(0x24, 4, D_0069E280);
    *(s32 *)(s0 + 4) = 0;
    s1 = s0 + 0x10;
    *(s32 *)(s0 + 8) = 0;
    *(s32 *)(s0 + 0xC) = 0;
    v = (char *)func_00326750(0, 4, *HObject__tf());
    *(char **)(s0 + 4) = v;
    *(char **)(s0 + 8) = v;
    *(char **)(s0 + 0xC) = v;
    sp[4] = (s32)v;
    func_0030BB18(&sp[8]);
    *(s32 *)(s0 + 8) = func_005D84B0(sp[4], 0, &sp[8], 0);
    func_00309378(&sp[8], 2);
    *(s32 *)(s1 + 4) = 0;
    *(s32 *)(s1 + 8) = 0;
    *(s32 *)(s1 + 0xC) = 0;
    w = (char *)func_00326750(4, 4, *HObject__tf());
    *(char **)(s1 + 4) = w;
    *(char **)(s1 + 0xC) = w + 4;
    *(char **)(s1 + 8) = w;
    sp[4] = (s32)w;
    func_0030BB18(&sp[8]);
    *(s32 *)(s1 + 8) = func_005D84B0(sp[4], 1, &sp[8], 0);
    func_00309378(&sp[8], 2);
    *(s32 *)(s0 + 0x20) = 0;
    *(char **)(arg0 + 0x2C) = s0;
    func_0030BB18(arg0 + 0x30);
    *(s32 *)(arg0 + 0x34) = 0;
    *(s32 *)(arg0 + 0x48) = 0;
    func_005A48D8(arg0 + 0x38, 0, 0x10);
}
