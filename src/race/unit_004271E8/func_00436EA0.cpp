typedef short s16;
typedef int s32;

extern "C" s32 func_0043DA38(s32);
extern "C" s32 func_0043DA40(s32, s32);

extern char D_006A5E10[];

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, char *, s32);
};

struct Holder {
    char pad0[0x50];
    VEntry ent;
};

extern "C" void func_00436EA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s1 = arg0 + 0x11D0;
    if (arg1 < func_0043DA38(s1)) {
        s32 *pv = (s32 *)func_0043DA40(s1, arg1);
        Holder *h = (Holder *)*pv;
        VEntry *e = &h->ent;
        e->fn((char *)pv + e->delta, D_006A5E10, arg3);
    }
}
