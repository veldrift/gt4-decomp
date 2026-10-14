typedef int s32;
extern "C" s32 func_00108D80(s32 a);
extern "C" s32 func_004479B0(void);
extern "C" s32 func_004479E8(void);
extern "C" void func_00447A20(void);
extern "C" void func_0048F930(void *a);
extern "C" void func_0048F9B8(s32 a);
extern "C" void func_0048FA10(void);
extern "C" char D_0068CB80[];
extern "C" s32 D_006186F0;
extern "C" void func_00107F68(void) {
    s32 *p = &D_006186F0;
    if (*p == 0) {
        func_0048FA10();
        func_0048F930(D_0068CB80);
        func_0048F9B8(func_00108D80(1));
        func_00447A20();
        func_004479E8();
        func_004479B0();
        *p = 1;
    }
}
