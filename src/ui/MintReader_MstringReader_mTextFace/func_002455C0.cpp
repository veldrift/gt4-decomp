/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Face { char pad[0x2C]; float sx, sy, bx, by; };
struct Obj { char pad[0xA0]; Face face; };
extern "C" void func_00245408(Obj *, float *, float *) throw();
extern "C" void mWidget__getWindowSize(Obj *, float *, float *);
static inline Face *getface(Obj *o) { return &o->face; }
extern "C" void func_002455C0(Obj *o) {
    float tw, th, ww, wh;
    func_00245408(o, &tw, &th);
    mWidget__getWindowSize(o, &ww, &wh);
    if (ww < tw) getface(o)->sx = ww / tw * getface(o)->bx;
    if (wh < th) getface(o)->sy = wh / th * getface(o)->by;
}
