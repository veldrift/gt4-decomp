/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct VEnt { s16 delta; s16 idx; void (*fn)(void *, void *); };
struct VT { char pad[0x18]; VEnt e; };
struct Obj { char pad[4]; VT *vt; };
union U { Str s; char *o[4]; char buf[0x10]; };

extern char D_006927F0[];
extern char D_006927F8[];
extern char D_00692800[];
extern char D_0068BB20[];
extern "C" void func_001A0AF8(void *, s32) throw();
extern "C" s32 func_001A0B50(void *) throw();
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_00447188(s32, const char *);
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" S00659988 *func_005C11A8(void);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MRaceData__global_00825AF8(s32 arg0, s32 arg1, s32 arg2, Obj **arg3) {
    U u;
    char buf[0x80];
    if (arg2 > 0) {
        func_001A0B50(&u);
        s32 h = (s32)u.o[0] + 0x10;
        func_001A0AF8(&u, 2);
        Obj *a2 = *arg3;
        VEnt *e = &a2->vt->e;
        e->fn(&u, (char *)a2 + e->delta);
        const char *c = D_006927F0;
        if (str_length(&u.s) != 0) {
            str_terminate(&u.s);
            c = rep_data(str_rep(&u.s));
        }
        release(&u.s);
        if (func_00447188(h, c) == 0) {
            func_0057DA20(buf, D_006927F8, D_0068BB20, c);
            if (func_00447188(h, buf) == 0) {
                func_0057DA20(u.buf, D_006927F8, D_00692800, c);
                func_00447188(h, u.buf);
            }
        }
    }
}
