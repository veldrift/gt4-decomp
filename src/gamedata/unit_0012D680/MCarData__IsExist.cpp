/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; s32 pad[3]; };
union U { Str s; s32 h[4]; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj { char pad[4]; VEntry *vtbl; };
struct Equip { char pad[0x180]; };

extern char D_0068E7F8[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_00444190(Equip *);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(Equip *, int);
extern "C" s32 func_004443A8(Equip *, const char *);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0068E7F8;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}

extern "C" void MCarData__IsExist(s32 *arg0, s32 arg1, VObj **arg2) {
    if (arg1 > 0) {
        U u;
        Equip eq;
        const char *c;
        s32 found;
        vcall(&u, *arg2);
        c = c_str(&u.s);
        release(&u.s);
        func_00444190(&eq);
        found = func_004443A8(&eq, c) != 0;
        func_002FE278(&u, found);
        if (arg0 != u.h) {
            s32 newVal = u.h[0];
            s32 oldVal;
            if (newVal != 0) func_003285A8(newVal);
            oldVal = *arg0;
            if (oldVal != 0) func_003285F8(oldVal);
            *arg0 = newVal;
        }
        func_002FC870(&u, 2);
        SPEC_DATABASE__CarEquipments__setVariationOrder(&eq, 2);
    }
}
