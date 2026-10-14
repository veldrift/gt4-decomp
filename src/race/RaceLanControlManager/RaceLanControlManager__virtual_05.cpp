/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[0x50]; int count; char pad54[0x10]; int handle; int enabled; char pad6c[8]; int active; };
extern "C" void func_00337A18(int);
extern "C" void func_00337A70(int);
extern "C" void RaceLanControlManager__virtual_05(Obj *self) {
    if (self->enabled != 0 && self->active != 0) {
        func_00337A18(self->handle);
        self->count++;
    } else {
        func_00337A70(self->handle);
    }
}
