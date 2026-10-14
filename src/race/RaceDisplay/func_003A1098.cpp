/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef short s16;
typedef float f32;

struct Car { char pad[0x18]; s32 mode; };
struct ListHdr { s32 count; s32 pad4; Car **items; };
struct Info { char pad[0x60]; ListHdr *list; };

struct Disp {
    u32 w0;
    char pad4[0x14];
    char *ptr18;
    f32 f1C;
    f32 f20;
    s32 i24;
};

struct Msg {
    u8 b0;
    char pad1[3];
    s16 x;
    s16 y;
    char pad8[0x10];
    s32 i18;
    s32 i1C;
    s32 i20;
    f32 f24;
};

struct Self {
    char pad0[4];
    Info *info;
    struct Ent { s32 a, b; } *entries;
    char pad0C[0x17BC - 0xC];
    Msg msg;
    char pad17E8[0x2D14 - 0x17BC - sizeof(Msg)];
    Disp disp;
    char pad2D3C[0x2D58 - 0x2D14 - sizeof(Disp)];
    char osc[4];
};

extern char D_006A0470[];

extern "C" s32 Automobile__getDrawMode(s32, Car *);
extern "C" void func_003A5268(void *, const char *, s32);
extern "C" void RaceEventDisplay__addEvent(char *, const char *, f32, f32, f32, f32);
extern "C" void func_003A6878(f32, f32, void *);
extern "C" void Oscillator__setCycle(void *, f32, f32);
extern "C" void Oscillator__setWaveform(void *, f32, f32);
extern "C" void RaceDisplayObjectBase__setLocation(void *, s32, s32);
extern "C" void RaceDisplayObjectBase__setAlignment(void *, s32, s32);
extern "C" void RaceDisplayUtil__timeToString(char *, s32);

static inline bool isMode3(Car *c) { return Automobile__getDrawMode(c->mode,c) == 3; }

extern "C" void func_003A1098(Self *self, s32 arg1, s32 arg2, s32 arg3) {
    char buf[0x20];
    s32 ok = 0;
    s32 v;
    Msg *m;
    Info *info = self->info;
    if (self->entries != 0 && arg2 >= 0) {
        ok = arg2 < info->list->count;
    }
    v = 0;
    if (ok) {
        ListHdr *list = info->list;
        Car *car = list->items[arg2];
        bool dm = isMode3(car);
        if (dm) {
            m = &self->msg;
            Disp *d = &self->disp;
            s32 x = m->x;
            d->ptr18 = (char *)&self->entries[arg2];
            RaceDisplayObjectBase__setLocation(d, x - 0x59, m->y + 0x16);
            v = 0x20;
            d->i24 = 0;
            Oscillator__setCycle(self->osc, 0.5f, 0.5f);
            Oscillator__setWaveform(self->osc, 0x1.999998p-5f, 0x1.999998p-5f);
            d->f1C = 0x1.333332p-3f;
            d->f20 = 0x1.333332p-3f;
            RaceDisplayObjectBase__setAlignment(d, 0, 2);
            u32 visible = m->b0;
            self->disp.w0 = (self->disp.w0 & ~0xFF) | visible;
        } else { m = &self->msg; }
    } else {
        m = &self->msg;
    }
    m->i18 = v;
    m->i1C = 0x19;
    func_003A5268(m, D_006A0470, 0);
    m->i20 = arg3;
    buf[0] = arg1 >= 0 ? 0x2B : 0x7F;
    buf[1] = 0x20;
    RaceDisplayUtil__timeToString(buf + 2, arg1 < 0 ? -arg1 : arg1);
    RaceEventDisplay__addEvent((char *)m, buf, 3.0f, -3.0f, 0x1.333332p-3f, 0x1.333332p-3f);
    if (ok) {
        func_003A6878(0x1.6cccccp+1f, m->f24, &self->disp);
    }
}
