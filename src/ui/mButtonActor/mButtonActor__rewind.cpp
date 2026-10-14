/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, int, float); };
struct Target { int word; char *vt; };
struct Obj {
    char pad0[0x14];
    void *widget;
    Target *target;
    char pad1[8];
    float x, y, w, h, value;
};
extern "C" void mWidget__setWindowX(void *, float);
extern "C" void mWidget__setWindowY(void *, float);
extern "C" void mWidget__setWindowW(void *, float);
extern "C" void mWidget__setWindowH(void *, float);
extern "C" void mButtonActor__rewind(Obj *o) {
    if (o->widget) {
        mWidget__setWindowX(o->widget, o->x);
        mWidget__setWindowY(o->widget, o->y);
        mWidget__setWindowW(o->widget, o->w);
        mWidget__setWindowH(o->widget, o->h);
    }
    Target *t = o->target;
    if (t) {
        VEntry *e = (VEntry *)(t->vt + 0x1D8);
        e->fn((char *)t + e->delta, -1, o->value);
    }
}
