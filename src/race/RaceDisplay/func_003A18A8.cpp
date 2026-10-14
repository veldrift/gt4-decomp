/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Obj18 { char pad[0x18]; void *p18; };
struct Table { char pad[8]; Obj18 **entries; };
struct Ctx { char pad[0x60]; Table *tbl; };
struct Self {
    char pad0[4];
    Ctx *ctx;
    char pad8[0x14];
    s32 i1C;
    s32 i20;
    char pad24[8];
    signed char id2C_;
    char pad2d;
    signed char id2E;
};

extern "C" s32 func_003683A8(void *);
extern "C" s32 func_003A1EE0(Self *);
extern "C" s32 func_003F9018(void *);

extern "C" s32 func_003A18A8(Self *self, s32 arg1) {
    switch (self->i1C) {
    case 8: return 1;
    case 9: return 3;
    }
    if ((self->i20 ^ 1) == 0) return 2;
    if (func_003A1EE0(self) != 0) arg1 = 1;
    void *s2 = self->ctx->tbl->entries[self->id2E]->p18;
    if (func_003683A8(s2) != 0) {
        arg1 = 4;
        if (func_003A1EE0(self) != 0) arg1 = 1;
    }
    return func_003F9018(s2) == 0 ? arg1 : 1;
}
