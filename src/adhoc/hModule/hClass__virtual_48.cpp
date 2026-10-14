/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Handle { void *p; char pad[12]; };
struct Str { char *p; char pad[12]; };
struct Rep { int len, cap, ref, sel; };
struct Type { const char *name; };
struct Obj { int x; char *vt; };
struct E1 { short delta, index; void (*fn)(void *, void *); };
struct E2 { short delta, index; void (*fn)(void *, void *, void *); };
extern "C" void func_003041B8(void *, int) throw();
extern "C" void func_00304210(void *, void *) throw();
extern "C" void func_00307728(void *, int);
extern "C" void func_00307D90(void *, void *, void *, void *);
extern "C" void func_00309378(void *, int);
extern "C" void func_0030BB18(void *);
extern "C" int HSymID__GetID(void *);
extern "C" void func_00323B60(void *, int);
extern "C" void func_00323D08(void *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" Type *func_005C11A8();
static inline void assign(Handle *dst, Handle *src) {
    if (dst != src) {
        void *p = src->p;
        if (p) func_003285A8(p);
        void *old = dst->p;
        if (old) func_003285F8(old);
        dst->p = p;
    }
}
extern "C" void hClass__virtual_48(void *unused, Handle *out, void *arg2, int n, Handle *args) {
    Handle h;
    if (n == 1) {
        Handle id;
        Handle v;
        Handle *pv;
        Handle *pi;
        func_00304210(&h, arg2);
        {
            Str *ps = (Str *)&v;
            pi = &id;
            Obj *obj = (Obj *)args->p;
            E1 *e = (E1 *)(obj->vt + 0x18);
            e->fn(ps, (char *)obj + e->delta);
            pi->p = (void *)HSymID__GetID(ps);
            Rep *r = (Rep *)(ps->p - 16);
            if (--r->ref == 0) {
                int cap = r->cap + 16;
                func_00326798(r, cap, 4, func_005C11A8()->name);
            }
        }
        pv = &v;
        func_00323D08(pv);
        {
            Obj *obj = (Obj *)h.p;
            E2 *e = (E2 *)(obj->vt + 0x198);
            e->fn((char *)obj + e->delta, pv, pi);
        }
        if (pv->p == 0) {
            Handle temp;
            Handle *pt = &temp;
            func_0030BB18(pt);
            assign(out, pt);
            func_00309378(pt, 2);
        } else {
            Handle temp;
            Handle blank;
            Handle *pt;
            Handle *pb = &blank;
            func_0030BB18(pb);
            pt = &temp;
            func_00307D90(pt, pi, pb, pv);
            assign(out, pt);
            func_00307728(pt, 2);
            func_00309378(pb, 2);
        }
        func_00323B60(pv, 2);
        func_003041B8(&h, 2);
    } else {
        func_0030BB18(&h);
        assign(out, &h);
        func_00309378(&h, 2);
    }
}
