typedef int s32;

extern "C" char D_0084D5C0[];
extern "C" char D_0084D5E0[];
extern "C" char D_0084D600[];
extern "C" char D_0084D800[];

extern "C" void func_0060B408(void *a, void *b, s32 c, s32 d);
extern "C" void func_0060B450(void *a, void *b, s32 c, s32 d);
extern "C" void func_0060B498(void *arg0, s32 arg1);
extern "C" void func_0060B4F0(void *arg0, s32 arg1);

extern "C" void func_004B14D0(s32 init, s32 prio) {
    if (prio == 0xFFFF && init == 1)
        func_0060B408(D_0084D5C0, D_0084D600, 0x200, 0x10);
    if (prio == 0xFFFF && init == 1)
        func_0060B450(D_0084D5E0, D_0084D800, 0x800, 0x40);
    if (prio == 0xFFFF && init == 0)
        func_0060B498(D_0084D5E0, 2);
    if (prio == 0xFFFF && init == 0)
        func_0060B4F0(D_0084D5C0, 2);
}
