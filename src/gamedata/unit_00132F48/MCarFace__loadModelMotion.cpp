/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct VEntS { s16 delta; s16 pad; void (*fn)(void *, void *); };
struct VEntI { s16 delta; s16 pad; s32 (*fn)(void *); };
struct VEntF { s16 delta; s16 pad; f32 (*fn)(void *); };
struct VT { char pad[0x18]; VEntS e18; char pad1[0x58 - 0x18 - 8]; VEntI e58; VEntF e60; };
struct VO { char pad[4]; VT *vt; };
extern "C" {
void func_00137D60(void *, int) throw();
void func_00137DB8(void *, s32) throw();
void func_0013A570(void *, void *, s32, s32, s32, f32);
void func_00326798(void *, s32, s32, const char *);
struct S00659988 *func_005C11A8(void);

void MCarFace__loadModelMotion(void *arg0, s32 arg1, s32 arg2, VO **arg3) {
    if (arg2 >= 2) {
        f32 f20;
        if (arg2 >= 5) {
            VO *o = arg3[4];
            VEntF *e = &o->vt->e60;
            f20 = e->fn((char *)o + e->delta);
        } else {
            f20 = 0.0f;
        }
        s32 s4 = 0;
        if (arg2 >= 4) {
            VO *o = arg3[3];
            VEntI *e = &o->vt->e58;
            s4 = e->fn((char *)o + e->delta) != 0;
        }
        s32 s3 = 0;
        if (arg2 >= 3) {
            VO *o = arg3[2];
            VEntI *e = &o->vt->e58;
            s3 = e->fn((char *)o + e->delta);
        }
        VO *o1 = arg3[1];
        VEntI *e1 = &o1->vt->e58;
        s32 s1 = e1->fn((char *)o1 + e1->delta);
        Str st;
        VO *o0 = arg3[0];
        VEntS *e0 = &o0->vt->e18;
        e0->fn(&st, (char *)o0 + e0->delta);
        void *h[4];
        void **ph = h;
        func_00137DB8(ph, arg1);
        func_0013A570(ph[0], &st, s1, s3, s4, f20);
        func_00137D60(ph, 2);
        Rep *q = (Rep *)st.p - 1;
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
}
}
