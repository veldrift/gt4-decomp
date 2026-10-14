struct State;
struct Obj { char pad[0x3c]; int busy; char pad40[4]; State *state; };
struct State { void *handle; int data; int value; char pad[0x1018]; int type; char body[0x102c]; int (*callback)(Obj *, int, int); };
struct Manager { char pad[0x18]; void (*release)(void *); };
extern Manager *D_0064B4B0;
extern int D_0064C128, D_0064C118;
extern char D_006C40D8[];
extern int D_0086B540[];
extern "C" int func_0053BD78(Obj *, int *) throw();
extern "C" void func_00540EB0(int);
extern "C" int func_00540F10(int, const char *, int, int);
extern "C" int func_00540F98(int, int *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_0053C590(Obj *self) {
    int flag; int data;
    flag = 0;
    int result = func_0053BD78(self, &flag);
    if (result || flag) {
        if (self->state->type == 200 && flag) {
            data = 0;
            if (!func_00540F10(self->state->data, D_006C40D8, 0, 1) && !func_00540F98(self->state->data, &data)) {
                func_005A4724(D_0086B540, (void *)data, 0x1304);
                self->state->value = D_0086B540[0];
            }
        }
        D_0064C118 = 1;
        D_0064C128 = result;
        func_00540EB0(self->state->data);
        self->state->data = 0;
        D_0064B4B0->release(self->state->handle);
        {
            State *c = self->state;
            c->handle = 0;
            c->callback(self, result, c->value);
        }
        self->state->callback = 0;
        func_005A48D8(&self->state->type, 0, 0x100c);
        self->busy = 0;
    }
    return result;
}
