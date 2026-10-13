struct Referent_001C9468 { char padding_00[0x3c]; volatile int field_3c; };
typedef int (*Callback_0019A630)(void *, int, int);
struct Handle_00A0 {
    Referent_001C9468 *field_00;
    Referent_001C9468 *operator->() const { return field_00; }
    Referent_001C9468 *get() const { return field_00; }
};
struct Obj_0019A940 { char padding_00[0xa0]; Handle_00A0 field_a0; };
extern "C" void func_0019A698(Obj_0019A940 *, void *);
extern "C" int func_0019A630(void *, int, int);
extern "C" const char *func_001CA740(Referent_001C9468 *, Callback_0019A630, Obj_0019A940 *);
extern "C" const char *func_0019A940(Obj_0019A940 *self, void *context) {
    Handle_00A0 &slot = self->field_a0;
    if (slot->field_3c != 0) return 0;
    func_0019A698(self, context);
    return func_001CA740(slot.get(), func_0019A630, self);
}
