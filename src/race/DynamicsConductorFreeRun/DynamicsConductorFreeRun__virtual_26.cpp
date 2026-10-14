/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct Result { char pad[0x10]; int value; };
struct Car { char pad[0x144]; void *p144; };
struct Entry { short delta, index; Car *(*fn)(void *, int); };
struct Race { char pad[0x64]; char *vt; };
struct Root { char pad[0x84]; Race *race; };
struct Obj { Root *root; char pad4[0xCBD8]; unsigned char flag; char padCBDD[0x2CC3]; int state; };
extern "C" void func_00345520(char *);
extern "C" Result *func_00346A28(void *);
extern "C" char *func_0034C190(Obj *, int);
extern "C" int DynamicsConductorBattle2P__virtual_26(Obj *);
extern "C" void func_00353570(Obj *);
extern "C" void DynamicsConductorFreeRun__virtual_26(Obj *self) {
    DynamicsConductorBattle2P__virtual_26(self);
    func_00353570(self);
    if (self->flag == 0) {
        Race *r = self->root->race;
        Entry *e = (Entry *)(r->vt + 0x240);
        Result *p = func_00346A28(e->fn((char *)r + e->delta, 0x100)->p144);
        if (p->value == 0) p->value = 0x157529FF;
    }
    if (self->state != 2) return;
    return func_00345520(func_0034C190(self, 1));
}
