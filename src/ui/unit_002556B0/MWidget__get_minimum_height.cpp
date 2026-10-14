typedef int s32;
typedef float f32;

struct W {
    s32 pad0;
    f32 f4;
};

struct VEntry_60 {
    short delta;
    short index;
    f32 (*fn)(void *);
};

struct VObj_60 {
    char pad0[4];
    VEntry_60 *vtbl;
};

static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}

extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" s32 func_0025BF60(s32 arg0);
extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, f32 fparg0);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MWidget__get_minimum_height(s32 *arg0, void *arg1, s32 arg2, void **arg3) {
    s32 buf[4];
    W *w;
    s32 newVal;
    s32 oldVal;
    func_00255110(buf, arg1);
    w = (W *)func_0025BF60(buf[0]);
    func_002550B8(buf, 2);
    if (arg2 == 0) {
        func_002F9360(buf, w->f4);
        if (arg0 != buf) {
            newVal = buf[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002F7B68(buf, 2);
    } else if (arg2 == 1) {
        w->f4 = vcall_60((char *)*arg3);
    }
}
