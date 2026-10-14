/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
typedef unsigned int u32;

struct VEnt { s16 delta; s16 idx; void *fn; };
struct Self {
    char *vtbl;
    char pad4[0x2F - 4];
    signed char id2F;
    char pad30[0xC];
    u32 w3C;
    char pad40[4];
    u32 w44;
};
struct Sub { char pad[0x18]; u32 w18; };

extern "C" void func_0039BCA8(Self *);
extern "C" void func_0039D218(Self *, s32);
extern "C" s32 func_003A1638(Self *, s32);
extern "C" void func_003A2270(Self *, f32);

extern "C" void func_0039BBE0(Self *self) {
    VEnt *e = (VEnt *)(self->vtbl + 0x58);
    self->w3C = self->w3C & 0xFFFFFF;
    ((void (*)(void *, s32))e->fn)((char *)self + e->delta, self->id2F);
    func_0039D218(self, self->id2F);
    func_003A1638(self, 0);
    func_0039BCA8(self);
    s32 flag = *(s32 *)((char *)self + 0x20) == 1;
    func_003A2270(self, flag ? 42.0f : 0.0f);
    Sub *s = (Sub *)((char *)self + 0xD58);
    s->w18 = (s->w18 & -0x100) | flag;
    self->w44 = (self->w44 & -0x100) | 1;
}
