/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" char *func_005A609C(char *, const char *);
extern "C" s32 func_004F6F10(char *dst, s32 size, const char *src) {
    s32 len = func_0057F260(dst);
    if (len < size) {
        s32 rem = size - len;
        if (rem >= func_0057F260(src)) {
            func_005A609C(dst + len, src);
            return 0;
        }
        func_005A4724(dst + len, src, rem);
        dst[size - 1] = 0;
        return 1;
    }
    return 1;
}
