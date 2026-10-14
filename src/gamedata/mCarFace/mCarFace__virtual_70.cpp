/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x, y, w, h; };
struct Obj;
struct Entry {
    short delta, index;
    void (*fn)(void *, void *, void *, Vec4 *, void *, void *, void *, int);
};
struct Obj { int x; Entry *vt; };
struct Self { char pad[0x29c]; int field29c; int field2a0; Obj *obj; };
extern "C" void mWidget__virtual_70(void *, void *, int);
extern "C" float func_002313E0(void *);
extern "C" float func_00231400(void *);
extern "C" float mWidget__getWindowW(void *);
extern "C" float mWidget__getWindowH(void *);
extern "C" void mCarFace__virtual_70(Self *self, void *arg1, int arg2) {
    Obj **holder = &self->obj;
    mWidget__virtual_70(self, arg1, 0);
    if (arg2 && *holder) {
        float x = func_002313E0(arg1);
        float y = func_00231400(arg1);
        float w = mWidget__getWindowW(self);
        float h = mWidget__getWindowH(self);
        Vec4 rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        Obj *obj = *holder;
        Entry *e = obj->vt + 58;
        e->fn((char *)obj + e->delta, arg1, (char *)self + 0xcc, &rect,
              (char *)self + 0xa0, (char *)self + 0xd0, (char *)self + 0x138, self->field29c);
    }
}
