typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern "C" char PDISTD__UNIT_MANAGER[];

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcallf_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}

extern "C" f32 func_00472940(s32 *p, f32 x);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" void func_002FC870(void *arg0, s32 arg1);

extern "C" void MUnit__GetVelocityForDisplay(s32 *arg0, s32 arg1, void **arg2) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    if (arg1 > 0) {
        f32 r = vcallf_60((char *)(*(s32 *)arg2));
        if (*(s32 *)PDISTD__UNIT_MANAGER != 0) {
            r = func_00472940((s32 *)PDISTD__UNIT_MANAGER, r * 0x1.1C71C6p-2f);
        }
        s32 t = (s32)(r + 0x1.0p-1f);
        func_002FE278(buf0, (void *)t);
        if (arg0 != buf0) {
            newVal = buf0[0];
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
}
