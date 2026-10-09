typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}
extern "C" void func_00137DB8(void *, void *);
extern "C" void func_00137D60(void *, s32);

extern "C" void MCarFace__set_quality_level(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    s32 t1;
    func_00137DB8(buf0, arg1);
    v_s1 = buf0[0];
    t1 = vcall_58((char *)(*(s32 *)(char *)arg3));
    *(s32 *)((char *)v_s1 + 0xa4) = t1;
    func_00137D60(buf0, 0x2);
}
