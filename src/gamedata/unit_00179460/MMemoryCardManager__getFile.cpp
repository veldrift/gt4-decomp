/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct RefCounter;
struct P20 { char pad[0x20]; s32 unk20; };
extern "C" void func_001740F0(void *, int);
extern "C" void mMemoryCardFile__structor_0(void *, s32);
extern "C" void func_00179280(void *, int) throw();
extern "C" s32 func_001792D8(void *, s32) throw();
extern "C" s32 func_001D27D0(s32, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, s32);
extern "C" s32 func_002FE250(s32);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);

extern "C" void MMemoryCardManager__getFile(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 b0[4];
    P20 *b1[4];
    s32 b2[4];
    if (arg2 > 0) {
        func_002FC8C8(b0, arg3);
        P20 **p1 = b1;
        func_001792D8(p1, arg1);
        s32 s0 = (*p1)->unk20;
        s32 v = func_001D27D0(s0, func_002FE250(b0[0]));
        if (v != 0) {
            s32 *p2 = b2;
            mMemoryCardFile__structor_0(p2, v);
            if (arg0 != p2) {
                s32 n = *p2;
                if (n != 0) {
                    func_003285A8((RefCounter *)n);
                }
                s32 old = *arg0;
                if (old != 0) {
                    func_003285F8((RefCounter *)old);
                }
                *arg0 = n;
            }
            func_001740F0(p2, 2);
        }
        func_00179280(p1, 2);
        func_002FC870(b0, 2);
    }
}
