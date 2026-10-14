/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { int a, b; float c; };
struct Obj00228A38 { char pad[0x10]; float x, y; int z; Sub sub; };
extern "C" float func_00228A38(Obj00228A38 *);
extern "C" void func_002289C0(Obj00228A38 *o, float x, float y) {
    Sub *p = &o->sub;
    o->x = x;
    o->y = y;
    o->z = 0;
    p->c = func_00228A38(o);
}
