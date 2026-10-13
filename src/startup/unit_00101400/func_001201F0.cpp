typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32 *);
};

struct VObj {
    char pad[0x64];
    char *vtbl;
};

extern VObj *D_00618710;

extern "C" s32 func_001201F0(void) {
    s32 buf[4];
    VObj *o = D_00618710;
    if (o != 0) {
        VEntry *e = (VEntry *)(o->vtbl + 0x308);
        e->fn((char *)o + e->delta, buf);
        return buf[0];
    }
    return -1;
}
