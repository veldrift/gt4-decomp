/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; s32 pad[3]; };
struct Self {
    char pad0[4];
    void *vt;
    char pad8[8];
    char sub[0x20];
    void *fn30;
    char pad34[0xFC - 0x34];
    char f_fc[4];
    char f_100[4];
    char *str;
    s32 f108;
    s32 f10c;
};

extern Rep D_00659FA8;
extern char mHttp__vtable[];
extern char mUpdateContext__Sync[];

extern "C" void func_001DC5F8(void *, s32);
extern "C" void func_001DC8F0(void *);
extern "C" void func_001F1080(Str *, s32);
extern "C" void func_002FA120(void *);
extern "C" void *hObject__structor_0(void *);
extern "C" void *func_0030BB18(void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_004E6BD8(void *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

static inline void release(char *p) {
    Rep *q = (Rep *)(p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

extern "C" void mHttp__structor_0(Self *self) {
    char **ps = &self->str;
    char *sub = self->sub - 0x10 + 0x10;
    hObject__structor_0(self);
    self->vt = mHttp__vtable;
    func_004E6BD8(sub);
    func_002FA120(self->f_fc);
    func_0030BB18(self->f_100);
    Rep *r = &D_00659FA8;
    char *d;
    if (r->sel != 0) {
        d = func_005C2560(r);
    } else {
        d = (char *)(r + 1);
        r->ref++;
    }
    *ps = d;
    self->f108 = 0;
    self->f10c = 0;
    s32 h[4];
    func_001DC8F0(h);
    Str tmp;
    Str *pt = &tmp;
    func_001F1080(pt, h[0]);
    if (pt != (Str *)ps) {
        release(*ps);
        Rep *sr = (Rep *)(pt->p - 0x10);
        char *c;
        if (sr->sel != 0) {
            c = func_005C2560(sr);
        } else {
            c = pt->p;
            sr->ref++;
        }
        *ps = c;
    }
    release(pt->p);
    *(char **)(sub + 0x20) = mUpdateContext__Sync;
    func_001DC5F8(h, 2);
}
