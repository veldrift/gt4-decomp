/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Obj { char pad[0x3104]; char buf[4]; };
extern "C" void func_00576100(Obj *);
extern "C" void func_00576140(Obj *);
extern "C" void *func_005A4724(void *, const void *, u32);
extern "C" void func_004FB110(Obj *o, const void *src, u32 n) {
    func_00576100(o);
    func_005A4724(o->buf, src, n);
    func_00576140(o);
}
