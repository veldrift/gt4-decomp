typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct func_00472A08_p;

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcallf_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}

extern "C" char PDISTD__UNIT_MANAGER[];
extern "C" f32 func_00472A08(struct func_00472A08_p *p, f32 x);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" void func_002FC870(void *arg0, s32 arg1);

extern "C" void MUnit__GetTorqueForDisplay(s32 *arg0, s32 arg1, void **arg2) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    if (arg1 > 0) {
        func_002FE278(buf0, (void *)(s32)(func_00472A08((struct func_00472A08_p *)PDISTD__UNIT_MANAGER, vcallf_60((char *)*arg2)) + 0.5f));
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
