/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int unk0; char *base; char pad8[8]; char *data; char pad14[8]; int active; };
extern "C" void func_00454410(void *);
extern "C" void func_00454698(void *, void *, int, int);
extern "C" void func_003BAD50(Obj *self) {
    char **data = &self->data;
    if (self->active) {
        char *base = self->base;
        self->base = (char *)self;
        *data += (char *)self - base;
        func_00454410(*data);
        void **member = *(void ***)(*data + 0x7C);
        func_00454698(*member, member, 0, 0);
    }
}
