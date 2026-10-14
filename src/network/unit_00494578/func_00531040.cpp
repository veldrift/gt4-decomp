/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long T __attribute__((aligned(4)));
struct Pair { T value; } __attribute__((packed));
struct State { int x; Pair p; };
static inline Pair *member(State *s) { return &s->p; }
struct Ops { char pad[0x70]; int (*test)(T); };
extern State D_00868698;
extern Ops *D_0064B4B0;
extern "C" void func_00530F98(Pair *) throw();
extern "C" int func_00531040(Pair *p) {
    Pair *q = member(&D_00868698);
    *p = *q;
    if (D_0064B4B0->test(p->value)) {
        func_00530F98(p);
        *q = *p;
    }
    return 0;
}
