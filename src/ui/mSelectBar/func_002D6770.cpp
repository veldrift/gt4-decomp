/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Range { int index; int low; int high; int wrap; };
struct Obj { char pad[0xBC]; Range r; char padCC[8]; float scale; int d8; int wrap; int e0; float width; float height; float offset; };
extern "C" Obj *func_00206868(Obj *);
extern "C" int func_00206880(Obj *);
extern "C" void mWidget__setWindowW(Obj *, float);
extern "C" void mWidget__setWindowH(Obj *, float);
extern "C" Obj *func_0025C300(Obj *);
extern "C" float func_002D6598(Obj *) throw();
extern "C" void func_0057CD90(Range *, int, int);
extern "C" void func_002D6770(Obj *self) {
    Range *r = &self->r;
    func_0057CD90(r, 0, func_00206880(self));
    if (self->wrap) r->wrap = 1;
    else r->wrap = 0;
    if (func_00206868(self)) self->offset = func_002D6598(self);
    int i = 0;
    Obj *child = func_00206868(self);
    while (child) {
        float w = self->width;
        float h = self->height;
        if (i == r->index) {
            float k = self->scale;
            w *= k;
            h *= k;
        }
        ++i;
        mWidget__setWindowW(child, w);
        mWidget__setWindowH(child, h);
        child = func_0025C300(child);
    }
}
