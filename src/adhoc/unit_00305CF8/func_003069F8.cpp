typedef int s32;
typedef short s16;

struct RefCounter;

struct VEntry_198 { s16 delta; s16 index; s32 (*fn)(void *, void *, s32); };
struct VEntry_48 { s16 delta; s16 index; void (*fn)(void *, void *, void *); };
struct VObj { char pad0[4]; char *vtbl; };

extern "C" void func_00323D08(void *a0);
extern "C" void *func_0030BB18(void *a0);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_00323B60(void *arg0, int arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void func_003069F8(void *arg0, s32 *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 newVal;
    s32 oldVal;
    func_00323D08(buf0);
    {
        VEntry_198 *e = (VEntry_198 *)(((VObj *)arg0)->vtbl + 0x198);
        char *obj = (char *)arg0 + e->delta;
        e->fn(obj, buf0, arg2);
    }
    if (buf0[0] != 0) {
        s32 *p_s3 = buf1;
        char *o = (char *)buf0[0];
        VEntry_48 *e = (VEntry_48 *)(((VObj *)o)->vtbl + 0x48);
        char *obj = o + e->delta;
        func_0030BB18(p_s3);
        e->fn(obj, arg1, p_s3);
        func_00309378(p_s3, 2);
    } else {
        s32 *p_s1 = buf1;
        func_0030BB18(p_s1);
        if (arg1 != p_s1) {
            newVal = p_s1[0];
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *arg1;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *arg1 = newVal;
        }
        func_00309378(p_s1, 2);
    }
    func_00323B60(buf0, 2);
}
