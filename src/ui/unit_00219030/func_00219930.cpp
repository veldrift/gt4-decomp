typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct VE { short d; short i; void (*fn)(void *, s32); };
struct Inner { char pad[4]; char *vt; };
struct Handle { Inner *o; char pad[0xC]; };
struct Arg1 { char pad[0x24]; void *f24; };

extern Rep D_00659FA8;
extern "C" void func_00213090(void *, void *, void *) throw();
extern "C" void func_002292F8(void *, void *);
extern "C" void func_002550B8(void *, int);
extern "C" void func_00306638(void *, void *, void *);
extern "C" void func_00323B60(void *, int);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);
extern char D_00697C40[];

extern "C" void *func_00219930(void *arg0, Arg1 *arg1, s32 arg2) {
    Handle h;
    Str s;
    Str *ps = &s;
    const char *name = D_00697C40;
    {
        Rep *r = &D_00659FA8;
        char *p = (char *)(r + 1);
        if (r->sel != 0)
            p = func_005C2560(r);
        else
            r->ref++;
        ps->p = p;
    }
    func_005C2630(ps, 0, -1, name, func_0057F260(name));
    func_00213090(&h, arg1, ps);
    {
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
    {
        Inner *o = h.o;
        VE *ve = (VE *)(o->vt + 0x190);
        ve->fn((char *)o + ve->d, arg2);
    }
    func_00306638(ps, arg1->f24, &h);
    func_00323B60(ps, 2);
    func_002292F8(arg0, &h);
    func_002550B8(&h, 2);
    return arg0;
}
