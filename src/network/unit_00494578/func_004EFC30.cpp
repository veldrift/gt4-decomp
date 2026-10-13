typedef int s32;

extern char D_00689608[];

extern "C" void func_004EFF48(void *p);
extern "C" s32 func_0057FBE0(void);

struct Obj {
    s32 f0;
    s32 f4;
    s32 f8;
    char pad[0x100];
    void *f10C;
};

extern "C" void func_004EFC30(struct Obj *self) {
    self->f10C = D_00689608;
    self->f0 = func_0057FBE0();
    self->f4 = 0x20;
    self->f8 = 0x40;
    func_004EFF48(self->pad);
    func_004EFF48(self->pad + 0x80);
}
