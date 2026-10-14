/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00645570[];
extern char D_0085147C[];
extern "C" int *func_00500DA0(char *arg0, char *arg1) {
    if (arg1 == 0) arg1 = D_00645570;
    if (*(signed char *)(arg0 + 0x15) == 0) *(int *)(arg1 + 0x5EC) = 1;
    *(int *)D_0085147C = 1;
    return (int *)D_0085147C;
}
