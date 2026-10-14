/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { int pad0; Node *p4; int p8; Node *pC; };
struct Obj { int type; void *ptr; };
struct A { short cnt; };
struct B { int cnt; char pad[0x10]; Obj inner; };
struct C { int cnt; Node list; char pad[0x4]; Obj inner; };
extern "C" void free(void *) throw();
extern "C" void func_005C1628(void *) throw();
extern "C" void func_005C1648(void *);
extern "C" void func_00606258(void *, void *);
extern "C" void func_004768C0(Obj *o) {
    int t = o->type;
    if (t == 3) {
        A *a = (A *)o->ptr;
        if (--a->cnt == -1) func_005C1648(a);
    } else if (t == 13) {
        B *b = (B *)o->ptr;
        int n = b->cnt - 1;
        b->cnt = n;
        if (n == -1) {
            func_004768C0(&b->inner);
            func_005C1628(b);
        }
    } else if (t == 7) {
        C *c = (C *)o->ptr;
        int n = c->cnt - 1;
        c->cnt = n;
        if (n == -1) {
            func_004768C0(&c->inner);
            Node *l = &c->list;
            if (l->p8) {
                func_00606258(l, l->p4->p4);
                *(Node **)&l->p4->p8 = l->p4;
                l->p4->p4 = 0;
                l->p4->pC = l->p4;
                l->p8 = 0;
            }
            free(l->p4);
            func_005C1628(c);
        }
    }
    o->type = 1;
}
