/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Pair { float a; float b; };
struct Hdr { char pad[0xC0]; s32 lim; Pair p[1]; };
struct VObj;
struct VEntryP { s16 delta; s16 index; void *(*fn)(void *, s32); };
struct VEntryI { s16 delta; s16 index; s32 (*fn)(void *); };
struct VEntryF { s16 delta; s16 index; float (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
struct Hold { Hdr *p; char pad[12]; };
struct Arr { VObj *p; char pad[12]; };

extern "C" void func_0029E7F0(void *, int) throw();
extern "C" void func_0029E848(void *, void *) throw();
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002ED618(void *, void *);
extern "C" s32 hArray__size(void *);

static inline void *vc70(VObj *o, s32 i) {
    VEntryP *e = (VEntryP *)(o->vtbl + 0x70);
    return e->fn((char *)o + e->delta, i);
}
static inline float vc60(VObj *o) {
    VEntryF *e = (VEntryF *)(o->vtbl + 0x60);
    return e->fn((char *)o + e->delta);
}
static inline s32 vc58(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline Pair *point(Pair *base, s32 index) { return base + index; }

extern "C" void MGraphFace__changePoints(void *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Hold sp0;
    func_0029E848(&sp0, arg1);
    if (arg2 > 0) {
        Arr h;
        Arr *ph = &h;
        Pair *base = sp0.p->p;
        func_002ED618(ph, arg3);
        s32 cnt = hArray__size(ph->p);
        s32 start = 0;
        if (arg2 >= 2) {
            start = vc58(arg3[1]);
        }
        s32 j = 0;
        s32 lim = sp0.p->lim;
        if (j < cnt && j + start < lim) {
            Arr t;
            Arr *pt = &t;
            for (; j < cnt && j + start < lim;) {
                s32 i = j + start;
                void *r = vc70(ph->p, j);
                Pair *dst = point(base, i);
                j++;
                func_002ED618(pt, r);
                VObj *x = *(VObj **)vc70(pt->p, 0);
                float f = vc60(x);
                VObj *y = *(VObj **)vc70(pt->p, 1);
                float g = vc60(y);
                dst->a = f;
                dst->b = g;
                func_002ED5C0(pt, 2);
            }
        }
        func_002ED5C0(ph, 2);
    }
    func_0029E7F0(&sp0, 2);
}
