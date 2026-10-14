/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct HO { char pad[0x10]; s32 f10; };
struct VEntS { s16 delta; s16 pad; void (*fn)(void *, void *); };
struct VEntI { s16 delta; s16 pad; s32 (*fn)(void *); };
struct VT { char pad[0x18]; VEntS e18; char pad1[0x58 - 0x18 - 8]; VEntI e58; };
struct VO { char pad[4]; VT *vt; };
extern char D_0068EAD8[];
extern "C" {
void func_00132D60(void *, int) throw();
void func_00132DB8(void *, void *) throw();
void func_00312318(void *, int);
void func_00312370(void *, void *);
Str *func_00314920(void *);
void func_00326798(void *, s32, s32, const char *);
s32 func_0042EF18(const char *);
void func_0042F3C0(s32, const char *, s32, s32);
struct S00659988 *func_005C11A8(void);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0068EAD8;
    str_terminate(s);
    return rep_data(str_rep(s));
}

void MCalendar__putBuyWheelEvent(void *arg0, void *arg1, s32 arg2, VO **arg3) {
    if (arg2 >= 3) {
        HO *h[4];
        func_00132DB8(h, arg1);
        s32 s4 = h[0]->f10;
        func_00132D60(h, 2);
        func_00312370(h, arg3);
        Str *r = func_00314920(h[0]);
        const char *s5 = c_str(r);
        s32 s3;
        {
            Str st;
            VO *o = arg3[1];
            VEntS *e = &o->vt->e18;
            e->fn(&st, (char *)o + e->delta);
            s3 = func_0042EF18(c_str(&st));
            Rep *q = str_rep(&st);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
        VO *o2 = arg3[2];
        VEntI *e2 = &o2->vt->e58;
        func_0042F3C0(s4, s5, s3, e2->fn((char *)o2 + e2->delta));
        func_00312318(h, 2);
    }
}
}
