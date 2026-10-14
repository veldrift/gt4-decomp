extern "C" int func_0052DFA0(void *, void *);
extern "C" int func_00528F38(void *arg0, char *arg1, int arg2, void *arg3) {
    if (!arg0) return 0xD2F2;
    if (!arg1) return 0xD2F3;
    if (*(int *)arg1 != 13) return 0xD2F3;
    if (!arg3) return 2;
    if (arg2 == 0) return func_0052DFA0(arg1 + 0x14, arg3);
    if (arg2 == 1) return func_0052DFA0(arg1 + 0x2c, arg3);
    return 2;
}
