typedef int s32;
struct B60 { s32 cnt; char pad[4]; s32 p8; };
struct Q { char pad[0x60]; s32 p60; char pad2[0x70 - 0x64]; s32 p70; };
struct W { char pad[0x6C]; s32 q; };
struct Self {
    char pad0[4];
    char s4[0x444];
    s32 f448, f44C, f450;
    char pad1[0x46C - 0x454];
    s32 f46C, f470, f474, f478;
    char pad2[0x480 - 0x47C];
    s32 f480;
    char pad3[0x4A4 - 0x484];
    s32 f4A4;
};
extern char *D_00622F4C;
extern "C" char *func_00445450(char *);
extern "C" s32 func_00445AE8(char *, char *);
extern "C" char *func_004472A0(void *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getBronzeTime(void *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getGoldTime(void *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getSilverTime(void *);
extern "C" char *func_005A609C(char *, const char *);

#define QQ(w) ((Q *)(w)->q)
#define BB(w) ((B60 *)QQ(w)->p60)

extern "C" void func_0011BFE8(char *self, W *w) {
    s32 n = BB(w)->cnt;
    s32 i;
    for (i = 0; i < n; ) {
        s32 off = i * 4;
        i++;
        char *o = *(char **)(off + BB(w)->p8);
        s32 idx = *(s32 *)(o + 0x3444);
        func_005A609C(self + idx * 0x80 + 4, func_00445450(o + 0x20));
        off += BB(w)->p8;
        char *p = self + idx * 16;
        char *o2 = *(char **)off;
        func_00445AE8(o2 + 0x20, p + 0x304);
    }
    Self *s = (Self *)self;
    s->f46C = 0;
    s->f470 = 0;
    s->f474 = 0;
    s->f480 = 0;
    s->f4A4 = 0;
    func_005A609C(self + 0x3C8, D_00622F4C + 0x46);
    func_005A609C(self + 0x408, func_004472A0((void *)QQ(w)->p70));
    s->f478 = n;
    s->f448 = SPEC_DATABASE__RaceSpec__getBronzeTime((void *)QQ(w)->p70);
    s->f44C = SPEC_DATABASE__RaceSpec__getGoldTime((void *)QQ(w)->p70);
    s->f450 = SPEC_DATABASE__RaceSpec__getSilverTime((void *)QQ(w)->p70);
}
