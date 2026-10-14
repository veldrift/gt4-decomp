/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { int a; int b; };
struct World { char pad[0x88]; Pair pair; };
struct Self { World *world; };
extern "C" int DynamicsConductor__initialize(Self *, int);
extern "C" int func_003FA238(Self *);
extern "C" int DynamicsConductorLicense__virtual_27(Self *self, int arg1) {
    DynamicsConductor__initialize(self, arg1);
    Pair *w = &self->world->pair;
    w->a = -2;
    w->b = 0x157529FF;
    return func_003FA238(self);
}
