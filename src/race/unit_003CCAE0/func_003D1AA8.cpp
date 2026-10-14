typedef int s32;
typedef float f32;

extern "C" s32 func_003CC8E8(void);
extern "C" void RaceEntryCar__update(s32 arg0);
extern "C" s32 func_003D5660(void *s);
extern "C" void func_003D56A0(void *arg0);
extern "C" void func_003D5728(void *a0, s32 a1, s32 a2, f32 f12, f32 f13, f32 f14, f32 f15);
extern "C" void func_003D57D8(void *a0);

extern "C" void func_003D1AA8(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    char *self = (char *)arg0;
    if (func_003CC8E8() == 0) {
        return;
    }
    RaceEntryCar__update(0);
    if (*(s32 *)(self + 0x9680) == 0) {
        return;
    }
    char *p = self + 0x7C5C;
    if (func_003D5660(p) == 0) {
        return;
    }
    func_003D56A0(p);
    s32 i = 0;
    if (*(s32 *)((char *)arg1 + 0xF8A0) > 0) {
        do {
            if (i != arg3) {
                func_003D5728(p, i, arg2, *(f32 *)(self + 0x78A8), *(f32 *)(self + 0x78AC),
                              *(f32 *)(self + 0x78B0), *(f32 *)(self + 0x78B8));
            }
            i += 1;
            self += 0xA0;
        } while (i < *(s32 *)((char *)arg1 + 0xF8A0));
    }
    func_003D57D8(p);
}
