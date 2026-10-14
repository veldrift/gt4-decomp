/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
struct SS { char *p; s32 pad[3]; };
struct Obj { char pad0[4]; char *vtbl; };
struct Arg { char pad0[0x10]; Obj *f10; s32 f14; };
struct Hold { Obj *p; s32 pad[3]; };
struct VE68 { s16 delta; s16 index; s32 (*fn)(void *, s32); };
struct VE18 { s16 delta; s16 index; void (*fn)(void *, void *); };

extern char D_0069D658[];
extern char D_0069D668[];
extern char D_0069D670[];
extern char D_0069D678[];
extern char D_0069D680[];

extern "C" char *func_005C2560(Rep *r);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" int func_0032B5C0(SS *arg0);
extern "C" SS *func_0032B808(SS *arg0, const char *arg1);
extern "C" SS *func_0032B6D8(SS *arg0, s32 arg1);
extern "C" SS *func_0032B658(SS *arg0, SS *arg1);
extern "C" Str *func_0032B8C0(SS *arg0);
extern "C" void func_00309360(Hold *, s32);
extern "C" void func_00309378(Hold *, s32);

extern "C" Str *hArrayElement__toString(Str *ret, Arg *arg1) {
    SS ss;
    Hold h;
    SS tmp;
    Obj **pf = &arg1->f10;
    func_0032B5C0(&ss);
    if (*pf == 0) {
        func_0032B808(&ss, D_0069D658);
    } else {
        func_0032B808(func_0032B6D8(func_0032B808(&ss, D_0069D668), arg1->f14), D_0069D670);
        Obj *o = *pf;
        VE68 *e = (VE68 *)(o->vtbl + 0x68);
        s32 rv = e->fn((char *)o + e->delta, arg1->f14);
        Hold *ph = &h;
        func_00309360(ph, rv);
        if (ph->p == 0) {
            func_0032B808(&ss, D_0069D678);
        } else {
            VE18 *e2 = (VE18 *)(ph->p->vtbl + 0x18);
            SS *pt = &tmp;
            e2->fn(pt, (char *)ph->p + e2->delta);
            func_0032B808(func_0032B658(&ss, pt), D_0069D680);
            Rep *q = (Rep *)(pt->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_00309378(ph, 2);
    }
    {
        s32 p = *(s32 *)&func_0032B8C0(&ss)->p;
        Rep *r = (Rep *)(p - 0x10);
        s32 d;
        if (r->sel != 0) {
            d = (s32)func_005C2560(r);
        } else {
            d = p;
            r->ref++;
        }
        *(s32 *)&ret->p = d;
    }
    {
        Rep *q = (Rep *)(*(s32 *)&ss.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    return ret;
}
