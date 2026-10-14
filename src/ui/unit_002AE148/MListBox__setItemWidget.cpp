struct Ref { char *p; int pad[3]; };
struct Obj { char *p; int pad[3]; };
struct VE { short delta; short idx; int (*fn)(void *); };
struct Hold { char *vt; int a; int b; };

extern "C" void func_002AE968(void *arg0, int arg1) throw();
extern "C" void func_002AE9C0(void *arg0, int arg1) throw();
extern "C" void func_0022AC98(void *a, void *b);
extern "C" void func_0022ACC8(void *a, int b);
extern "C" void func_00255088(void *a, void *b);
extern "C" void func_002550B8(void *a, int b);
extern "C" void func_002B4FD8(void *a, int b, int c, int d);

static inline int *st(int *p, int v) { *p = v; return p; }

extern "C" void MListBox__setItemWidget(void *self, int a1, int count, Hold *a3) {
    if (count == 3) {
        Obj o;
        Ref r1;
        Ref r2;
        int t1;
        int t2;
        func_002AE9C0(&o, a1);
        Ref *p1 = &r1;
        func_0022AC98(p1, st(&t1, a3->a));
        int v2 = a3->b;
        int *q2 = &t2;
        Ref *p2 = &r2;
        *q2 = v2;
        func_00255088(p2, q2);
        char *obj = a3->vt;
        a3 = (Hold *)o.p;
        VE *ve = (VE *)(*(char **)(obj + 4) + 0x58);
        func_002B4FD8(a3, ve->fn(obj + ve->delta), (int)p1->p, (int)p2->p);
        func_002550B8(p2, 2);
        func_0022ACC8(p1, 2);
        func_002AE968(&o, 2);
    }
}
