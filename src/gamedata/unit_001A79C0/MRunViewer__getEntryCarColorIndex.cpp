typedef int s32;
typedef unsigned char u8;

struct RefCounter {
    s32 ref;
};

struct S {
    char pad[0x10];
};

extern "C" void func_001A7728(void *arg0, int arg1);
extern "C" void func_001A7780(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" int func_002FE250(S *arg0);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void MRunViewer__getEntryCarColorIndex(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s3;
    s32 *p_s1;
    s32 base;
    s32 idx;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_001A7780(buf0, arg1);
        p_s3 = buf1;
        func_002FC8C8(p_s3, arg3);
        base = *(s32 *)((char *)buf0[0] + 0x10);
        idx = func_002FE250((S *)p_s3[0]);
        p_s1 = buf2;
        func_002FE278(p_s1, *(void **)((char *)(idx * 0x44 + base) + 0x40));
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s1, 0x2);
        func_002FC870(p_s3, 0x2);
        func_001A7728(buf0, 0x2);
    }
}
