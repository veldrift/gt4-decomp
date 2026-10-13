typedef struct { char b[25]; } Block25;

void *func_0043CC88(void *arg0, void *arg1) {
    *(Block25 *)((char *)arg0 + 0x10) = *(Block25 *)arg1;
    return (char *)arg1 + 0x1C;
}
