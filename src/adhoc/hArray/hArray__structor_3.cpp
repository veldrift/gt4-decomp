/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

extern char hArray__vtable[];

extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" int hObject__structor_0(void *arg0);
extern "C" void *func_0030BB18(void *arg0);
extern "C" void *func_00326750(u32 size, s32 align, const char *name);
extern "C" void *HObject__tf(void);
extern "C" s32 func_005D84B0(s32 arg0, s32 arg1, void *arg2, s32 arg3);

extern "C" void hArray__structor_3(char *arg0, s32 arg1) {
    char *s0;
    s32 sp[12];

    s32 temp_s1;
    void *temp_v0;

    hObject__structor_0(arg0);
    s0 = arg0 + 0x10;
    temp_s1 = arg1 * 4;
    *(void **)(arg0 + 4) = hArray__vtable;
    *(s32 *)(s0 + 4) = 0;
    *(s32 *)(s0 + 8) = 0;
    *(s32 *)(s0 + 0xC) = 0;
    temp_v0 = func_00326750(temp_s1, 4, *(const char **)HObject__tf());
    *(char **)(s0 + 0xC) = (char *)temp_v0 + temp_s1;
    *(void **)(s0 + 4) = temp_v0;
    *(void **)(s0 + 8) = temp_v0;
    sp[4] = (s32)temp_v0;
    func_0030BB18(&sp[8]);
    *(s32 *)(s0 + 8) = func_005D84B0(sp[4], arg1, &sp[8], 0);
    func_00309378(&sp[8], 2);
    *(s32 *)(arg0 + 0x20) = 0;
}
