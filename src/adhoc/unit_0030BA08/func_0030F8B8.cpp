/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Elem { int x; };
struct Vec { int alloc; Elem *start, *finish, *end; };
extern "C" void func_005DB7E0(Vec *, Elem *, const Elem *);
extern "C" void func_0030F8B8(Vec *v) {
    const Elem *p = v->start;
    if (v->finish != v->end) {
        if (v->finish) *v->finish = *p;
        ++v->finish;
    } else {
        func_005DB7E0(v, v->finish, p);
    }
}
