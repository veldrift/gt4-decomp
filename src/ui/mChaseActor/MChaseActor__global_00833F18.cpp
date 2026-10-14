/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VObj;
struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
struct H { VObj *p; };
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void func_002836B0(void *, int) throw();
extern "C" void func_00283708(void *, void *) throw();
extern "C" void func_002841C0(void *, s32);
extern "C" void MChaseActor__global_00833F18(void *unused, void *a1, s32 a2, void *a3) {
    H h;
    s32 s1 = 0;
    if (a2 > 0) {
        func_00255110(&h, a3);
        s1 = (s32)h.p;
        func_002550B8(&h, 2);
    }
    func_00283708(&h, a1);
    VEntry *e = (VEntry *)(h.p->vtbl + 0x190);
    e->fn((char *)h.p + e->delta);
    func_002841C0(h.p, s1);
    func_002836B0(&h, 2);
}
