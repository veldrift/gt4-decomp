typedef int s32;
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, s32) throw();
extern "C" s32 func_001F66F8(s32, s32, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
struct H { s32 p[4]; H(const H &); };
extern "C" H func_002FE278(s32);
inline void *operator new(unsigned int, void *p) { return p; }
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

static inline void assign(s32 *dst, s32 *src) { s32 newVal, oldVal;
            if (dst != src) {
                newVal = *src;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *dst;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *dst = newVal;
            }
}
extern "C" void MNetwork__glistLAN(s32 *arg0, s32 arg1, s32 arg2, char *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s4;
    s32 *p_s3;
    s32 *p_s1;
    s32 s0;
    s32 r;
    s32 newVal;
    s32 oldVal;
    if (arg2 >= 2) {
        func_001DC650(buf0, arg1);
        p_s4 = buf1;
        func_002FC8C8(p_s4, arg3);
        p_s3 = buf2;
        func_002FC8C8(p_s3, arg3 + 4);
        s0 = func_002FE250(*p_s4);
        r = func_001F66F8(buf0[0], s0, func_002FE250(*p_s3));
        if (r == 0) {
            new (buf3) H(func_002FE278(0));
            assign(arg0, buf3);
            func_002FC870(buf3, 2);
        } else {
            new (buf3) H(func_002FE278(1));
            assign(arg0, buf3);
            func_002FC870(buf3, 2);
        }
        func_002FC870(p_s3, 2);
        func_002FC870(p_s4, 2);
        func_001DC5F8(buf0, 2);
    }
}
