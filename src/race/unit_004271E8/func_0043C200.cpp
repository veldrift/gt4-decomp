typedef struct {
    char b[30];
} Block30_0043C200;

extern "C" void *func_0043C200(void *arg0, const void *arg1) {
    char *src = (char *)arg1;
    *(Block30_0043C200 *)((char *)arg0 + 0x10) = *(const Block30_0043C200 *)src;
    return src + 0x20;
}
