/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x860]; int flag; };
extern "C" void *func_004B5CC0(Obj *) throw();
extern "C" int func_004B7C20(Obj *);
extern "C" int func_004B7D18(Obj *);
extern "C" int func_004B7BA0(Obj *obj) {
    if (obj->flag != 0) return 1;
    signed char c = *(signed char *)func_004B5CC0(obj);
    if (c == 3) return func_004B7D18(obj);
    if (c != 4) return func_004B7C20(obj);
    return func_004B7D18(obj);
}
