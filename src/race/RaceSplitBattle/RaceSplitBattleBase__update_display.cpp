/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VE { s16 d; s16 p; void *fn; };
typedef void *(*F0)(void *);
typedef void *(*F1)(void *, s32);
typedef void *(*F1f)(void *, float);
typedef void (*F1v)(void *, s32);
typedef void (*F1fv)(void *, float);

struct Obj { char *vtbl; s32 f4; };
struct Disp { char *vtbl; char pad[0x9BC - 4]; s32 cnt; };

struct Self {
    char pad0[0x64];
    char *tbl;
    char pad68[4];
    void *org;
};

extern "C" void func_00372080(void *, s32);
extern "C" s32 func_00373DA0(void *, s32);
extern "C" void RaceDisplay__commonPreUpdate(void *);
extern "C" void func_0039DA80(void *);

static inline VE *ve(void *o, s32 off) { return (VE *)(*(char **)o + off); }
static inline void *c0(void *o, s32 off) {
    VE *e = ve(o, off);
    return ((F0)e->fn)((char *)o + e->d);
}
static inline void *c1(void *o, s32 off, s32 a) {
    VE *e = ve(o, off);
    return ((F1)e->fn)((char *)o + e->d, a);
}
static inline void *c1f(void *o, s32 off, float a) {
    VE *e = ve(o, off);
    return ((F1f)e->fn)((char *)o + e->d, a);
}
static inline void c1v(void *o, s32 off, s32 a) {
    VE *e = ve(o, off);
    ((F1v)e->fn)((char *)o + e->d, a);
}
static inline void c1fv(void *o, s32 off, float a) {
    VE *e = ve(o, off);
    ((F1fv)e->fn)((char *)o + e->d, a);
}
static inline void *tc0(Self *s, s32 off) {
    VE *e = (VE *)(s->tbl + off);
    return ((F0)e->fn)((char *)s + e->d);
}
static inline void *tc1(Self *s, s32 off, s32 a) {
    VE *e = (VE *)(s->tbl + off);
    return ((F1)e->fn)((char *)s + e->d, a);
}

extern "C" void RaceSplitBattleBase__update_display(Self *self, float f) {
    s32 i = 0;
    RaceDisplay__commonPreUpdate(self->org);
    Obj *o = (Obj *)tc0(self, 0x4C8);
    do {
        Disp *d = (Disp *)tc1(self, 0xD0, 0);
        func_00372080(d, i);
        o->f4 = i;
        c1v(o, 0x50, i);
        c1v(o, 0x58, *(s16 *)((char *)d + d->cnt * 0x19C + 0x1C));
        c1(o, 0x60, (s32)c0(d, 0x120));
        s32 r = func_00373DA0(d, i);
        i++;
        c1(o, 0x70, r);
        c1v(o, 0x78, (s32)c0(d, 0x1B0));
    } while (i < 2);
    c1fv(o, 0x10, f);
    func_0039DA80(self->org);
}
