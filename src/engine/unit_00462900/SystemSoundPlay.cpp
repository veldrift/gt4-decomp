/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Entry463378 {
    char d[0x24];
};

extern Entry463378 D_008485C0[];

extern "C" u32 getNumber(s32 arg0) throw();
extern "C" s32 GTSOUNDINSTRUMENTJAM__getJam(Entry463378 *e) throw();
extern "C" void SystemSoundStop(void *self, int flags);
extern "C" void SePlayer__Initialize(void *self, s32 *out, s32 arg2) throw();
extern "C" void SePlayer__Play(void *self, s32 arg1, f32 f0, f32 f1, f32 f2, s32 arg2, s32 arg3) throw();

extern "C" void SystemSoundPlay(void *obj, s32 arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1) {
    struct Params { s32 a,b,c,d; } out;
    u32 v;

    v = getNumber(arg0);
    out.a = GTSOUNDINSTRUMENTJAM__getJam(&D_008485C0[v >> 24]);
    out.b = (v >> 16) & 0xFF;
    out.c = (v >> 8) & 0xFF;
    out.d = v & 0xFF;
    SystemSoundStop(obj, 1);
    SePlayer__Initialize(obj, (s32 *)&out, 1);
    SePlayer__Play(obj, arg2, fparg0, fparg0, fparg1, 0, arg1);
}
