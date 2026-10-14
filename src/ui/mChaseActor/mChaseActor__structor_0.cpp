/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Chase {
    char pad0[4];
    char *vtbl;
    char pad8[0xC];
    s32 u14, u18, u1C, u20;
    float f24, f28;
    s32 u2C, u30;
};
extern char mChaseActor__vtable[];
extern "C" void *mActor__structor_0(void *);
extern "C" int mChaseActor__structor_0(struct Chase *self) {
    mActor__structor_0(self);
    self->u2C = 1;
    self->vtbl = mChaseActor__vtable;
    self->f24 = 16.0f;
    self->f28 = 8.5f;
    self->u14 = 0;
    self->u18 = 0;
    self->u1C = 0;
    self->u20 = 0;
    self->u30 = 0;
}
