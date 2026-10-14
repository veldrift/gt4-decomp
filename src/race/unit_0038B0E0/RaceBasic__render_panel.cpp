/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct A { VE *vt; };
struct B { char pad[0xC]; char *vt; };
struct C { char pad[8]; char *vt; };
struct Obj {
    char pad0[0x6C]; void *u6C;
    char pad70[0xCD8 - 0x70]; s32 cd8;
    char padCDC[0xE40C - 0xCDC]; void *e40c; char pad410[4]; void *e414;
    C *e418; B *e41c; A *e420; void *e424;
};
extern "C" void RacePS2Base__render_panel(Obj *, s32);
extern "C" void func_001056A0(s32);
extern "C" void func_003DA150(void *);
extern "C" void func_003DD690(void *);
extern "C" void func_003BAD08(void *, s32);
extern "C" void RaceBasic__render_panel(Obj *self, s32 arg) {
    RacePS2Base__render_panel(self, arg);
    void *u = self->u6C;
    A *a = self->e420;
    if (a) {
        VE *e = (VE *)((char *)a->vt + 0x18);
        ((void (*)(void *, s32))e->fn)((char *)a + e->delta, arg);
    }
    func_001056A0(arg);
    if (self->e424) func_003DA150(self->e424);
    B *b = self->e41c;
    if (b) {
        VE *e = (VE *)(b->vt + 0x28);
        ((void (*)(void *, s32, void *))e->fn)((char *)b + e->delta, arg, u);
    }
    if (self->e40c) func_003DD690(self->e40c);
    if (self->e414) func_003BAD08(self->e414, arg);
    if (self->cd8) {
        C *c = self->e418;
        VE *e = (VE *)(c->vt + 0x28);
        ((void (*)(void *, s32, void *))e->fn)((char *)c + e->delta, arg, u);
    }
}
