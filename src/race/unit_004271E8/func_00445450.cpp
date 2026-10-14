typedef int s32;
typedef long s64;
struct Tab { char pad[0x1E4]; s32 f1E4; };
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow_2(void *, int, int, void *);
extern "C" s64 func_004454C0(s64 *);
extern "C" s32 func_00449CD8(s32, s32);
extern Tab D_006235A8;
extern char D_006A6DD0[];
extern "C" char *func_00445450(s64 *p) {
    s32 buf[4];
    s32 key = (s32)(func_004454C0(p) & 0xFFFFFFFFL);
    if (!SPEC_DATABASE__DatabaseStorage__getRow_2(&D_006235A8, key, 0x27, buf)) {
        return D_006A6DD0;
    }
    return (char *)func_00449CD8(D_006235A8.f1E4, buf[2]);
}
