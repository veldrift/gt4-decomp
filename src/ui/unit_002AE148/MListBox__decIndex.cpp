struct Ref { char *p; int pad[3]; };
struct Obj { char *p; int pad[3]; };
struct VE { short delta; short idx; int (*fn)(void *); };
struct Hold { char *vt; };

extern "C" void func_002AE968(void *arg0, int arg1) throw();
extern "C" void func_002AE9C0(void *arg0) throw();
extern "C" int func_002B3C88(char *self, int count);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, int arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

static inline void assign(Ref *d, Ref *s) {
    if (d != s) {
        char *q = s->p;
        if (q) func_003285A8(q);
        if (d->p) func_003285F8(d->p);
        d->p = q;
    }
}

extern "C" void MListBox__decIndex(Ref *out, int a1, int count, Hold **a3) {
    Obj o;
    Ref r;
    func_002AE9C0(&o);
    int v = 1;
    if (count > 0) {
        char *obj = (char *)*a3;
        VE *ve = (VE *)(*(char **)(obj + 4) + 0x58);
        v = ve->fn(obj + ve->delta);
    }
    func_002FE278(&r, func_002B3C88(o.p, v) != 0);
    assign(out, &r);
    func_002FC870(&r, 2);
    func_002AE968(&o, 2);
}
