/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len; int cap; int ref; int sel; };
struct Str { char *p; int pad[3]; };
struct Type { const char *name; };
struct VEntry { short delta; short index; void (*fn)(Str *, void *); };
struct Obj { int pad; char *vtbl; };
extern "C" void func_00304210(void *, void *);
extern "C" void func_003041B8(void *, int) throw();
extern "C" void func_00306130(int, int *);
extern "C" int HSymID__GetID(Str *);
extern "C" Type *func_005C11A8(void);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void Module__removeStatic(void *arg0, void *arg1, int n, Obj **args) {
    int tmp[4];
    int sym[4];
    Str s;
    Str *ps;
    int *pi;
    func_00304210(tmp, arg1);
    if (n == 1) {
        ps = &s;
        pi = sym;
        Obj *o = *args;
        int h = tmp[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x18);
        e->fn(ps, (char *)o + e->delta);
        *pi = HSymID__GetID(ps);
        func_00306130(h, pi);
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            int cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    func_003041B8(tmp, 2);
}
