/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { short pad[2]; short begin, end; };
struct Slot { char pad[0x20]; int state; char gap[0x250-0x24]; Data data; char tail[0x41C-0x258]; };
struct Obj { Slot slots[2]; char pad[0x20]; int active; char gap[4]; int busy; };
extern "C" Data *func_004B5D00(Obj *) throw();
extern "C" void func_004B5EB8(Obj *, Data *) throw();
extern "C" void func_004B66F0(Obj *, int) throw();
extern "C" void func_004B54E8(Obj *) throw();
extern "C" int func_004B4220(void) throw();
extern "C" void func_0057D9C0(const char *, ...);
extern char D_006B0458[];
extern "C" int func_004B72E0(Obj *self) {
    if (self->busy) return 1;
    Slot *slot = self->slots + (1 - self->active);
    int *state = &slot->state;
    switch (*state) {
    case 0: {
        Data *p = func_004B5D00(self);
        if (p->end - p->begin > 0) {
            func_004B5EB8(self, p);
            func_004B66F0(self, 1);
        }
        break;
    }
    case 1: {
        Data *p = func_004B5D00(self);
        if (p->end - p->begin > 0) {
            func_004B5EB8(self, p);
            func_004B66F0(self, 1);
        } else {
            func_004B5EB8(self, &slot->data);
        }
        break;
    }
    case 2: {
        func_004B54E8(self);
        int result = func_004B4220();
        if (result < 0) func_0057D9C0(D_006B0458, result & 0xFF, result & 0x7F00);
        *state = 1;
        break;
    }
    }
    return 1;
}
