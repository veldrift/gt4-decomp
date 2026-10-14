/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[8]; char *inner; };
extern "C" void func_002F7060(char *, int, __builtin_va_list);
extern "C" void func_0020ED08(Obj *o, int fmt, ...) {
    __builtin_va_list ap;
    __builtin_stdarg_start(ap, fmt);
    func_002F7060(o->inner, fmt, ap);
}
