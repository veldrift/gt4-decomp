extern void *func_001F1368(void *);
extern void func_00215298(int);
extern int func_004F3A20(char *, int);
extern char D_00645570[];

void *func_001F5BB8(void *arg0)
{
    while (!func_004F3A20(D_00645570, *(int *)(D_00645570 + 0xFDC)))
        func_00215298(1);
    return func_001F1368(arg0);
}
