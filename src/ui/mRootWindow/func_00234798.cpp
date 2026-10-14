/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct N34798 { N34798 *a; N34798 *b; s32 c; };
struct Iter { N34798 *p; Iter(N34798 *n) : p(n) {} Iter(const Iter &i) : p(i.p) {} };
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void *func_005DBBC0(void);
inline Iter insert(Iter pos, const s32 &value) {
    N34798 *n = (N34798 *)func_00326750(0xC, 4, (const char *)*(void **)func_005DBBC0());
    s32 *pc = &n->c;
    if (pc != 0) *pc = value;
    n->a = pos.p;
    n->b = pos.p->b;
    pos.p->b->a = n;
    pos.p->b = n;
    return Iter(n);
}
extern "C" void func_00234798(void *arg0, s32 arg1) {
    s32 value = arg1;
    Iter result = insert(Iter(*(N34798 **)((char *)arg0 + 0xC4)), value);
}
