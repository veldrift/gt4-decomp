/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; int pad[3]; };
struct Type { const char *name; };
struct Obj { char pad[4]; char *vt; };
struct Ent { short delta, index; void (*fn)(void *, Str *); };
extern "C" void func_00261EC0(void **, void *) throw();
extern "C" Type *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_002625A8(Obj *self, void *arg1) {
    Str s;
    func_00261EC0((void **)&s, arg1);
    Ent *e = (Ent *)(self->vt + 0x190);
    e->fn((char *)self + e->delta, &s);
    Rep *q = (Rep *)(s.p - 0x10);
    if (--q->ref == 0) {
        int cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}
