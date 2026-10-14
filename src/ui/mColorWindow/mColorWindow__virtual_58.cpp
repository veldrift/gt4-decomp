/* compiler: ee-gcc2.96-nogcse */
union Elem;
struct Vec { int x; Elem *lo; Elem *hi; };
struct Obj { char pad[0xB0]; Vec v; };
union Elem { struct { float r, g, b, a; }; float fields[4]; };
extern "C" void mColorWindow__virtual_58(Obj *o, int index, float alpha) {
    Vec *v = &o->v;
    int n = v->hi - v->lo;
    if (index < 0) {
        for (index = 0; index < n; index++) {
            Elem *e = v->lo + index;
            e->a = alpha;
        }
        return;
    }
    int cond = index < n;
    int maxIdx = n - 1;
    index = cond ? index : maxIdx;
    Elem *e = v->lo + index;
    e->a = alpha;
}
