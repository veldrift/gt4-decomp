/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef float f32;

struct VEntryI { s16 delta; s16 index; s32 (*fn)(void *self); };
struct VEntryF { s16 delta; s16 index; void (*fn)(void *self, f32 a); };

struct Msg {
    char pad0[0x20];
    u32 color;
};

struct Other {
    char pad[0x10140];
    char *vtbl;
};

struct Strs {
    char pad[0x140];
    char *s140;
};

struct Self {
    char *vtbl;
    char pad4[0xC];
    Other *other;
    char pad14[8];
    s32 f1C;
    char pad20[0x58 - 0x20];
    s32 flags;
    char pad5C[0x17BC - 0x5C];
    Msg msg;
};

extern char D_006A0470[];
extern char D_006A0760[];
extern char D_006A0770[];
extern Strs *DisplayRText__rtext_ptrs_;

extern "C" void RaceEventDisplay__addEvent(void *, const char *, f32, f32, f32, f32);
extern "C" void func_003A5268(void *, const char *, s32);
extern "C" void RaceDisplayUtil__timeToString(char *, s32);
extern "C" void func_0057DA20(char *, const char *, ...);

static inline void formatOne(char *buf, char *title, s32 lap, char *time) { func_0057DA20(buf, D_006A0770, title, lap, time); }

extern "C" void RaceDisplay__virtual_46(Self *self, s32 arg1, s32 arg2) {
    char buf[0x40];
    char buf2[0x20];
    Msg *m = &self->msg;
    m->color = 0x80C8C8C8;
    func_003A5268(m, D_006A0470, 0);
    RaceDisplayUtil__timeToString(buf2, arg2);
    u32 k = self->f1C - 8;
    if (((self->flags >> 10) & 1) || k < 2) {
        Other *o = self->other;
        VEntryI *e = (VEntryI *)(o->vtbl + 0x128);
        s32 r = e->fn((char *)o + e->delta);
        if (r > 0) {
            func_0057DA20(buf, D_006A0760, DisplayRText__rtext_ptrs_->s140, arg1, r, buf2);
        } else {
            formatOne(buf, DisplayRText__rtext_ptrs_->s140, arg1, buf2);
        }
        RaceEventDisplay__addEvent(m, buf, 3.0f, 0.0f, 0x1.333332p-3f, 0x1.333332p-3f);
    } else {
        RaceEventDisplay__addEvent(m, buf2, 3.0f, 0.0f, 0x1.333332p-3f, 0x1.333332p-3f);
    }
    VEntryF *e1 = (VEntryF *)(self->vtbl + 0x188);
    e1->fn((char *)self + e1->delta, 8.0f);
    VEntryF *e2 = (VEntryF *)(self->vtbl + 0x190);
    e2->fn((char *)self + e2->delta, 2.85f);
}
