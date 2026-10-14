/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    int first;
    void *vtbl;
    char pad[0x1D98 - 8];
    int a, b, c, d;
};
struct Input { char pad[0x420]; int value; };
struct Screen { char pad[0x1C]; float width, height; };
extern char mRenderContextPS2__vtable[];
extern Screen *PDISTD__global_font_manager;
extern "C" void *mRenderContext__structor_0(Obj *, Input *);
extern "C" void *func_00105250(char *);
extern "C" int mRenderContextPS2__structor_0(Obj *self, Input *arg) {
    mRenderContext__structor_0(self, arg);
    self->vtbl = mRenderContextPS2__vtable;
    func_00105250((char *)self + 0x1D5C);
    self->a = 0;
    self->b = 0;
    self->c = arg->value;
    self->d = 0;
    Screen *screen = PDISTD__global_font_manager;
    screen->width = 640.0f;
    screen->height = 480.0f;
}
