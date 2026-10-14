/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int active; char pad[12]; int touched; };
struct Info { char pad0[0x88]; State state; char pad1[0xdc-0x9c]; int dc; int e0; char pad2[0x968-0xe4]; unsigned int limit; };
struct Obj { Info *info; char pad0[0xcbdc-4]; unsigned char flag; char pad1[0x10140-0xcbdd]; char *vt; };
struct Entry { short delta; short index; int (*fn)(void *); };
extern "C" unsigned char DynamicsConductor__GetNumberOfPylonsToBeTouched(void *);
extern "C" void func_0035DF80(char *, int, int, int);
extern "C" int func_00358000(Obj *self, int arg1, unsigned int arg2) {
    if (arg1 != 0) return 0;
    Info *info = self->info;
    if (info->dc != 0) return 0;
    if (self->flag != 0) return 0;
    if (info->e0 != 0) return 0;
    if (arg2 == 0x157529ff) return 0;
    if (arg2 >= info->limit) return 0;
    State *state = &info->state;
    Entry *e = (Entry *)(self->vt + 0x30);
    if (e->fn((char *)self + e->delta) != 0 && DynamicsConductor__GetNumberOfPylonsToBeTouched(self) == 0)
        state->touched = 1;
    if (state->active != 0)
        func_0035DF80((char *)info, 0x16, arg1, 0);
    return 1;
}
