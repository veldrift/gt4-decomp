/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern char D_0067FC58[];
extern "C" int func_00105250(void *);
extern "C" void func_003B8270(void *, float, float, float, float, float, float, float, float, float, float, float, float);
extern "C" void func_003B82D0(void *, s32, float, float, float, float, float, float, float, float, float, float, float, float, float);
extern "C" void func_004969B0(void);
extern "C" void func_00496C38(void);

extern "C" void func_003B7F10(char *arg0) {
    s32 i = 0;
    *(s32 *)(arg0 + 0x7C) = 0;
    *(s32 *)(arg0 + 0x80) = 0;
    *(s32 *)(arg0 + 0x84) = 0;
    *(char **)(arg0 + 0x2428) = D_0067FC58;
    *(s32 *)(arg0 + 0x88) = 0;
    func_00105250(arg0 + 0x8C);
    func_00105250(arg0 + 0xC8);
    s32 al = (s32)(arg0 + 0x147);
    al &= ~0x3F;
    *(s32 *)(arg0 + 0x104) = al;
    func_004969B0();
    func_00496C38();
    **(s32 **)(arg0 + 0x104) = 0;
    *(s32 *)(arg0 + 0xA28) = 0;
    *(s32 *)(arg0 + 0xA2C) = 0;
    func_003B8270(arg0, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1000.0f, 0.0f, 1.0f);
    s32 *p = (s32 *)(arg0 + 0x2260);
    do {
        s32 a1 = i;
        i++;
        func_003B82D0(arg0, a1, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1000.0f, 0.0f, 0.0f);
        *p = 0;
        p += 0x3C / 4;
    } while (i < 8);
}
