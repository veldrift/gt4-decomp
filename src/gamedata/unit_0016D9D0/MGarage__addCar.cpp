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
extern char D_00690A30[];
extern "C" s32 func_0016D848(void *) throw();
extern "C" void func_0016D7F0(void *, s32) throw();
extern "C" void func_002FE278(void *, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" s32 func_00435780(s32, const char *, s32, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
#define VE_AT(o, off) ((VE *)((o)->vt + (off)))
extern "C" void MGarage__addCar(s32 *out, s32 a1, s32 mode, Data *d) {
    if (mode >= 2) {
        H h;
        func_0016D848(&h);
        s32 s2 = ((Q *)h.p)->f10;
        func_0016D7F0(&h, 2);
        VE *e1 = VE_AT(d->f4, 0x58);
        s32 r1 = ((s32 (*)(void *))e1->fn)((char *)d->f4 + e1->delta);
        VE *e3 = VE_AT(d->f0, 0x18);
        ((void (*)(H *, void *))e3->fn)(&h, (char *)d->f0 + e3->delta);
        const char *cs;
        Rep *r = (Rep *)h.p - 1;
        if (r->len == 0) {
            cs = D_00690A30;
        } else {
            h.p[r->len] = 0;
            cs = h.p;
        }
        s2 = func_00435780(s2, cs, r1, 0);
        Rep *q = (Rep *)h.p - 1;
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
        func_002FE278(&h, s2);
        if (out != (s32 *)&h) {
            s32 nv = (s32)h.p;
            if (nv) func_003285A8(nv);
            if (*out) func_003285F8(*out);
            *out = nv;
        }
        func_002FC870(&h, 2);
    }
}
