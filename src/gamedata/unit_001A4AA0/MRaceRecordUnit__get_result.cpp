/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };
struct Bits { u32 low:4; u32 style:4; u32 rest:24; };
struct HO { char pad[0x10]; Bits *f10; };

extern Rep D_00659FA8;
extern char D_00692A98[];

extern "C" void func_001A4808(void *, int) throw();
extern "C" int func_001A4860(void *, void *) throw();
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" const char *func_00431C38(int);
extern "C" s32 func_00431C60(const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_00692A98;
    }
    s->p[len] = 0;
    return s->p;
}

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

struct Str2 { char *p; char pad[0x1C]; };

extern "C" void MRaceRecordUnit__get_result(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    s32 h[4];
    Str2 s1;
    Str s2;
    s32 hh[4];
    if (arg2 > 0) {
        func_001A4860(h, arg1);
        Bits *dst = ((HO *)(*(void **)h))->f10;
        vcall(&s1, arg3[0]);
        dst->style = func_00431C60(c_str((Str *)&s1));
        release((Str *)&s1);
        func_001A4808(h, 2);
    } else {
        s32 *phh = hh;
        Str *ps = &s2;
        func_001A4860(phh, arg1);
        HO *hp = *(HO **)phh;
        const char *name = func_00431C38(hp->f10->style);
        {
            Rep *r = &D_00659FA8;
            char *p;
            if (r->sel != 0) {
                p = func_005C2560(r);
            } else {
                p = (char *)(r + 1);
                r->ref++;
            }
            ps->p = p;
        }
        func_005C2630(ps, 0, -1, name, func_0057F260(name));
        func_00314B20(h, ps);
        if (arg0 != h) {
            s32 nv = h[0];
            if (nv != 0) func_003285A8(nv);
            if (*arg0 != 0) func_003285F8(*arg0);
            *arg0 = nv;
        }
        func_00312318(h, 2);
        release(ps);
        func_001A4808(phh, 2);
    }
}
