/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct Rep { s32 len, cap, ref, sel; };
struct S00659988 { const char *name; };
struct H { char *p; s32 pad[3]; };
struct Q { char pad[0x10]; s32 f10; };
struct Ob { s32 pad0; char *vt; };
struct Data { Ob *f0; Ob *f4; };
struct T { s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24; const char *f28; };
struct Buf { char b[0x20]; };
extern char D_00690BD8[];
extern char D_00690BE0[];
extern "C" s32 func_00171248(void *) throw();
extern "C" void func_001711F0(void *, s32) throw();
extern "C" void *func_005A48D8(void *, s32, s32);
extern "C" void func_0044B258(void *, void *, s32);
extern "C" s32 func_00431C60(const char *);
extern "C" void func_004320B8(s32, s32, s32, void *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
#define VE_AT(o, off) ((VE *)((o)->vt + (off)))
extern "C" void MLicenseRecordUnit__insertEntry(s32 a0, s32 a1, s32 mode, Data *d) {
    if (mode >= 2) {
        H h;
        func_00171248(&h);
        VE *e1 = VE_AT(d->f0, 0x58);
        s32 r1 = ((s32 (*)(void *))e1->fn)((char *)d->f0 + e1->delta);
        H s;
        H *ps = &s;
        VE *e3 = VE_AT(d->f4, 0x18);
        ((void (*)(H *, void *))e3->fn)(ps, (char *)d->f4 + e3->delta);
        const char *cs = D_00690BD8;
        if (((Rep *)ps->p)[-1].len != 0) {
            ps->p[((Rep *)ps->p)[-1].len] = 0;
            cs = ps->p;
        }
        Rep *q = (Rep *)((volatile H *)ps)->p - 1;
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
        T t;
        Buf buf;
        t.f0 = 0;
        t.f4 = 1;
        t.f10 = 1;
        t.f14 = 1;
        t.f18 = 1;
        t.f1C = r1;
        t.f20 = 1;
        t.f24 = 1;
        t.f28 = D_00690BE0;
        func_005A48D8(&buf, 0, 0x20);
        func_0044B258(&t, &buf, 0x20);
        s32 hv = ((Q *)h.p)->f10;
        s32 n = func_00431C60(cs);
        func_004320B8(hv, r1, n, &buf);
        func_001711F0(&h, 2);
    }
}
