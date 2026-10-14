/* compiler: ee-gcc2.96-nogcse */
struct Elem { float r, g, b, a; };
struct Vec { int x; Elem *lo; Elem *hi; };
struct Obj { char pad[0xB0]; Vec v; };
extern "C" Elem *func_002030E8(Elem *, Elem *);
extern "C" void mColorWindow__setColor_2(Obj *o, Elem *color, int index) {
    Vec *v = &o->v;
    int n = v->hi - v->lo;
    if (index < 0) {
        for (int i = 0; i < n; i++) {
            Elem *p = v->lo + i;
            func_002030E8(p, color);
        }
    } else {
        if (index >= n) index = n - 1;
        Elem *p = v->lo + index;
        func_002030E8(p, color);
    }
}
