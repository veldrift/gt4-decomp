typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern f32 D_00618A38;
extern f32 D_00618A3C;

extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F7BC0(void *arg0, void *arg1);
extern "C" f32 func_002F9158(void *arg0);
extern "C" void func_002F9360(void *arg0, f32 fparg0);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void func_0017EF70(s32 *arg0, s32 arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    f32 *pg;
    f32 *pb;
    s32 *p_s2;
    f32 r;
    f32 cur;
    f32 nxt;
    s32 newVal;
    s32 oldVal;
    if (arg1 > 0) {
        func_002F7BC0(buf0, (void *)arg2);
        pg = &D_00618A38;
        r = func_002F9158((void *)buf0[0]);
        pb = &D_00618A3C;
        cur = *pg;
        p_s2 = buf1;
        nxt = cur + ((*pb - cur) * r);
        *pg = nxt;
        func_002F9360(p_s2, nxt);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002F7B68(p_s2, 2);
        func_002F7B68(buf0, 2);
    }
}
