/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
extern Rep D_00659FA8;
extern char mFlashFace__vtable[];
extern "C" void *mWidget__structor_0(void *);
extern "C" void *func_00291150(void *);
extern "C" char *func_005C2560(Rep *);
struct Obj {
    int count;
    void *vt;
    char pad[0x98];
    char *str;
    int a4;
    int a8;
    int ac;
    int b0;
    unsigned f0:1;
    unsigned f1:1;
    unsigned f2:1;
    unsigned f3:1;
    unsigned f4:1;
    unsigned f5:1;
    unsigned f6:1;
    unsigned f7:1;
    unsigned rest:24;
};
extern "C" int mFlashFace__structor_0(Obj *self) {
    char **s = &self->str;
    mWidget__structor_0(self);
    self->vt = mFlashFace__vtable;
    Rep *r = &D_00659FA8;
    char *p = (char *)(r + 1);
    if (r->sel) p = func_005C2560(r);
    else ++r->ref;
    *s = p;
    self->a4 = 0;
    func_00291150(&self->a8);
    func_00291150(&self->ac);
    self->b0 = 0;
    self->f0 = 1;
    self->f1 = 0;
    self->f2 = 1;
    self->f3 = 0;
    self->f4 = 1;
    self->f5 = 1;
    self->f6 = 1;
    self->f7 = 0;
}
