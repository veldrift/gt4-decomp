/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00208428(void *);
extern "C" void func_00208568(float *, void *);
extern "C" void mWidget__getWindowSize(void *, float *, float *);
extern "C" void func_0025B538(void *, float, float, float, float);
extern "C" void func_002D2068(void *, float *, float, float) throw();
struct Obj { char pad[0xBC]; void *view; void *child; };
extern "C" void func_002D2BF8(Obj *self) {
    float size[2];
    float rect[4];
    void *view = self->view;
    if (view && self->child) {
        mWidget__getWindowSize(view, &size[0], &size[1]);
        func_00208568(rect, self->child);
        if (func_00208428(self->child) > 0) {
            func_0025B538(self->child, rect[0], rect[1], rect[2], rect[3]);
        } else {
            func_0025B538(self->child, 0.0f, 0.0f, size[0], size[1]);
        }
        func_002D2068((char *)self + 0xC4, rect, size[0], size[1]);
        func_002D2068((char *)self + 0xFC, rect, size[0], size[1]);
    }
}
