typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}

extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" f32 func_00267D10(s32 arg0);
extern "C" void mWidget__setRotate(s32 arg0, f32 fparg0);
extern "C" void func_002F7B68(void *arg0, s32 arg1);
extern "C" void func_002F9360(void *arg0, f32 fparg0);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void MWidget__get_rotate(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    s32 *p_s1;
    f32 t1;
    s32 newVal;
    s32 oldVal;
    func_00255110(buf0, arg1);
    if (arg2 == 0) {
        t1 = func_00267D10(buf0[0]);
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
    } else if (arg2 == 1) {
        v_s0 = buf0[0];
        t1 = vcall_60(*arg3);
        mWidget__setRotate(v_s0, t1);
    }
    func_002550B8(buf0, 0x2);
}
