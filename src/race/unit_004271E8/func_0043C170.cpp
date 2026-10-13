typedef int s32;

typedef struct {
    char b[30];
} Block30_0043C170;

extern "C" void func_005A48D8(void *dst, int c, unsigned int n);

extern "C" void *func_0043C170(void *arg0, void *arg1) {
    func_005A48D8(arg1, 0, 0x20);
    *(Block30_0043C170 *)arg1 = *(const Block30_0043C170 *)((char *)arg0 + 0x10);
    return (char *)arg1 + 0x20;
}
