typedef int s32;

extern "C" void func_005A2F88(void *arg0);
extern "C" char D_0069E1B0[];

extern "C" void hString__toInt(void *arg0) {
    arg0 = (char *)arg0 + 0x10;
    void *obj = *(void **)arg0;
    s32 off = *(s32 *)((char *)obj - 0x10);
    void *a0v;
    if (off == 0) {
        a0v = D_0069E1B0;
    } else {
        char *p = (char *)obj + off;
        *p = 0;
        a0v = *(void **)arg0;
    }
    func_005A2F88(a0v);
}
