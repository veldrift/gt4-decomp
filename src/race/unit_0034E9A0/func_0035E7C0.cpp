typedef int s32;
typedef float f32;

extern "C" s32 func_0034C190(void *arg0, s32 arg1);
extern "C" s32 func_0035E3F8(void *arg0, void *arg1, s32 arg2);
extern "C" void func_003A3148(void *o, void *t);
extern "C" void func_003A36A0(void *arg0);
extern "C" f32 func_00472940(void *p, f32 x);
extern char D_006244D8[];

extern "C" void func_0035E7C0(void *arg0, s32 arg1, f32 fparg0) {
    s32 buf[4];
    char *temp_s1;
    s32 temp_a1;
    s32 r;
    unsigned char *w;

    w = (unsigned char *)((char *)func_0034C190(arg0, arg1) + 0x104);
    if (w[0x441] == 0 && w[0x632] == 0) {
        temp_s1 = *(char **)arg0;
        r = func_0035E3F8(temp_s1, arg0, func_0034C190(arg0, arg1));
        temp_a1 = arg1 * 4;
        if (r == 0) {
            char *v60 = *(char **)(temp_s1 + 0x60);
            s32 v8 = *(s32 *)(v60 + 8);
            char *el = *(char **)(temp_a1 + v8);
            *(f32 *)(el + 0x3464) = fparg0;
        }
        if (*(s32 *)(temp_s1 + 0xDC) == 0) {
            func_003A36A0(buf);
            buf[0] = arg1;
            *(f32 *)&buf[2] = func_00472940(D_006244D8, fparg0);
            func_003A3148(buf, temp_s1);
        }
    }
}
