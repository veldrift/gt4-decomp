/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot { int state; char pad[0x418]; };
struct Obj { char pad[0x20]; Slot slots[2]; int cur; int unk85c; int done; };
extern "C" void func_004B5628(Obj *) throw();
extern "C" void func_004B61A8(Obj *) throw();
extern "C" int func_004B7B08(Obj *self) {
    if (self->done) return 1;
    Slot *s = &self->slots[1 - self->cur];
    switch (s->state) {
    case 0:
        s->state = 1;
        func_004B61A8(self);
        return 1;
    case 1:
    case 2:
        func_004B5628(self);
        s->state = 0;
        break;
    }
    return 1;
}
