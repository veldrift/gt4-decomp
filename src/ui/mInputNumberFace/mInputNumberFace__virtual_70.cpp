/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };

struct Strm;
struct VEnt {
    short adj;
    short pad;
    void (*fn)(Strm *, int);
};
struct VEnt1 {
    short adj;
    short pad;
    void (*fn)(Strm *);
};
struct VTab {
    char pad[0x1C0];
    VEnt e0;
    VEnt1 e1;
};
struct Strm {
    s32 pad0;
    VTab *vt;
};

struct Self {
    char pad0[0xA0];
    char sub[0x64];
    char *str;
    s32 v108;
};

extern Rep D_00659FA8;
extern char D_0069B920[];
extern "C" void func_00231170(void *, void *);
extern "C" void func_00247428(void *);
extern "C" void func_002472B8(void *, void *);
extern "C" void mWidget__virtual_70(void *, void *, int);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057DA20(void *, const char *, s32);
extern "C" s32 func_0057F260(const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

extern "C" void mInputNumberFace__virtual_70(Self *self, Strm *strm, int flag) {
    char buf[0x20];

    s32 sA0[4];
    mWidget__virtual_70(self, strm, 0);
    if (flag != 0) {
        char *sub = self->sub;
        VEnt *e = &strm->vt->e0;
        e->fn((Strm *)((char *)strm + e->adj), 0);
        func_002472B8(sub, strm);
        const char *a;
        {
            char **ps = &self->str;
            Rep *r = (Rep *)(*ps - 0x10);
            if (r->len == 0) {
                a = D_0069B920;
            } else {
                (*ps)[r->len] = 0;
                a = *ps;
            }
        }
        func_0057DA20(buf, a, self->v108);
        s32 *pA0 = sA0;
        char *pb = buf;
        {
            Rep *d = &D_00659FA8;
            char *p;
            if (d->sel != 0) {
                p = func_005C2560(d);
            } else {
                p = (char *)d + 0x10;
                d->ref++;
            }
            pA0[0] = (s32)p;
        }
        func_005C2630(pA0, 0, (u32)-1, pb, func_0057F260(pb));
        func_00231170(strm, pA0);
        {
            Rep *q = (Rep *)(pA0[0] - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_00247428(sub);
        VEnt1 *e2 = &strm->vt->e1;
        e2->fn((Strm *)((char *)strm + e2->adj));
    }
}
