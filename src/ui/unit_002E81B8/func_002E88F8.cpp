/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
struct VE { s16 delta; s16 index; void (*fn)(void *, void *, int, float *, float); };
struct VE2 { s16 delta; s16 index; void (*fn)(void *, int); };
struct Obj1 { char pad0[4]; char *vtbl; };
struct Obj0 {
    char pad0[0xB8];
    int mode;
    float fBC;
    int iC0;
    char padC4[4];
};
extern "C" float mWidget__getWindowW(void *);
extern "C" float mWidget__getWindowH(void *);
extern "C" int func_002861D8(Obj0 *, int);

extern "C" void func_002E88F8(Obj0 *a0, Obj1 *a1) {
    int r = func_002861D8(a0, 0);
    VE2 *e = (VE2 *)(a1->vtbl + 0x198);
    e->fn((char *)a1 + e->delta, r);
    switch (a0->mode) {
    case 0: {
        float w = mWidget__getWindowW(a0);
        float h = mWidget__getWindowH(a0);
        float buf[2];
        buf[0] = w;
        buf[1] = h;
        VE *v = (VE *)(a1->vtbl + 0x260);
        v->fn((char *)a1 + v->delta, (char *)a0 + 0xC4, a0->iC0, buf, a0->fBC);
        break;
    }
    case 1: {
        float w = mWidget__getWindowW(a0);
        float h = mWidget__getWindowH(a0);
        float buf[2];
        buf[0] = w;
        buf[1] = h;
        VE *v = (VE *)(a1->vtbl + 0x268);
        v->fn((char *)a1 + v->delta, (char *)a0 + 0xC4, a0->iC0, buf, a0->fBC);
        break;
    }
    }
}
