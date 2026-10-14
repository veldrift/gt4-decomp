typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *); };
struct VObj { char pad[4]; VEntry *vtbl; };
static inline s32 vcall(char *o) {
    VEntry *e = (VEntry *)((char *)((VObj *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}
extern "C" void func_001DC650(void *, void *) throw();
extern "C" void func_001DC5F8(void *, s32) throw();
extern "C" s32 func_001F4C88(s32);
extern "C" void func_001F4EB8(void *, s32, s32);
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void MNetwork__getGamePlayers(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4], buf1[4];
    s32 t1, nv, ov;
    s32 *p;
    func_001DC650(buf0, arg1);
    t1 = func_001F4C88(buf0[0]);
    if (arg2 > 0) t1 = vcall(*arg3);
    p = buf1;
    func_001F4EB8(p, buf0[0], t1);
    if (arg0 != p) {
        nv = *p;
        if (nv != 0) func_003285A8(nv);
        ov = *arg0;
        if (ov != 0) func_003285F8(ov);
        *arg0 = nv;
    }
    func_002ED5C0(p, 2);
    func_001DC5F8(buf0, 2);
}
