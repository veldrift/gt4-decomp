typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

extern "C" void *func_002405A8(s32 *arg0, void *arg1);
extern "C" void func_002403B0(void *arg0, s32 *arg1);
extern "C" void func_002403C8(void *arg0, int arg1);
extern "C" void func_00240398(void *arg0, s32 *arg1);

extern "C" void *func_002406E0(void *arg0) {
    s32 sp[8];
    s32 i = 0;
    do {
        func_002405A8(sp, (void *)i);
        i++;
        VObj *o = (VObj *)sp[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x198);
        s32 r = e->fn((char *)o + e->delta);
        if (r != 0) {
            func_002403B0(arg0, sp);
            func_002403C8(sp, 2);
            return arg0;
        }
        func_002403C8(sp, 2);
    } while (i < 3);
    sp[4] = 0;
    func_00240398(arg0, &sp[4]);
    return arg0;
}
