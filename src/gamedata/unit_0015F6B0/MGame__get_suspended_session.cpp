typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}
extern "C" void * func_0015F3E0(void *, void *);
extern "C" void func_0015F388(void *, s32);
extern "C" void * func_002FE278(void *, u8);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

struct func_001655A8_s {
    char pad0[0x28];
    s8 unk28;
    u8 unk29;
};

extern "C" void func_001655A8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s0;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    struct func_001655A8_s *p;
    if (arg2 > 0) {
        func_0015F3E0(buf0, arg1);
        v_s0 = *(s32 *)((char *)buf0[0] + 0x10);
        v_s0 = v_s0 + 0x38BF8;
        t1 = vcall_58((char *)(*(s32 *)(char *)arg3));
        ((struct func_001655A8_s *)v_s0)->unk29 = (u8)t1;
        func_0015F388(buf0, 0x2);
    } else {
        func_0015F3E0(buf0, arg1);
        p = (struct func_001655A8_s *)(*(s32 *)((char *)buf0[0] + 0x10) + 0x38BF8);
        func_0015F388(buf0, 0x2);
        if (p->unk28 != 0) {
            func_002FE278(buf0, p->unk29);
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
}
