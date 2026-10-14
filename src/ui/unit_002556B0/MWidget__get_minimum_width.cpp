typedef int s32;
typedef short s16;
typedef float f32;

struct RefCounter;

struct VEntry {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" f32 *func_0025BF60(s32 arg0);
extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, float fparg0);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void MWidget__get_minimum_width(s32 *arg0, void *arg1, s32 arg2, void **arg3) {
    s32 buf[4];
    f32 *s2;
    s32 newVal;
    s32 oldVal;

    func_00255110(buf, arg1);
    s2 = func_0025BF60(buf[0]);
    func_002550B8(buf, 2);
    if (arg2 == 0) {
        func_002F9360(buf, *s2);
        if (arg0 != buf) {
            newVal = buf[0];
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002F7B68(buf, 2);
    } else if (arg2 == 1) {
        VObj *o = (VObj *)arg3[0];
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x60);
        *s2 = e->fn((char *)o + e->delta);
    }
}
