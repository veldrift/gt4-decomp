typedef int s32;

struct Vec4 {
    char pad[0x10];
};

struct mComposite;

struct Sub {
    char pad0[4];
    s32 f4;
    s32 f8;
    s32 fC;
};

struct mColorWindow {
    char pad0[4];
    s32 vtbl;
    char pad8[0xA8];
    Sub sub;
    s32 fC0;
    char fC4[4];
};

extern "C" void func_00105250(char *arg0);
extern "C" void func_002030A0(Vec4 *arg0);
extern "C" void func_00203118(int arg0, int arg1);
extern "C" void *func_00204F10(struct mComposite *arg0);
extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" s32 func_005E4EA8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" void *func_005E5148(void);

extern char D_0066A328[];

extern "C" void func_00287E68(struct mColorWindow *self) {
    Sub *s;
    s32 spare[4];
    s32 sp[4];
    Vec4 v;

    func_00204F10((struct mComposite *)self);
    s = &self->sub;
    self->vtbl = (s32)D_0066A328;
    s->f4 = 0;
    s->f8 = 0;
    s->fC = 0;
    s32 p = (s32)func_00326750(0x10, 4, *(const char **)func_005E5148());
    s->fC = p + 0x10;
    s->f4 = p;
    s->f8 = p;
    sp[0] = p;
    func_002030A0(&v);
    s->f8 = func_005E4EA8(sp[0], 1, (s32)&v, 0);
    func_00203118((int)&v, 2);
    self->fC0 = 0;
    func_00105250(self->fC4);
}
