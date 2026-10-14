/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct V2 { float x, y; };
struct Self {
    char pad0[0x38];
    V2 pos;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
};
struct Args { char pad0[0xAC]; s32 mode; };

extern s32 D_00618428;

extern "C" void func_001042C0(Self *self) throw();
extern "C" s32 func_00103FB8(void) throw();

extern "C" void func_00104A60(Self *self, Args *args) {
    func_001042C0(self);
    switch (args->mode) {
    case 0: {
        self->f40 = 0;
        self->f44 = 0;
        V2 *p = &self->pos;
        p->y = p->x = 0.0f;
        self->f48 = 0;
        D_00618428 = 0;
        self->f4C = func_00103FB8();
        break;
    }
    case 2:
        self->pos.x = -0.25f;
        break;
    }
}
