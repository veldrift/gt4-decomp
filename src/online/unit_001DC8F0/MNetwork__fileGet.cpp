typedef int s32;
typedef short s16;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct VEntryI {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

extern char D_006959D8[];
extern Rep D_00659FA8;

extern "C" void func_001DC5F8(void *, int);
extern "C" void func_001DC650(void *, void *);
extern "C" unsigned char *func_001F7B58(void *, s32 *);
extern "C" void func_001F7CB8(void *, void *, const char *, s32, s32, s32, s32, s32);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002ED618(void *, void *);
extern "C" s32 hArray__size(void *);
extern "C" VObj **HArray__operator_index(void *, s32);
extern "C" s32 func_003122E8(void *, s32 *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" void free(void *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(void *, unsigned, unsigned, const char *, unsigned);

static inline void str_release(Str *s) {
    Rep *q = ((Rep **)s)[0] - 1;
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}

static inline s32 vcall58(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

extern "C" void MNetwork__fileGet(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    Str sp0;
    if (arg2 > 0) {
        Str t;
        Str h20;
        s32 sz30;
        Str h40;
        Str s50;
        s32 z60;
        s32 z64;
        s32 z68;
        Str *pt;
        const char *c;
        func_001DC650(&sp0, arg1);
        pt = &t;
        vcall18(pt, *arg3);
        c = c_str(pt);
        str_release(pt);
        func_001F7CB8(pt, sp0.p, c, 0, 100000000, -1, 0, 1);
        if (pt->p == 0) {
            Str *ph = &h20;
            z60 = 0;
            func_003122E8(ph, &z60);
            if ((void *)arg0 != (void *)ph) {
                void *p = ph->p;
                if (p != 0) {
                    func_003285A8(p);
                }
                if (*arg0 != 0) {
                    func_003285F8(*arg0);
                }
                *arg0 = p;
            }
            func_00312318(ph, 2);
            func_002ED5C0(pt, 2);
            func_001DC5F8(&sp0, 2);
        } else if (hArray__size(pt->p) == 0) {
            Str *ph = &h20;
            z64 = 0;
            func_003122E8(ph, &z64);
            if ((void *)arg0 != (void *)ph) {
                void *p = ph->p;
                if (p != 0) {
                    func_003285A8(p);
                }
                if (*arg0 != 0) {
                    func_003285F8(*arg0);
                }
                *arg0 = p;
            }
            func_00312318(ph, 2);
            func_002ED5C0(pt, 2);
            func_001DC5F8(&sp0, 2);
        } else {
            unsigned char *data;
            Str *p20;
            VObj **src = HArray__operator_index(pt, 0);
            p20 = &h20;
            func_002ED618(p20, src);
            sz30 = vcall58(*HArray__operator_index(p20, 1));
            data = func_001F7B58(sp0.p, &sz30);
            if (data == 0) {
                Str *ph = &h40;
                z68 = 0;
                func_003122E8(ph, &z68);
                if ((void *)arg0 != (void *)ph) {
                    void *p = ph->p;
                    if (p != 0) {
                        func_003285A8(p);
                    }
                    if (*arg0 != 0) {
                        func_003285F8(*arg0);
                    }
                    *arg0 = p;
                }
                func_00312318(ph, 2);
                func_002ED5C0(p20, 2);
                func_002ED5C0(pt, 2);
                func_001DC5F8(&sp0, 2);
            } else {
                Str *pq = &s50;
                Str *ph;
                s32 len = sz30;
                Rep *r = &D_00659FA8;
                char *d;
                if (r->sel != 0) {
                    d = func_005C2560(r);
                } else {
                    d = (char *)(r + 1);
                    r->ref++;
                }
                pq->p = d;
                func_005C2630(pq, 0, -1, (const char *)data, len);
                ph = &h40;
                func_00314B20(ph, pq);
                if ((void *)arg0 != (void *)ph) {
                    void *p = ph->p;
                    if (p != 0) {
                        func_003285A8(p);
                    }
                    if (*arg0 != 0) {
                        func_003285F8(*arg0);
                    }
                    *arg0 = p;
                }
                func_00312318(ph, 2);
                str_release(pq);
                free(data);
                func_002ED5C0(p20, 2);
                func_002ED5C0(pt, 2);
                func_001DC5F8(&sp0, 2);
            }
        }
    }
}
