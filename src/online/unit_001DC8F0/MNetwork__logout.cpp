typedef int s32;
typedef unsigned int u32;
struct RefCounter;

extern "C" void func_001DC5F8(void *, s32) throw();
extern "C" void func_001DC650(void *, s32) throw();
extern "C" u32 func_001F1578(s32);
extern "C" s32 func_001F16A8(s32);
extern "C" s32 func_001F2308(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);

static inline void assign(s32 *dst, s32 *src) {
    if (dst != src) {
        s32 x = *src;
        if (x != 0)
            func_003285A8((RefCounter *)x);
        s32 old = *dst;
        if (old != 0)
            func_003285F8((RefCounter *)old);
        *dst = x;
    }
}

extern "C" void MNetwork__logout(s32 *dst, s32 a1) {
    struct F { s32 h[4]; s32 r[4]; } fr;
    func_001DC650(fr.h, a1);
    if (func_001F1578(fr.h[0]) == 0 || func_001F2308(fr.h[0]) == 0 || func_001F16A8(fr.h[0]) == 0) {
        s32 *pr = fr.r;
        func_002FE278(pr, 0);
        assign(dst, pr);
        func_002FC870(pr, 2);
        func_001DC5F8(fr.h, 2);
    } else {
        s32 *pr = fr.r;
        func_002FE278(pr, 1);
        assign(dst, pr);
        func_002FC870(pr, 2);
        func_001DC5F8(fr.h, 2);
    }
}
