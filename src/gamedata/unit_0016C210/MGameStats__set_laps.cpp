typedef int s32;
typedef short s16;
typedef signed char s8;

struct VEntry_16C {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj_16C {
    char pad0[4];
    VEntry_16C *vtbl;
};

extern "C" void func_0016BF40(void *arg0, s32 arg1);
extern "C" void func_0016BF98(void *arg0);

extern "C" void MGameStats__set_laps(void *, void *, s32, void **arg3) {
    s32 buf[4];
    s32 s1;
    Obj_16C *obj;
    VEntry_16C *e;
    s8 r;

    func_0016BF98((void *)buf);
    s1 = buf[0];
    obj = (Obj_16C *)*arg3;
    e = (VEntry_16C *)((char *)obj->vtbl + 0x58);
    r = (s8)e->fn((char *)obj + e->delta);
    *(s8 *)((char *)s1 + 0x30) = r;
    func_0016BF40((void *)buf, 2);
}
