/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct Q { char pad[0x10]; s32 f10; };
struct H { Q *p; s32 pad[3]; };
struct VEntryB { short delta; short index; void (*fn)(Str *, void *); };
struct Obj { char pad0[4]; char *vtbl; };
extern char D_006901F0[];
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0015F388(void *, int) throw();
extern "C" void func_0015F3E0(void *, s32) throw();
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" s32 mWidget__GetClassID(void);
extern "C" const char *hModule__getName(void *);
extern "C" s32 hObject__isInstanceOf(Obj *, s32);
extern "C" void func_0042FC10(s32, const char *);

extern "C" void MGame__set_major_menu_page(void *unused, s32 arg1, s32 a2, Obj **arg3) {
    const char *key;
    Obj *obj = *arg3;
    if (hObject__isInstanceOf(obj, mWidget__GetClassID())) {
        H h1;
        func_00255110(&h1, arg3);
        key = hModule__getName(h1.p);
        func_002550B8(&h1, 2);
    } else {
        Str s;
        Obj *o = *arg3;
        VEntryB *e = (VEntryB *)(o->vtbl + 0x18);
        e->fn(&s, (char *)o + e->delta);
        const char *cs = D_006901F0;
        s32 len = ((Rep *)s.p - 1)->len;
        if (len) {
            s.p[len] = 0;
            cs = s.p;
        }
        key = cs;
        {
            Rep *q = (Rep *)s.p - 1;
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
    H h;
    func_0015F3E0(&h, arg1);
    func_0042FC10(h.p->f10 + 0x3A368, key);
    func_0015F388(&h, 2);
}
