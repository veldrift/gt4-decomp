typedef int s32;
extern "C" void *func_005A6AB0(void *, void *, s32) throw();
extern "C" s32 func_0057F260(const char *) throw();
extern "C" char *func_005A6DC8(const char *, const char *) throw();
extern "C" s32 func_005A2F88(const char *);
extern "C" s32 func_005317B8(char *arg0, char *arg1) {
    char buf[16];
    char *p = buf;
    s32 i;
    if (arg1 == 0 || arg0 == 0) goto fail;
    func_005A6AB0(buf, arg1, 0x10);
    i = 0;
    if (func_0057F260(buf) == 0) return 0x17;
    for (;;) {
        char *dot = func_005A6DC8(p, ".");
        char *cur = p;
        p = dot + 1;
        if (dot == 0) goto fail;
        *dot = 0;
        arg0[i] = func_005A2F88(cur);
        i++;
        if (i >= 3) break;
    }
    arg0[3] = func_005A2F88(p);
    return 0;
fail:
    return 0xA;
}
