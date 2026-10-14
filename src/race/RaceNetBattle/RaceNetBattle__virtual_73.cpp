/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { char pad[0x1C]; short v; char pad2[0x19C - 0x1E]; };
struct Race {
    struct VE0 *vtbl;
    char pad[0x9BC - 4];
    int idx;
};
struct VE0 { char pad[0]; };
struct VEi { short delta, index; int (*fn)(void *); };
struct VEp { short delta, index; Race *(*fn)(void *, int); };
struct VEc { short delta, index; void (*fn)(void *, void *, int); };
struct Cb { char pad[0xC]; char *vt; };
struct Obj {
    char pad0[0x64]; char *vtbl;
    char pad1[4]; void *f6C;
};
extern "C" int func_00373DA0(void *, int);
extern "C" void RaceBasic__updatePlay(Obj *, float);
extern "C" void RaceDisplay__virtual_10(void *, int);
extern "C" void RaceDisplay__setViewMode(void *, int);
extern "C" void RaceDisplay__setDiveReplayMode(void *, int);
extern "C" void RaceDisplay__commonPreUpdate(void *);
extern "C" void func_0039DA80(void *);
extern "C" void RaceDisplay__update(void *, float);
extern "C" void RaceDisplay__setDisplayEnableInReplay(void *, int);

extern "C" void RaceNetBattle__virtual_73(Obj *self, float dt) {
    char *disp = (char *)self + 0x1ED1C;
    RaceBasic__updatePlay(self, dt);
    RaceDisplay__commonPreUpdate(self->f6C);
    VEp *e1 = (VEp *)(self->vtbl + 0xD0);
    Race *r = e1->fn((char *)self + e1->delta, 0);
    RaceDisplay__virtual_10(disp, ((Ent *)r)[r->idx].v);
    VEi *e2 = (VEi *)((char *)r->vtbl + 0x120);
    RaceDisplay__setViewMode(disp, e2->fn((char *)r + e2->delta));
    RaceDisplay__setDiveReplayMode(disp, func_00373DA0(r, 0));
    VEi *e3 = (VEi *)((char *)r->vtbl + 0x1B0);
    RaceDisplay__setDisplayEnableInReplay(disp, e3->fn((char *)r + e3->delta));
    RaceDisplay__update(disp, dt);
    if (*(Cb **)((char *)self + 0xE41C)) {
        VEi *e4 = (VEi *)(self->vtbl + 0x230);
        void *s0 = self->f6C;
        int v = e4->fn((char *)self + e4->delta);
        Cb *cb = *(Cb **)((char *)self + 0xE41C);
        VEc *e5 = (VEc *)(cb->vt + 0x20);
        e5->fn((char *)cb + e5->delta, s0, v);
    }
    func_0039DA80(self->f6C);
}
