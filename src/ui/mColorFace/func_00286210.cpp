/* compiler: ee-gcc2.96-nogcse */
struct Elem { float r,g,b,a; };
struct Vec { int pad; Elem *begin; Elem *end; };
extern "C" Elem *func_002030E8(Elem *, Elem *);
static inline int size(Vec *v) { return v->end - v->begin; }
static inline int clamp(int i, int n) { return i < n ? i : n - 1; }
static inline Elem *at(Vec *v, int i) { return v->begin + i; }
extern "C" void func_00286210(char *self, Elem *color, int index) {
    Vec *v = (Vec *)(self + 0xA0);
    int n = size(v);
    if (index < 0) {
        for (int i = 0; i < n; i++) func_002030E8(at(v, i), color);
    } else {
        index = clamp(index, n);
        func_002030E8(at(v, index), color);
    }
}
