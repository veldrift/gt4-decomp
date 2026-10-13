typedef int s32;

extern "C" void func_002AE9C0(void *);
extern "C" void func_0022AC98(void *, void *);
extern "C" void func_00255088(void *, void *);
extern "C" void func_002B5238(s32, s32, s32);
extern "C" void func_002550B8(void *, s32);
extern "C" void func_0022ACC8(void *, s32);
extern "C" void func_002AE968(void *, s32);

extern "C" void func_002AF9C8(void *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 t30;
    s32 t34;
    s32 *p1;
    s32 *p2;
    s32 *q30;
    s32 *q34;
    s32 v;

    if (arg2 == 0x2) {
        func_002AE9C0(buf0);
        v = arg3[0];
        q30 = &t30;
        p1 = buf1;
        *q30 = v;
        func_0022AC98(p1, q30);
        v = arg3[1];
        q34 = &t34;
        p2 = buf2;
        *q34 = v;
        func_00255088(p2, q34);
        func_002B5238(buf0[0], p1[0], p2[0]);
        func_002550B8(p2, 0x2);
        func_0022ACC8(p1, 0x2);
        func_002AE968(buf0, 0x2);
    }
}
