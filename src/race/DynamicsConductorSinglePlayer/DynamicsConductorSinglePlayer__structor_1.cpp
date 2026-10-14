/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int words[32]; };
struct Obj { char pad0[0xf818]; Block block; char padf898[0x10140-0xf898]; void *vt; };
extern Block D_006203C8;
extern char DynamicsConductorSinglePlayer__vtable[];
extern "C" void DynamicsConductor__structor_0(char *);
extern "C" void DynamicsConductorSinglePlayer__structor_1(Obj *self) {
    DynamicsConductor__structor_0((char *)self);
    self->vt = DynamicsConductorSinglePlayer__vtable;
    self->block = D_006203C8;
}
