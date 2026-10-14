/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ref { char *p; int pad[3]; };
struct Node { Node *a; Node *b; Ref v; };
struct It { Node *n; int pad[3]; };
struct Obj { char pad0[0x24]; Node *list; };

extern char D_0069D2A8[];
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void hClass__structor_0(void *);
extern "C" void func_002F29D8(Ref *, void *);
extern "C" void func_002F29F0(void *, Ref *);
extern "C" void func_002F2A08(Ref *, int);
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" const char **func_005EC1E8(void);

static inline void construct(Ref *p, Ref *src) {
    if (p)
        func_002F29F0(p, src);
}

extern "C" void *func_002EB630(void *a0, char *a1, int a2) {
    Ref r0;
    It s10;
    It s20;
    It s30;
    It *p30 = &s30;
    char *s4 = a1 + 0x44;
    void *c = func_00326750(0x38, 4, D_0069D2A8);
    hClass__structor_0(c);
    s30.n = (Node *)c;
    func_002F29D8(&r0, p30);
    *(int *)(r0.p + 0x34) = a2;
    if (a2 != 0) {
        func_00576788(s4);
        s20.n = ((Obj *)a1)->list;
        Node *n = (Node *)func_00326750(0xC, 4, *func_005EC1E8());
        construct(&n->v, &r0);
        n->a = s20.n;
        n->b = s20.n->b;
        s20.n->b->a = n;
        s20.n->b = n;
        s10.n = n;
        func_005767C0(s4);
    }
    func_002F29F0(a0, &r0);
    func_002F2A08(&r0, 2);
    return a0;
}
