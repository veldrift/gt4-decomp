typedef int s32;

extern "C" s32 func_00485FF0(void *arg0, void *arg1, void *arg2);
extern "C" char D_00698458[];

extern "C" void func_00229F40(void *arg0, void *arg1, void **arg2) {
    void *obj = *arg2;
    s32 off = *(s32 *)((char *)obj - 0x10);
    void *a2v;
    if (off == 0) {
        a2v = D_00698458;
    } else {
        char *p = (char *)obj + off;
        *p = 0;
        a2v = *arg2;
    }
    func_00485FF0((char *)arg0 + 0xB0, arg1, a2v);
}
