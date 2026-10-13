typedef int s32;

extern char D_00693B80[];
extern char D_00828268[];
extern "C" s32 func_0057B1E8(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_001BF190(void *arg0, void **arg1) {
    void *t = *(void **)((char *)arg0 + 0x14);
    if (t == 0)
        return;
    void *obj = *arg1;
    s32 off = *(s32 *)((char *)obj - 0x10);
    void *a1v;
    if (off == 0) {
        a1v = D_00693B80;
    } else {
        char *p = (char *)obj + off;
        *p = 0;
        a1v = *arg1;
    }
    *(s32 *)((char *)t + 0x14) = func_0057B1E8((s32)D_00828268, (s32)a1v, 1);
}
