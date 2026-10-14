typedef int s32;
struct Rep { s32 len, cap, ref, sel; };
struct S00659988 { const char *name; };
struct Str { char *p; s32 pad[3]; };
struct VEntry { short delta; short index; void (*fn)(Str *, void *); };
struct Obj { char pad0[4]; char *vtbl; };
extern "C" void func_002BAAE0(void *, int) throw();
extern "C" void func_002BAB38(void *, void *) throw();
extern "C" void func_002BEB68(s32, Str *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void MModelFace__setModelMotionPath(void *arg0, void *arg1, s32 n, Obj **args) {
    s32 tmp[4];
    Str s;
    Str *ps;
    if (n > 0) {
        func_002BAB38(tmp, arg1);
        {
            Obj *o = *args;
            s32 h = tmp[0];
            ps = &s;
            VEntry *e = (VEntry *)(o->vtbl + 0x18);
            e->fn(ps, (char *)o + e->delta);
            func_002BEB68(h, ps);
        }
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_002BAAE0(tmp, 2);
    }
}
