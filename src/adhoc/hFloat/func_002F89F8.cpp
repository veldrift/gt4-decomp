typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" void func_002FE2E0(void *arg0);
extern "C" s32 func_002FC910(void *arg0, void *arg1);
extern "C" void func_002F9360(void *arg0, f32 fparg0);
extern "C" void func_002F7B68(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void func_002F89F8(s32 *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    f32 t1;
    s32 newVal;
    s32 oldVal;
    func_002FE2E0(buf0);
    if (func_002FC910(buf0, arg3) != 0) {
        t1 = (f32)vcall_58((char *)buf0[0]);
        p_s1 = buf1;
        func_002F9360(p_s1, t1);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002F7B68(p_s1, 0x2);
    }
    if (arg0 != arg3) {
        newVal = *arg3;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(buf0, 0x2);
}
