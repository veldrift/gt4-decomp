typedef int s32;

typedef struct {
    char b[25];
} Block25_0043CC10;

extern "C" void func_005A48D8(void *dst, int c, unsigned int n);

extern "C" void *func_0043CC10(void *arg0, void *arg1) {
    func_005A48D8(arg1, 0, 0x1C);
    *(Block25_0043CC10 *)arg1 = *(const Block25_0043CC10 *)((char *)arg0 + 0x10);
    return (char *)arg1 + 0x1C;
}
