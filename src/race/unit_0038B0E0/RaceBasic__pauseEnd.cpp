typedef int s32;

struct VEntry_B4B8 {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Sub_B4B8 {
    char pad0[4];
    void *p4;
};

struct Mid_B4B8 {
    char pad0[0x80];
    Sub_B4B8 *p80;
};

struct Obj_B4B8 {
    char pad0[0x64];
    char *vt;
    char pad1[4];
    Mid_B4B8 *f6C;
    char pad2[0xD30 - 0x70];
    s32 fD30;
};

extern "C" void func_0038B798(Obj_B4B8 *arg0, s32 arg1);
extern "C" void func_00396A90(void *self, s32 on);

extern "C" void func_0038B4B8(Obj_B4B8 *self) {
    self->fD30 = 0;
    func_0038B798(self, 0);
    VEntry_B4B8 *e = (VEntry_B4B8 *)(self->vt + 0x2C8);
    e->fn((char *)self + e->delta);
    func_00396A90(self->f6C->p80->p4, 0);
    *(s32 *)((char *)self + 0xE418) = 0;
}
