/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
struct A8 { s32 p0; };
struct B60 { s32 cnt; char pad[4]; s32 p8; };
struct Q { s32 f0; char pad[0x60 - 4]; s32 p60; char pad2[0x70 - 0x64]; s32 p70; char pad3[0x80 - 0x74]; s32 p80; char pad4[0x970 - 0x84]; s32 f970; };
struct W { char pad[0x6C]; s32 q; };
struct Self {
    char pad0[0x3C8];
    char s3C8[0x40];
    char s408[0x46C - 0x408];
    s32 f46C;
    char padX[0x478 - 0x470];
    s32 f478;
    char pad2[0x480 - 0x47C];
    s32 f480;
    char pad3[0x490 - 0x484];
    s32 f490;
    char pad4[0x4A0 - 0x494];
    s32 f4A0, f4A4;
    char pad5[0x4F0 - 0x4A8];
    s32 f4F0, f4F4;
};
extern "C" s32 func_00110498(void *);
extern "C" float RaceCourse__getCourseLength(void *);
extern "C" char *func_00445450(char *);
extern "C" s32 func_00445AE8(char *, char *);
extern "C" char *SPEC_DATABASE__RaceSpec__getRaceLabel(void *);
extern "C" char *func_004472A0(void *);
extern "C" char *func_005A609C(char *, const char *);

extern "C" void func_00114250(char *self, W *w) {
    Q *q = (Q *)w->q;
    s32 n = ((B60 *)q->p60)->cnt;
    s32 i = 0;
    if (n > 0) do {
        s32 off = i * 4;
        i++;
        B60 *b = (B60 *)q->p60;
        char *o = *(char **)(off + b->p8);
        s32 idx = *(s32 *)(o + 0x3444);
        func_005A609C(self + idx * 0x80 + 4, func_00445450(o + 0x20));
        char *p = self + idx * 16;
        off += ((B60 *)q->p60)->p8;
        char *o2 = *(char **)off;
        func_00445AE8(o2 + 0x20, p + 0x304);
    } while (i < n);
    Self *s = (Self *)self;
    s->f478 = n;
    s->f4A0 = *(s32 *)(((A8 *)((B60 *)q->p60)->p8)->p0 + 0x3444);
    func_005A609C(s->s3C8, SPEC_DATABASE__RaceSpec__getRaceLabel((void *)q->p70));
    func_005A609C(s->s408, func_004472A0((void *)q->p70));
    s32 v = func_00110498((void *)q->p70);
    s->f490 = v;
    q->f970 = v != 0;
    s->f4A4 = 0;
    s->f46C = 0;
    s->f480 = 0;
    s->f4F4 = q->f0;
    s->f4F0 = (s32)RaceCourse__getCourseLength((void *)q->p80);
}
