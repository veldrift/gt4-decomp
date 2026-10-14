/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int mode; char pad[0x418]; };
struct Obj { char pad[0x20]; State state[2]; int index; int pad85c; int busy; };
extern "C" int func_004B4B40(Obj *, int) throw();
extern "C" void func_004B5628(Obj *) throw();
extern "C" void func_004B6108(Obj *, int) throw();
extern "C" void func_004B61A8(Obj *) throw();
extern "C" void func_004B8440(Obj *, int);
extern "C" int func_004B6D90(Obj *self) {
    if (self->busy) return 1;
    State *s = &self->state[1-self->index];
    switch (s->mode) {
    case 0:
        func_004B6108(self, 10);
        func_004B8440(self, 0);
        return 1;
    case 1:
        if (func_004B4B40(self, 1) <= 0) {
        func_004B5628(self);
        s->mode = 0;
        func_004B6108(self, 10);
        s->mode = 1;
        func_004B61A8(self);
        return 1;
        }
        return 0;
    case 2:
        return 0;
    default:
        return 1;
    }
}
