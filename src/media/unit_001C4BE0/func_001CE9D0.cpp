/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long long s64;
extern "C" s64 func_001CB8C0(void *) throw();
extern "C" void func_001CB9B8(void *, s32) throw();
extern "C" s32 func_001CBA80(void *, s32, s32, s32) throw();
extern "C" int func_001CE4F0(void *, void *, void *) throw();
extern "C" void func_004359B0(char *, unsigned long);

static inline s32 get(const s32 &x) { return x; }

extern "C" s32 func_001CE9D0(void *a0, void *a1, char *self, s32 flag) {
    char buf[0x80];
    s32 res;
    char *p = (char *)(((s32)buf + 0x3F) & ~0x3F);
    res = func_001CE4F0(a0, a1, p);
    s32 code = get(res);
    if (code != 0) return code;
    s32 t = *(s32 *)(self + 0x81CC);
    func_001CB9B8(p, t);
    s32 r = func_001CBA80(p, t, *(s32 *)(self + 0x81E0), *(s32 *)(self + 0x81F0));
    if (r == 0) return 4;
    *(s32 *)(self + 0x81F0) = *(s32 *)(p + 0x3C);
    if (flag) {
        func_004359B0(self, func_001CB8C0(p));
    }
    return 0;
}
