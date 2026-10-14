/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern "C" void func_00210710(void *, int);
extern "C" void func_0025A7E0(void *, void *);
extern "C" void mTextFace__virtual_67(void);
extern "C" void func_0026A118(void *, int);
extern "C" void func_0026A990(void *, s32, void *, int, int, int);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void mColorChipFace__virtual_67(char *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    char *p;
    s32 i;
    mTextFace__virtual_67();
    i = 1;
    p = arg0;
    do {
        s32 *src = (s32 *)(p + 0xA0);
        if (__builtin_expect(*(s32 *)(*src - 0x10), 0)) {
            s32 *dst = (s32 *)(p + 0xA8);
            s32 *handle = buf1;
            func_0025A7E0(handle, arg0);
            func_0026A990(buf0, *handle, src, 1, 0, 1);
            if (dst != buf0) {
                s32 n = buf0[0];
                if (n != 0) func_003285A8(n);
                if (*dst != 0) func_003285F8(*dst);
                *dst = n;
            }
            func_00210710(buf0, 2);
            func_0026A118(handle, 2);
        }
        i--;
        p += 4;
    } while (i >= 0);
}
