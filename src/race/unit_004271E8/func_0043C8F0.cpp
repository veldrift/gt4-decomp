typedef int s32;

typedef struct {
    char b[21];
} Block21_0043C8F0;

extern "C" void func_005A48D8(void *dst, int c, unsigned int n);

extern "C" void *func_0043C8F0(void *arg0, void *arg1) {
    func_005A48D8(arg1, 0, 0x18);
    *(Block21_0043C8F0 *)arg1 = *(const Block21_0043C8F0 *)((char *)arg0 + 0x10);
    return (char *)arg1 + 0x18;
}
