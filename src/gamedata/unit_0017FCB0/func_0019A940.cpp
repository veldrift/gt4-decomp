/* compiler: ee-gcc2.96-no-strict-aliasing */
struct In { char pad[0x3C]; volatile int f3c; };
struct H { In *p; };
struct O { char pad[0xA0]; H h; };
extern "C" void func_0019A698(O *, void *) throw();
extern "C" void func_0019A630();
extern "C" int func_001CA740(In *, void (*)(), void *);
static inline In *get(H *h) { return h->p; }
static inline bool busy(H *h) { return get(h)->f3c != 0; }
extern "C" int func_0019A940(O *o, void *a1)
{
    H *h = &o->h;
    if (busy(h)) return 0;
    func_0019A698(o, a1);
    return func_001CA740(get(h), func_0019A630, o);
}
