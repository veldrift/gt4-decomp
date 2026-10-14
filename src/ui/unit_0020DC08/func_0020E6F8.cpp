/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int allocator; int *start; int *finish; int *end; };
struct Obj { int x; int line; char pad[8]; Vec v; };
extern "C" void func_005D8920(Vec *, int *, const int *);
extern "C" void func_0020E6F8(Obj *o, int c) {
    Vec *v = &o->v;
    if (c == 10) --o->line;
    if (v->finish != v->end) {
        if (v->finish != 0) *v->finish = c;
        ++v->finish;
    } else {
        func_005D8920(v, v->finish, &c);
    }
}
