/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x60]; char *data; };
extern "C" void AutomobileControlRecord__Recorder__save(void *, int *) throw();
extern "C" void func_00346EB0(Obj *self, int *out) {
    __builtin_memcpy((char *)out + *out, self->data, 0x14F4);
    *out += 0x14F4;
    AutomobileControlRecord__Recorder__save((char *)self + 8, out);
}
