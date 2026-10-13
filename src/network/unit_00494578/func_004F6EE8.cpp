typedef struct S8 { char data[8]; } S8;

extern char D_00645570[];

extern "C" void func_004F6EE8(S8 *arg0, char *arg1) {
    if (arg1 == 0) {
        arg1 = D_00645570;
    }
    *(S8 *)(arg1 + 0xCB0) = *arg0;
}
