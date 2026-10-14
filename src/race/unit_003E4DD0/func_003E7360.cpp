/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char *base, *a, *b, *c, *d; };
extern "C" void func_00427698(void *);
extern "C" void func_00454410(void *);
static inline char *relocate(char *p, int delta) { return p ? p+delta : 0; }
extern "C" void func_003E7360(Obj *o) {
    int delta = (char *)o-o->base;
    if((char *)o != o->base) {
        o->a=relocate(o->a,delta);
        o->b=relocate(o->b,delta);
        o->c=relocate(o->c,delta);
        o->d=relocate(o->d,delta);
        o->base=(char *)o;
        func_00427698(o->a);
        func_00427698(o->b);
        func_00454410(o->c);
        func_00454410(o->d);
    }
}
