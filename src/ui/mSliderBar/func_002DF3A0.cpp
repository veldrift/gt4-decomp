/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct RefCounter;
struct VEntry { s16 delta; s16 pad; void (*fn)(void *, void *, s32, void *); };
struct Vt { char pad[4]; VEntry *vtbl; };
struct Obj {
    char pad0[0xC8];
    Vt *unkC8;
    s32 unkCC;
};

extern "C" void func_0023DDF0(void *, s32);
extern "C" void func_0023F8C8(s32, const char *);
extern "C" void func_0023FB80(void *);
extern "C" s32 func_00265D00(void *);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00309348(void *, void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0030BB18(void *);
extern "C" void func_003285A8(RefCounter *);
extern "C" void func_003285F8(RefCounter *);

extern char D_0069CF80[];

static inline void assign(s32 *dst, s32 *src) {
    if (dst != src) {
        s32 n = *src;
        if (n != 0)
            func_003285A8((RefCounter *)n);
        s32 old = *dst;
        if (old != 0)
            func_003285F8((RefCounter *)old);
        *dst = n;
    }
}

struct Value { s32 p; Value() { func_0030BB18(this); } };
extern "C" void func_002DF3A0(Obj *self, s32 a1, s32 a2) {
    s32 a[4];
    if (a2 != 0) {
        func_0023FB80(a);
        func_0023F8C8(a[0], D_0069CF80);
        func_0023DDF0(a, 2);
    }
    Vt **handle;
    if (func_00265D00(self) != 0 && *(handle = &self->unkC8) != 0) {
        func_0030BB18(a);
        Value b[2];
        s32 tmp[4];
        s32 *d = tmp;
        Value *dst = b;
        s32 t = a1;
        func_00309348(d, &t);
        assign(&dst->p, d);
        func_00309378(d, 2);
        dst = &b[1];
        func_002FE278(d, self->unkCC);
        assign(&dst->p, d);
        func_002FC870(d, 2);
        Vt *o = *handle;
        VEntry *e = o->vtbl + 0xA8 / 8;
        e->fn((char *)o + e->delta, a, 2, b);
        Value *p = b+2;
        while (b != p) {
            --p;
            func_00309378(p, 2);
        }
        func_00309378(a, 2);
    }
}
