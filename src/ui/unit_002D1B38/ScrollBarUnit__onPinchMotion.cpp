/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Widget { char pad[0xb8]; float origin; };
struct Obj { int word; int horizontal; char p8[0xc]; float value; char p18[0x14]; Widget *parent; Widget *child; };
struct Event { char pad[0x20]; float x, y; };
extern "C" float mWidget__getWindowW(Widget *);
extern "C" float mWidget__getWindowH(Widget *);
extern "C" void func_0025BAA0(Widget *, float *, float *, float *, float *);
extern "C" float func_002D2218(Obj *) throw();
extern "C" int ScrollBarUnit__onPinchMotion(Obj *self, int unused, Event *ev) {
    float x, y, w, h;
    float base, delta;
    if (!self->parent) return 1;
    if (!self->child) return 1;
    {
        func_0025BAA0(self->parent, &x, &y, &w, &h);
        Widget *child = self->child;
        base = child->origin;
        float max;
        if (self->horizontal) {
            delta = ev->x - x;
            max = w - mWidget__getWindowW(child) + base;
        } else {
            delta = ev->y - y;
            max = h - mWidget__getWindowH(child) + base;
        }
        float v = delta;
        if (v < base) v = base;
        if (max < v) v = max;
        base = v - base;
        base /= func_002D2218(self);
        self->value = base;
    }
    return 1;
}
