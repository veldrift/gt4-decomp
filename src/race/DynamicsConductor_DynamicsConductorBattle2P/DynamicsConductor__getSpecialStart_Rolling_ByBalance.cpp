typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    char pad0[0x10140];
    union {
        char *vtbl;
        s32 word;
    } vt;
};

static inline s32 vcall_0034D168(Obj *o, s32 off, s32 a) {
    VEntry *e = (VEntry *)(o->vt.vtbl + off);
    return e->fn((char *)o + e->delta, a);
}

extern "C" s32 DynamicsConductor__GetStartVOffsetBySectionSet(Obj *o);

extern "C" s32 DynamicsConductor__getSpecialStart_Rolling_ByBalance(Obj *arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    s32 n;

    n = vcall_0034D168(arg0, 0x118, arg1);
    if (n < 0) {
        n = vcall_0034D168(arg0, 0x120, arg1);
        if (n > 0) {
            *arg2 = 2;
            n = vcall_0034D168(arg0, 0x118, arg1);
            *arg3 = n;
            if (n != 0) {
                *arg3 += DynamicsConductor__GetStartVOffsetBySectionSet(arg0);
            }
            *arg4 = vcall_0034D168(arg0, 0x120, arg1);
            return 1;
        }
    }
    return 0;
}
