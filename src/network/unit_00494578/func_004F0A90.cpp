/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p0[0x160]; int active; char p164[0x383c]; int pending; };
extern "C" int func_004F0D48(Obj *);
extern "C" void func_004FB548(Obj *);
extern "C" void func_004F8890(Obj *, int);
extern "C" void func_004F0A90(Obj *self) {
    while (self->pending != 0 && self->active == 0) {
        func_004FB548(self);
        if (func_004F0D48(self) != 1) break;
    }
    if (self->active != 0) {
        func_004F8890(self, 2);
        self->active = 0;
    }
}
