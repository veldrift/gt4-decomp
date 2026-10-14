/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x3f20]; int active; int pending; };
extern "C" void func_004F8858(Obj *, int) throw();
extern "C" int func_00505438();
extern "C" void func_00577F80();
extern "C" int func_004FFD40(Obj *self) {
    if (self->active == 0) return 1;
    {
        if (self->pending != 0) {
            self->pending = 0;
            func_00577F80();
        }
        int value = func_00505438();
        func_004F8858(self, value);
        if (value != 0) return 0;
        self->active = 0;
        return 1;
    }
}
