/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct R { s32 ok; char pad[0x14]; };
struct Obj { char pad[0x14]; s32 f14; };
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_00565BA8(Obj *p, int a1, void *a2, int a3, int *out);
extern "C" R func_005534E0(Obj *obj) {
    R r;
    int out;
    func_005A48D8(&r, 0, 0x18);
    if (obj->f14 == 0) return r;
    func_00565BA8(obj, 0, &r, 0x18, &out);
    r.ok = (out != 0);
    return r;
}
