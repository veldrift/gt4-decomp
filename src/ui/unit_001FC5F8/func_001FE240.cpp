/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x84]; int a, b; char pad2[0x28]; int handle; };
extern "C" int func_0054EC70(int);
extern "C" int func_001FE240(Obj *o) {
 int r = 0;
 int h = o->handle;
 if (h == 0) return r;
 r = func_0054EC70(h);
 if (r != 0) return r;
 o->b = 0; o->a = 0;
 return r;
}
