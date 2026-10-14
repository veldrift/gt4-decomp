/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Dst { char pad[0x20]; s32 f20; s32 f24; float f28; float f2C; };
struct Holder { Dst *p; char pad[12]; };
struct VEntryI { s16 delta; s16 index; s32 (*fn)(void *); };
struct VEntryF { s16 delta; s16 index; float (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
struct Args { char pad[8]; VObj *o8; VObj *oC; VObj *o10; VObj *o14; };

extern "C" void func_0022ACC8(void *, int);
extern "C" void func_0022AD20(void *, void *);
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void func_0028EA10(void *, s32);
extern "C" void func_0028EA70(void *, s32);
extern "C" void func_002A9610(void *, int) throw();
extern "C" void func_002A9668(void *) throw();

static inline s32 vc58(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}
static inline float vc60(VObj *o) {
    VEntryF *e = (VEntryF *)(o->vtbl + 0x60);
    return e->fn((char *)o + e->delta);
}

extern "C" void MKeyEvent__global_00837318(void *arg0, void *arg1, s32 arg2, Args *arg3) {
    if (arg2 == 6) {
        Holder sp0;
        Holder a;
        Holder b;
        func_002A9668(&sp0);
        Holder *pa = &a;
        func_0022AD20(pa, arg3);
        Holder *pb = &b;
        func_00255110(pb, (char *)arg3 + 4);
        func_0028EA10(sp0.p, *(s32 *)pa);
        func_0028EA70(sp0.p, *(s32 *)pb);
        sp0.p->f20 = vc58(arg3->o8);
        sp0.p->f24 = vc58(arg3->oC);
        sp0.p->f28 = vc60(arg3->o10);
        sp0.p->f2C = vc60(arg3->o14);
        func_002550B8(pb, 2);
        func_0022ACC8(pa, 2);
        func_002A9610(&sp0, 2);
    }
}
