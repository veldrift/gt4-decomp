/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int mode, next; char pad[0x414]; };
struct Obj { char pad[0x20]; State state[2]; int index; int pad85c; int busy; };
struct Packet { char status; char pad[3]; short first, last; };
extern "C" void func_004B4CC0(void *, void *, void *, int) throw();
extern "C" void func_004B4F28(void *) throw();
extern "C" void *func_004B5CC0(void *) throw();
extern "C" void func_004B5E00(void *, void *, void *, int) throw();
extern "C" void func_004B9438(void *);
extern "C" int func_004B7D18(Obj *self) {
    char buf[512];
    if (self->busy) return 1;
    State *s = &self->state[1-self->index];
    switch (s->mode) {
    case 0: return 0;
    case 1:
        s->next = 2;
        func_004B4F28(self);
        s->mode = 2;
        break;
    case 2: {
        Packet *p = (Packet *)func_004B5CC0(self);
        func_004B4CC0(self, p, buf, 256);
        func_004B9438(buf);
        func_004B5E00(self, p, buf, p->last - p->first);
        p->status = 5;
        break;
    }
    }
    return 1;
}
