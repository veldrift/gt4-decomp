/* compiler: ee-gcc2.96-nogcse */
struct Elem { float r,g,b,a; };
struct Vec { int pad; union { Elem *begin; float alias; }; Elem *end; };
extern "C" void mMovieFace__virtual_58(char *self, int index, float alpha) {
    Vec *v = (Vec *)(self + 0xA0);
    int n = v->end - v->begin;
    if (index < 0) {
        for (index = 0; index < n; index++) { Elem *e = v->begin + index; e->a = alpha; }
        return;
    }
    Elem *e = v->begin;
    index = index < n ? index : n - 1;
    e += index;
    e->a = alpha;
}
