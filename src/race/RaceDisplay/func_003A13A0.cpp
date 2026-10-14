/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Table { char pad[8]; char **entries; };
struct Ctx { char pad[0x60]; Table *tbl; };
struct Self {
    char pad0[4];
    Ctx *ctx;
    char pad8[0x17BC - 8];
    char disp[1];
};
struct Globals { char pad[0x188]; char *fmt; };
struct Disp { char pad[0x20]; unsigned int color; };

extern Globals *DisplayRText__rtext_ptrs_;
extern char D_006A0718[];
extern "C" void func_0057DA20(char *, char *, ...);
extern "C" void RaceEventDisplay__clear(void *, f32);
extern "C" void func_003A5268(void *, char *, s32);
extern "C" void RaceEventDisplay__addEvent(void *, char *, f32, f32, f32, f32);

extern "C" void func_003A13A0(Self *self, s32 idx) {
    char buf[0x100];
    Disp *d;
    char *fmt = DisplayRText__rtext_ptrs_->fmt;
    char *b = buf;
    if (fmt) {
        d = (Disp *)((char *)self + 0x17BC);
        func_0057DA20(b, fmt, self->ctx->tbl->entries[idx] + 0x348C);
        RaceEventDisplay__clear(d, 0.0f);
        d->color = 0x80C8C8C8;
        func_003A5268(d, D_006A0718, 1);
        RaceEventDisplay__addEvent(d, b, 3.0f, 0.0f, 0x1.333332p-3f, 0x1.333332p-3f);
    }
}
