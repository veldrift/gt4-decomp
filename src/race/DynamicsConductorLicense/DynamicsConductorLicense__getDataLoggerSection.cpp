typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Obj_3F6140 {
    char pad0[0x10140];
    char *vtbl;
};

struct VEntry_3F6140 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *, s32);
};

extern "C" s16 Automobile__GetImplicitCurrentLap(void *);
extern "C" s32 DynamicsConductor__getNumberOfLoggerSections(void *);
extern "C" s32 DynamicsConductor__getDataLoggerSection(void *, void *, s32);

extern "C" s32 DynamicsConductorLicense__getDataLoggerSection(char *arg0, char *arg1, s32 arg2) {
    Obj_3F6140 *o = (Obj_3F6140 *)arg0;
    VEntry_3F6140 *e = (VEntry_3F6140 *)(o->vtbl + 0x40);
    if (e->fn((char *)o + e->delta, arg1, arg2) == 0) {
        return DynamicsConductor__getDataLoggerSection(arg0, arg1, arg2);
    } else {
        s32 s0 = Automobile__GetImplicitCurrentLap(arg1);
        s32 n = DynamicsConductor__getNumberOfLoggerSections(arg0);
        s32 temp = (s0 - 1) * n + *(u8 *)(arg1 + 0x5B8);
        s32 r = temp - 1;
        if (arg2 == 0) {
            r = temp;
        }
        return r;
    }
}
