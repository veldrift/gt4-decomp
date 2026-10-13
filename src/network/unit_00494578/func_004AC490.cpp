typedef int s32;

extern "C" void *func_004AD1C8(void *);
extern "C" void func_0057CB00(void *, void *);
extern "C" void *func_0060A480(void *);

extern char D_00688B70[];
extern s32 D_0062A070;
extern char D_0062A078[];

extern "C" void func_004AC490(char *arg0) {
    s32 i;
    char *p;
    char *s3;

    i = 0;
    s3 = arg0 + 0xA8;
    func_004AD1C8(arg0);
    *(s32 *)(arg0 + 0xA4) = (s32)D_00688B70;
    func_0060A480(s3);
    if (D_0062A070 > 0) {
        p = D_0062A078;
        do {
            *(s32 *)(p + 0x38) = (s32)arg0;
            func_0057CB00(s3, p + 0x3C);
            i++;
            p += 0xF0;
        } while (i < D_0062A070);
    }
}
