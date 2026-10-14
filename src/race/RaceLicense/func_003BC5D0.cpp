/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
extern "C" s32 func_0034C190(void *, s32);
extern "C" void func_003E7410(void *);
extern "C" u32 func_003ED9D0();
extern "C" u32 func_003ED9E0();
extern "C" s32 func_003ED9F0();
extern "C" void func_004080D8(void *, const char *, s32, s32);
extern "C" s32 LicenseConcourse__init(void *, void *, void *);
extern char D_006A2780[];
extern "C" void func_003BC5D0(char *arg0) {
    u32 temp_s0;
    char *temp_s0_2;
    char *temp_v1;
    temp_s0 = func_003ED9E0();
    if (func_003ED9D0() < temp_s0) {
        temp_v1 = *(char **)(arg0 + 0x70);
        if (*(s32 *)(temp_v1 + 0xF8A0) < 2) {
            temp_s0_2 = arg0 + 0x24E5C;
            func_0034C190(temp_v1, 0);
            if (*(s32 *)temp_s0_2 == 0) {
                func_004080D8(temp_s0_2, D_006A2780, func_003ED9F0(), 0x96000);
                func_003E7410(temp_s0_2);
            }
        }
    }
    char *p = arg0 + 0x24E5C;
    if (*(s32 *)p != 0) {
        LicenseConcourse__init(p, *(void **)(arg0 + 0x70), *(void **)(*(char **)(arg0 + 0x6C) + 0x80));
    }
}
