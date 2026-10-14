/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int pad; int v; };
extern char D_0068BB20[];
extern char D_006A5878[], D_006A5880[], D_006A5888[], D_006A5890[], D_006A5898[];
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" void func_00435D48(O *o) {
    if (func_0057F238(D_0068BB20, D_006A5878) == 0) return (void)(o->v = 1);
    if (func_0057F238(D_0068BB20, D_006A5880) == 0) return (void)(o->v = 2);
    if (func_0057F238(D_0068BB20, D_006A5888) == 0) return (void)(o->v = 4);
    if (func_0057F238(D_0068BB20, D_006A5890) == 0) return (void)(o->v = 1);
    if (func_0057F238(D_0068BB20, D_006A5898) == 0) return (void)(o->v = 5);
    return (void)(o->v = 1);
}
