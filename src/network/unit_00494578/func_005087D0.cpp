struct Obj { int a,b,response,d,type; };
extern "C" void func_00508840(Obj *);
extern "C" void func_00508F90(Obj *);
extern "C" void func_0057D9C0(const char *, ...);
extern char D_006C15B8[];
extern "C" void func_005087D0(int a, int b, int c, Obj *o) {
    if (o->type == 2 || o->type == 4) return func_00508840(o);
    if (o->type == 6 || o->type == 8) return func_00508F90(o);
    if (o->response) func_0057D9C0(D_006C15B8, o->response);
}
