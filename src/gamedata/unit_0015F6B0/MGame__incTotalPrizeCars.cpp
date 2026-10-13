typedef int s32;
typedef short s16;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" void func_0015F3E0(void *arg0, void *arg1);
extern "C" void func_0015F388(void *arg0, s32 arg1);

extern "C" void func_00163E80(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    char *o;
    char *w;
    s32 r;
    if (arg2 > 0) {
        func_0015F3E0(buf0, arg1);
        o = *arg3;
        w = (char *)*(s32 *)((char *)buf0[0] + 0x10) + 0x348;
        r = vcall_58(o);
        *(s32 *)(w + 0x50) = *(s32 *)(w + 0x50) + r;
        func_0015F388(buf0, 2);
    }
}
