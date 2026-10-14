/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct V2 { float x, y; };
struct Self { char pad0[0x30]; V2 pos; };
struct Args { char pad0[0xAC]; s32 mode; };

extern "C" void func_001042C0(Self *self);

extern "C" void func_00104488(Self *self, Args *args) {
    func_001042C0(self);
    V2 *p = &self->pos;
    p->x = 0.0f;
    p->y = 1.0f;
    if (args->mode == 2) {
        p->x = -0.25f;
    }
}
