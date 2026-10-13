typedef int s32;
typedef short s16;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" void func_0024E3D0(void *, void *);
extern "C" s32 func_00251BE8(s32, s32);
extern "C" void func_00232BF0(s32 *, s32 *);
extern "C" void func_00232C20(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_0024E378(void *, s32);

extern "C" void MUpdateContext__getStartPage(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 sp20[4];
    s32 *p20;
    s32 v_s0;
    s32 *p_s1;
    s32 r;
    s32 newVal;
    s32 oldVal;
    if (arg2 == 0x1) {
        func_0024E3D0(buf0, arg1);
        v_s0 = buf0[0];
        p20 = sp20;
        r = func_00251BE8(v_s0, vcall_58((char *)*(s32 *)arg3));
        p_s1 = buf1;
        sp20[0] = r;
        func_00232BF0(p_s1, p20);
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
        func_00232C20(p_s1, 0x2);
        func_0024E378(buf0, 0x2);
    }
}
