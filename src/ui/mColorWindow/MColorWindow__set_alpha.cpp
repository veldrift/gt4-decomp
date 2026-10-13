typedef int s32;
typedef float f32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, s32, f32);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_00287C88(void *arg0, int arg1);
extern "C" void func_00287CE0(void *arg0, void *arg1);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F7BC0(void *arg0, void *arg1);
extern "C" f32 func_002F9158(void *arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" s32 func_002FE250(s32 arg0);

extern "C" void func_00288170(void *arg0, void *arg1, s32 arg2, void *arg3)
{
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 v_s3;
    s32 *p_s2;
    s32 *p_s0;
    if (arg2 > 0) {
        v_s3 = -1;
        func_00287CE0(buf0, arg1);
        p_s2 = buf1;
        func_002F7BC0(p_s2, arg3);
        p_s0 = buf2;
        if (!(arg2 < 2)) {
            func_002FC8C8(p_s0, (char *)arg3 + 4);
            v_s3 = func_002FE250(*p_s0);
            func_002FC870(p_s0, 2);
        }
        VObj *o = (VObj *)buf0[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x1D8);
        char *self = (char *)o + e->delta;
        f32 f = func_002F9158((void *)*p_s2);
        e->fn(self, v_s3, f);
        func_002F7B68(p_s2, 2);
        func_00287C88(buf0, 2);
    }
}
