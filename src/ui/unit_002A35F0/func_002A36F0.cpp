/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Obj { char pad[0xbc]; int active; int handles[2]; union { u32 flags; struct { u32 low:3; u32 toggle:1; u32 rest:28; } b; }; };
extern "C" void *func_00218AD0(void *, int, int);
extern "C" void func_00210710(void *, int);
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
extern "C" void func_002A36F0(Obj *o, int a1, int a2) {
    int buf[4];
    o->active = 0;
    o->b.toggle = ~(o->flags >> 3);
    int *dst = &o->handles[o->b.toggle];
    func_00218AD0(buf, a1, a2);
    if (dst != buf) {
        int n = buf[0];
        if (n) func_003285A8(n);
        int old = *dst;
        if (old) func_003285F8(old);
        *dst = n;
    }
    func_00210710(buf, 2);
    int *src = &o->handles[o->b.toggle];
    o->active = *src;
}
