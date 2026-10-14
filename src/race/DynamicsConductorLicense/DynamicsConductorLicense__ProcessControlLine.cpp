/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(char *);
};

struct Slot { char pad[0x718]; s32 v; };

extern "C" Slot *func_0034C190(void *arg0, s32 arg1);
extern "C" int func_003F6320(void *o) throw();
extern "C" void func_00343D78(void *p, s32 n);
extern "C" void func_003F8AB0(void *self, void *obj, s32 time);
extern "C" void func_0035E6B0(s32 *arg0, void *arg1, s32 arg2, char **arg3);
extern "C" void RaceDisplayGeneralTimeEvent__structor_0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

extern "C" void DynamicsConductorLicense__ProcessControlLine(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    char *s5 = (char *)func_0034C190(arg0, arg1);
    u8 st = *(u8 *)((char *)arg0 + 0xF81A);
    s32 s1;
    u8 *a;

    if (st == 3 || st == 6) {
        VEntry *e;
        e = (VEntry *)(*(char **)((char *)arg0 + 0x10140) + 0x128);
        if (e->fn((char *)arg0 + e->delta) == arg2) {
            func_003F8AB0(arg0, s5, arg5);
            func_0034C190(arg0, arg1)->v = arg4;
            return;
        }
    } else if (st == 5) {
        VEntry *e;
        e = (VEntry *)(*(char **)((char *)arg0 + 0x10140) + 0x128);
        if (e->fn((char *)arg0 + e->delta) == arg2) {
            func_00343D78(s5, 3);
            func_0034C190(arg0, arg1)->v = arg4;
        }
        return;
    }
    s1 = arg2 - 1;
    if (func_003F6320(arg0) != 0) {
        VEntry *e;
        e = (VEntry *)(*(char **)((char *)arg0 + 0x10140) + 0x150);
        s1 = arg2 * e->fn((char *)arg0 + e->delta) - 1;
    }
    if (s1 < 0x10) {
        a = (u8 *)((char *)arg0 + 0xF818);
        if (a[0x40] == 0 || a[2] == 6) {
            func_0035E6B0((s32 *)arg0, (void *)arg1, s1, (char **)arg5);
            RaceDisplayGeneralTimeEvent__structor_0(arg0, arg1, arg2, s1, arg4, arg5, (u8)s5[0x5B7]);
            return;
        }
    }
}
