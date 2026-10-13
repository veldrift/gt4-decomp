typedef int s32;
typedef short s16;

struct RefCounter;
struct func_0042F4F0_arg0;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" void func_00132DB8(void *arg0, void *arg1);
extern "C" void func_00132D60(void *arg0, s32 arg1);
extern "C" s32 func_0042F4F0(struct func_0042F4F0_arg0 *arg0);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void func_00133288(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    s32 newVal;
    s32 oldVal;

    func_00132DB8(buf0, arg1);
    v_s1 = *(s32 *)((char *)buf0[0] + 0x10);
    func_00132D60(buf0, 2);
    v_s1 = func_0042F4F0((struct func_0042F4F0_arg0 *)v_s1);
    if (arg2 > 0) {
        v_s1 = v_s1 % vcall_58((char *)(*(s32 *)(char *)arg3));
    }
    func_002FE278(buf0, (void *)v_s1);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(buf0, 2);
}
