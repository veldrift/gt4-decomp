typedef int s32;
typedef short s16;
struct RefCounter;
struct VE { s16 delta; s16 pad; s32 (*fn)(void *); };
struct Obj { char pad0[4]; char *vtbl; };

extern "C" void func_001DC5F8(void *, s32) throw();
extern "C" void func_001DC650(void *, s32) throw();
extern "C" s32 func_001F1590(s32);
extern "C" void func_001F5C10(void *, s32, s32);
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);

extern "C" void MNetwork__getPlayerInfo(s32 *dst, s32 a1, s32 n, Obj **pobj) {
    struct F { s32 h[4]; s32 r[4]; s32 k[4]; } fr;
    func_001DC650(fr.h, a1);
    s32 v = func_001F1590(fr.h[0]);
    if (n > 0) {
        Obj *o = *pobj;
        VE *e = (VE *)(o->vtbl + 0x58);
        v = e->fn((char *)o + e->delta);
    }
    s32 *pk = fr.k;
    s32 *pr = fr.r;
    func_001DC650(pk, a1);
    func_001F5C10(pr, pk[0], v);
    if (dst != pr) {
        s32 x = pr[0];
        if (x != 0)
            func_003285A8((RefCounter *)x);
        s32 old = *dst;
        if (old != 0)
            func_003285F8((RefCounter *)old);
        *dst = x;
    }
    func_002ED5C0(pr, 2);
    func_001DC5F8(pk, 2);
    func_001DC5F8(fr.h, 2);
}
