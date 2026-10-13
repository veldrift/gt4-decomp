typedef int s32;

extern char D_00654D78[];
extern char D_00654D74[];
extern char D_00654D70[];
extern char D_00874378[];

extern "C" void func_00563748(void) {
    s32 *p = (s32 *)D_00874378;
    *(s32 *)D_00654D78 = 0;
    *(s32 *)D_00654D74 = 0;
    *(s32 *)D_00654D70 = 0;
    p[1] = 0;
    p[0] = 0;
}
