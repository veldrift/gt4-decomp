/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
struct VEnt { s16 delta; s16 pad; void *(*fn)(void *); };
struct Obj { char pad[4]; char *vt; };
struct OS { char *p; char pad[0xC]; };

extern char D_0069D728[];
extern char D_0069D730[];
extern char D_0069D738[];

extern "C" const char *hModule__getName(void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_0032B5C0(void *);
extern "C" void *func_0032B808(void *, const char *);
extern "C" Str *func_0032B8C0(void *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

extern "C" Str *hClass__toString(Str *ret, Obj *self) {
    OS os;
    func_0032B5C0(&os);
    void *r1 = func_0032B808(&os, D_0069D728);
    VEnt *e = (VEnt *)(self->vt + 0x50);
    void *n = e->fn((char *)self + e->delta);
    void *r2 = func_0032B808(r1, hModule__getName(n));
    void *r3 = func_0032B808(r2, D_0069D730);
    void *r4 = func_0032B808(r3, hModule__getName(self));
    func_0032B808(r4, D_0069D738);
    Str *src = func_0032B8C0(&os);
    {
        char *sp = src->p;
        Rep *q = (Rep *)sp - 1;
        char *p;
        if (q->sel != 0) {
            p = func_005C2560(q);
        } else {
            q->ref++;
            p = sp;
        }
        ret->p = p;
    }
    {
        Rep *q = (Rep *)(os.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    return ret;
}
