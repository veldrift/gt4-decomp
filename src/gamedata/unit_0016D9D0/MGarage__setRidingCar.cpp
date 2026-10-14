/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct Rep { s32 len, cap, ref, sel; };
struct S00659988 { const char *name; };
struct H { char *p; s32 pad[3]; };
typedef H Str;
struct Q { char pad[0x10]; s32 f10; };
struct Ob { s32 pad0; char *vt; };
struct Data { Ob *f0; Ob *f4; Ob *f8; };
extern char D_00690A30[];
extern "C" s32 func_0016D848(void *) throw();
extern "C" void func_0016D7F0(void *, s32) throw();
extern "C" void func_0013BDC0(void *, void *);
extern "C" s32 func_00147D80(void *);
extern "C" void func_0013BD68(void *, s32);
extern "C" void func_00435388(s32, s32, s32);
extern "C" void func_00435490(s32, s32, const char *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
#define VE_AT(o, off) ((VE *)((o)->vt + (off)))
extern "C" void MGarage__setRidingCar(s32 a0, s32 a1, s32 mode, Data *d) {
    H h;
    func_0016D848(&h);
    s32 s3 = ((Q *)h.p)->f10;
    func_0016D7F0(&h, 2);
    if (mode >= 3) {
        VE *e1 = VE_AT(d->f8, 0x58);
        s32 r1 = ((s32 (*)(void *))e1->fn)((char *)d->f8 + e1->delta);
        VE *e2 = VE_AT(d->f0, 0x58);
        s32 r2 = ((s32 (*)(void *))e2->fn)((char *)d->f0 + e2->delta);
        Str &s = h;
        VE *e3 = VE_AT(d->f4, 0x18);
        ((void (*)(Str *, void *))e3->fn)(&s, (char *)d->f4 + e3->delta);
        const char *cs = D_00690A30;
        Rep *r = (Rep *)s.p - 1;
        if (r->len != 0) {
            s.p[r->len] = 0;
            cs = s.p;
        }
        func_00435490(s3, r2, cs, r1);
        Rep *q = (Rep *)s.p - 1;
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    } else if (mode >= 2) {
        VE *e = VE_AT(d->f0, 0x58);
        s32 r2 = ((s32 (*)(void *))e->fn)((char *)d->f0 + e->delta);
        H &h2 = h;
        func_0013BDC0(&h2, &d->f4);
        func_00435388(s3, r2, func_00147D80((void *)h2.p));
        func_0013BD68(&h2, 2);
    }
}
