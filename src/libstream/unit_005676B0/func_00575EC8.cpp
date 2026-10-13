typedef struct { char b[40]; } Blob40;

extern void func_005A48D8(void *dst, int c, int n);

char *func_00575EC8(char *obj) {
    Blob40 t;
    func_005A48D8(&t, 0, 0x28);
    *(Blob40 *)obj = t;
    return obj;
}
