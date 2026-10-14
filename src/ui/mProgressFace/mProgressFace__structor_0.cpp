/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int word; void *vt; char pad[0xe8]; int member; int a,b,c; };
extern char mProgressFace__vtable[];
extern "C" void *mImageFace__structor_0(Obj *);
extern "C" int func_00228450(void *, void *);
extern "C" int mProgressFace__structor_0(Obj *self) {
    mImageFace__structor_0(self);
    self->vt = mProgressFace__vtable;
    void *zero = 0;
    func_00228450(&self->member, &zero);
    self->a = 0;
    self->b = 0;
    self->c = 0;
}
