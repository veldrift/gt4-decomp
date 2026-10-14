/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[2]; unsigned char m2, m3; };
extern "C" int func_00359A08(Obj *, int) throw();
extern "C" int func_00359A18(Obj *, int) throw();
extern "C" int func_00359A28(Obj *, int) throw();

extern "C" int func_00359A38(Obj *o, int a, int b, int c) {
    int x = func_00359A08(o, a);
    x = (x != 0) & (func_00359A18(o, b) != 0);
    x = (x != 0) & (func_00359A28(o, c) != 0);
    o->m2 = 0;
    o->m3 = 0;
    return x;
}
