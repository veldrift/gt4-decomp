typedef int s32;
typedef short s16;

struct VEntry58 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj {
    s32 pad0;
    VEntry58 *vtbl;
};

static inline s32 vcall58(VObj *o) {
    VEntry58 *e = (VEntry58 *)((char *)o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" s32 func_005797A8(s32, s32, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00309348(void *, s32 *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MCalendar__dateToDay(s32 *ret, s32 argc, VObj **args) {
    s32 result[4];
    if (argc >= 3) {
        s32 day = func_005797A8(vcall58(args[0]), vcall58(args[1]), vcall58(args[2]));
        func_002FE278(result, day);
        if (ret != result) {
            s32 newVal = result[0];
            if (newVal != 0)
                func_003285A8(newVal);
            s32 oldVal = *ret;
            if (oldVal != 0)
                func_003285F8(oldVal);
            *ret = newVal;
        }
        func_002FC870(result, 2);
    } else {
        s32 zero = 0;
        func_00309348(result, &zero);
        if (ret != result) {
            s32 newVal = result[0];
            if (newVal != 0)
                func_003285A8(newVal);
            s32 oldVal = *ret;
            if (oldVal != 0)
                func_003285F8(oldVal);
            *ret = newVal;
        }
        func_00309378(result, 2);
    }
}
