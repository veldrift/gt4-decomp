/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int mode, next; char pad[0x414]; };
struct Obj { char pad[0x20]; State state[2]; int index; int pad85c; int busy; };
extern "C" int func_004B4B40(Obj *, int) throw();
extern "C" void func_004B5628(Obj *) throw();
extern "C" void func_004B6108(Obj *, int) throw();
extern "C" void func_004B61A8(Obj *) throw();
extern "C" void func_004B4F28(Obj *) throw();
extern "C" char *func_004B5CC0(Obj *) throw();
extern "C" void func_004B6A38(Obj *) throw();
extern "C" int func_004B6E80(Obj *self) {
    if (self->busy) return 1;
    State *s = &self->state[1-self->index];
    switch (s->mode) {
    case 0:
        func_004B6108(self, 32);
        return 1;
    case 1:
        if (func_004B4B40(self, 1) <= 0) {
            func_004B5628(self);
            s->mode = 0;
            func_004B6108(self, 32);
            s->mode = 1;
            func_004B61A8(self);
            return 1;
        } else {
            s->next = 0;
            func_004B4F28(self);
            s->mode = 2;
        }
        break;
    case 2:
        *func_004B5CC0(self) = 3;
        func_004B6A38(self);
        break;
    }
    return 1;
}
