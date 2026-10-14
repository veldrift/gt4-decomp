typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef float f32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *self); };

struct Msg {
    char pad0[0x18];
    f32 f18;
    f32 f1C;
    u32 color;
};

struct Info { char pad[1]; };

struct Self {
    char *vtbl;
    s32 f4;
    char pad8[0x2F - 8];
    signed char id2F;
    char pad30[0x267C - 0x30];
    char m267C[0x150];
    char m27CC[1];
};

extern char D_006A0510[];
extern char D_006A0528[];
extern char D_006A0540[];
extern char D_006A0548[];

extern "C" char *DisplayRText__getRTextStr(const char *);
extern "C" s32 RaceOrganization__getPreScore(s32, s32);
extern "C" s32 func_0057DA20(char *, const char *, ...);
extern "C" void RaceMessageDisplay__setMessage(void *, const char *, f32, f32);
extern "C" void RaceMessageDisplay__setFont(void *, const char *, s32);

extern "C" void RaceDisplay__put_aspec_race_information(Self *self, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    char buf[0x80];
    VEntry *e = (VEntry *)(self->vtbl + 0x150);
    if (e->fn((char *)self + e->delta) != 0 && !(fparg1 <= 0.0f)) {
        char *s3 = DisplayRText__getRTextStr(D_006A0510);
        char *s2 = DisplayRText__getRTextStr(D_006A0528);
        if (s3 != 0 && s2 != 0) {
            Msg *m2 = (Msg *)self->m27CC;
            s32 p = self->f4;
            func_0057DA20(buf, s2, RaceOrganization__getPreScore(p, self->id2F));
            Msg *m1 = (Msg *)self->m267C;
            RaceMessageDisplay__setFont(m1, D_006A0540, 1);
            m1->color = 0x80C8C8C8;
            m1->f18 = fparg2;
            m1->f1C = fparg3;
            RaceMessageDisplay__setMessage(m1, s3, fparg1, fparg0);
            RaceMessageDisplay__setFont(m2, D_006A0548, 1);
            m2->color = 0x800086E6;
            m2->f18 = fparg2;
            m2->f1C = fparg3;
            RaceMessageDisplay__setMessage(m2, buf, fparg1, fparg0);
        }
    }
}
