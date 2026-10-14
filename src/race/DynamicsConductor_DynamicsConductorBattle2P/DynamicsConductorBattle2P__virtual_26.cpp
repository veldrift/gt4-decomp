/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Mode { char pad[0xCC8]; int mode; };
struct Head { char pad[0x84]; Mode *mode; };
struct Self {
    Head *head;
    char pad[0xCBD8 - 4];
    int fCBD8;
    char pad2[0x10140 - 0xCBDC];
    char *vt;
};
extern "C" void func_0035C4D8(Self *);
extern "C" void func_0035F630(Self *);
extern "C" void func_00365E38(Self *);
extern "C" void func_00365E80(Self *);
extern "C" void func_003C12B0(void *);
extern "C" void *func_003F40D0(char *);
extern "C" void *func_003F4478(char *);
extern "C" void func_003F4B20(Self *);
extern "C" void func_00414660(void *);
extern "C" void func_0045B8C0(void *, void *, int);
extern "C" void DynamicsConductorBattle2P__virtual_26(Self *self) {
    func_0035C4D8(self);
    VEntry *e = (VEntry *)(self->vt + 0x10);
    e->fn((char *)self + e->delta);
    VEntry *e2 = (VEntry *)(self->vt + 0x18);
    e2->fn((char *)self + e2->delta);
    func_003F4478((char *)self);
    func_003F40D0((char *)self);
    func_00365E38(self);
    func_00365E80(self);
    func_00414660((char *)self + 0xCD7C);
    func_003F4B20(self);
    func_0045B8C0((char *)self + 0xDA6C, self, self->fCBD8);
    func_003C12B0((char *)self->head + 0x88);
    if (self->head->mode->mode == 0) return func_0035F630(self);
}
