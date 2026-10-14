/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x4c]; void *p; char pad2[0x84-0x50]; int state; };
extern "C" void func_004AF780(void *, Obj *);
extern "C" void func_004ADC40(int unused, Obj *o) {
    void *p = o->p;
    if (p != 0) return func_004AF780(p,o);
    o->state = 2;
}
