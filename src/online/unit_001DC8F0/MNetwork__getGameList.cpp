typedef int s32;
typedef short s16;

struct Str {
    char *p;
    char pad[0xC];
};

struct VEntryI {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

extern "C" void func_001DC5F8(void *, int);
extern "C" void func_001DC650(void *, void *);
extern "C" void func_001F4160(void *, void *, s32, s32);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002EFBF0(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

static inline s32 vcall58(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void MNetwork__getGameList(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    Str sp0;
    Str a;
    Str b;
    Str *pa;
    Str *pb;
    s32 v0;
    s32 v1;
    func_001DC650(&sp0, arg1);
    pa = &a;
    func_002EFBF0(pa);
    if ((void *)arg0 != (void *)pa) {
        void *p = pa->p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*arg0 != 0) {
            func_003285F8(*arg0);
        }
        *arg0 = p;
    }
    v0 = 1;
    if (arg2 > 0) {
        v0 = vcall58(arg3[0]);
    }
    v1 = 0x10;
    if (arg2 >= 2) {
        v1 = vcall58(arg3[1]);
    }
    pb = &b;
    func_001F4160(pb, sp0.p, v0, v1);
    if ((void *)arg0 != (void *)pb) {
        void *p = pb->p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*arg0 != 0) {
            func_003285F8(*arg0);
        }
        *arg0 = p;
    }
    func_002ED5C0(pb, 2);
    func_002ED5C0(pa, 2);
    func_001DC5F8(&sp0, 2);
}
