/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xcc0]; int slots[3]; char pad2[0xc]; char sub[1]; };
extern "C" void func_004F89D8(void *) throw();
extern "C" void func_004F9CE8(Obj *);
extern "C" void func_004F9C08(Obj *self, int value) {
    func_004F89D8(self->sub);
    for (int i = 0; i < 3; ++i) {
        if (value == self->slots[i]) self->slots[i] = -1;
    }
    func_004F9CE8(self);
}
