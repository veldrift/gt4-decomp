/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
typedef unsigned char u8;

struct VEnt { s16 delta; s16 idx; void *fn; };
struct Msg { char pad[0x20]; s32 color; };
struct Table { char pad[0x124]; char *name; };
struct Self { char *vtbl; };
struct Arg { char pad[0x6FE]; u8 b6fe; };

extern Table *DisplayRText__rtext_ptrs_;
extern "C" s32 func_0035FC80(Arg *) throw();
extern "C" void func_0057DA20(char *, char *, ...);
extern "C" void RaceMessageDisplay__setFont(void *, char *, s32);
extern "C" void Oscillator__setCount(void *, s32, s32);
extern "C" void Oscillator__setCycle(void *, f32, f32);
extern "C" void RaceMessageDisplay__setMessage(void *, char *, f32, f32);
extern char D_006A0470[];

extern "C" void RaceDisplay__update_automobile_message(Self *self, Arg *arg) {
    char buf[0x80];
    char *osc = (char *)self + 0x22C0;
    s32 n = func_0035FC80(arg);
    Msg *m = (Msg *)((char *)self + 0x228C);
    if (n > 0) {
        func_0057DA20(buf, DisplayRText__rtext_ptrs_->name, n);
        RaceMessageDisplay__setFont(m, D_006A0470, 1);
        m->color = 0x800000C8;
        Oscillator__setCount(osc, -1, 1);
        Oscillator__setCycle(osc, 1.0f, 1.0f);
        RaceMessageDisplay__setMessage(m, buf, 0x1.999998p-3f, 0.0f);
    } else {
        VEnt *e = (VEnt *)(self->vtbl + 0xE0);
        ((void (*)(void *, s32))e->fn)((char *)self + e->delta, arg->b6fe);
    }
}
