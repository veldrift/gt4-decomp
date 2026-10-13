typedef int s32;

typedef struct {
    char b[21];
} Block21_0043C968;

extern "C" void *func_0043C968(void *arg0, const void *arg1) {
    char *src = (char *)arg1;
    *(Block21_0043C968 *)((char *)arg0 + 0x10) = *(const Block21_0043C968 *)src;
    return src + 0x18;
}
