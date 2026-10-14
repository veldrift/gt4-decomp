/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct VEntry { short delta; short index; void *fn; };
struct Obj { char pad0[4]; char *vtbl; };
struct VEntryA { short delta; short index; Obj **(*fn)(void *, s32); };
struct VEntryB { short delta; short index; void (*fn)(Str *, void *); };
struct Obj2 { char pad0[4]; char *vtbl; };
struct ObjA { char pad0[4]; char *vtbl; };

extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *r);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 hArray__size(void *) throw();
extern "C" void func_00314B20(void *, void *);
extern "C" void func_005CE388(Str *dst, s32 a, s32 b, Str *src, s32 c, s32 d);

extern "C" void *func_002EFD10(void *arg0, ObjA *arg1, Str *arg2) {
    Str s;
    Str t;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        s.p = d;
    }
    s32 n = hArray__size(arg1);
    s32 i = 0;
    if (n > 0) {
        Str *pt = &t;
        do {
            if (i > 0) {
                func_005CE388(&s, ((Rep *)s.p - 1)->len, 0, arg2, 0, -1);
            }
            VEntryA *e = (VEntryA *)(arg1->vtbl + 0x70);
            Obj **o = e->fn((char *)arg1 + e->delta, i);
            i++;
            ObjA *oo = (ObjA *)*o;
            VEntryB *e2 = (VEntryB *)(oo->vtbl + 0x18);
            e2->fn(pt, (char *)oo + e2->delta);
            func_005CE388(&s, ((Rep *)s.p - 1)->len, 0, pt, 0, -1);
            {
                Rep *q = (Rep *)pt->p - 1;
                if (--q->ref == 0) {
                    s32 cap = q->cap + 0x10;
                    func_00326798(q, cap, 4, func_005C11A8()->name);
                }
            }
        } while (i < n);
    }
    func_00314B20(arg0, &s);
    {
        Rep *q = (Rep *)s.p - 1;
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    return arg0;
}
