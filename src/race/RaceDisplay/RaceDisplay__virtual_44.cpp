/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
typedef float f32;

struct Msg {
    char pad0[0x18];
    f32 f18;
    f32 f1C;
    u32 color;
};

struct List { char pad[8]; char **items; };
struct Info { char pad[0x60]; List *list; char pad64[0x84 - 0x64]; struct Dev *dev; };
struct VEntry { s16 delta; s16 index; s32 (*fn)(void *self, s32 *a); };
struct Dev { char pad[0x64]; char *vtbl; };

struct Self {
    char pad0[4];
    Info *info;
    char pad8[0x2F - 8];
    signed char id2F;
    char pad30[0x267C - 0x30];
    Msg m267C;
    char pad2698[0x27CC - 0x267C - sizeof(Msg)];
    Msg m27CC;
};

extern char D_006A0540[];
extern char D_006A0580[];
extern char D_006A0588[];
extern char D_006A0590[];
extern char D_006A0598[];
extern char D_006A05A0[];
extern char D_006A05A8[];
extern char D_006A05B8[];
extern char PDISTD__UNIT_MANAGER[];

extern "C" {
void ShowRoomCar__structor_0(char *);
void ShowRoomCar__structor_1(char *, s32);
void func_00364868(char *, char *, s32);
f32 func_00364E78(char *, s32 *);
void RaceMessageDisplay__setMessage(void *, const char *, f32, f32);
void RaceMessageDisplay__setFont(void *, const char *, s32);
char *DisplayRText__getRTextStr(s32);
void RaceDisplayObjectBase__setLocation(void *, s32, s32);
const char *func_003B03B8(s32);
s32 func_004454C0(char *);
s32 func_004462E0(char *);
s32 func_00446320(char *);
void func_00448820(s32, char *);
s32 func_004489A0(char *, s32);
const char *func_004726B8(char *);
f32 func_004729A0(char *, f32);
s32 func_0057DA20(char *, const char *, ...);
char *func_005A609C(char *, const char *);
}

extern "C" void RaceDisplay__virtual_44(Self *self, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    char buf[0x80];
    char sp80[0x20];
    char sa0[0x10];
    s32 spB0;
    char spC0[0x20];
    char spE0[0x20];
    char sp100[0x80];
    f32 f20 = 0.0f;
    Msg *m = &self->m267C;
    char *s1 = self->info->list->items[self->id2F];
    RaceMessageDisplay__setFont(m, D_006A0540, 1);
    m->f18 = fparg2;
    m->f1C = fparg3;
    m->color = 0x80C8C8C8;
    RaceDisplayObjectBase__setLocation(m, 0x140, 0xDC);
    RaceMessageDisplay__setMessage(m, s1 + 0x348C, fparg1, fparg0);
    s1 += 0x20;
    Dev *s4 = self->info->dev;
    buf[0] = 0;
    func_00448820(func_004454C0(s1), sp80);
    ShowRoomCar__structor_0(sa0);
    func_00364868(sa0, s1, 0);
    if (func_004489A0(sp80, 3) == 0) {
        f20 = func_004729A0(PDISTD__UNIT_MANAGER, func_00364E78(sa0, &spB0));
    }
    const char *v0 = func_004726B8(PDISTD__UNIT_MANAGER);
    if (f20 > 0.0f) {
        func_0057DA20(spC0, D_006A0580, (s32)f20, v0);
    } else {
        func_0057DA20(spC0, D_006A0588, v0);
    }
    const char *s0 = func_003B03B8(func_004462E0(s1));
    func_0057DA20(spE0, D_006A0590, s0, func_003B03B8(func_00446320(s1)));
    *(u16 *)sp100 = *(u16 *)D_006A0598;
    spB0 = -1;
    VEntry *e = (VEntry *)(s4->vtbl + 0x308);
    s32 r = e->fn((char *)s4 + e->delta, &spB0);
    if (r != 0) {
        char *t = DisplayRText__getRTextStr(r);
        if (t != 0) {
            if (spB0 > 0) {
                func_0057DA20(sp100, D_006A05A0, t, spB0);
            } else {
                func_005A609C(sp100, t);
            }
        }
    }
    char *t2 = DisplayRText__getRTextStr((s32)D_006A05A8);
    if (t2 != 0) {
        func_0057DA20(buf, t2, spC0, spE0, sp100);
    }
    ShowRoomCar__structor_1(sa0, 2);
    Msg *m2 = &self->m27CC;
    RaceMessageDisplay__setFont(m2, D_006A05B8, 1);
    m2->color = 0x80C8C8C8;
    m2->f18 = fparg2;
    m2->f1C = fparg3;
    RaceDisplayObjectBase__setLocation(m2, 0x140, 0x104);
    RaceMessageDisplay__setMessage(m2, buf, fparg1, fparg0);
}
