/* compiler: ee-gcc2.96-nogcse */
typedef int s32; typedef float f32; typedef unsigned char u8; typedef unsigned short u16;

struct World {
    char pad0[0xCBD8];
    s32 iCBD8;
    char padCBDC[2];
    u8 bCBDE;
    char padCBDF[0xDA50 - 0xCBDF];
    char subDA50[0x1C];
    char subDA6C[1];
};
struct S {
    f32 f0, f4, f8;
    char padC[0x467 - 0xC];
    u8 b467;
    char pad468[0x4A4 - 0x468];
    f32 f4A4;
    char pad4A8[0x4BC - 0x4A8];
    u8 b4BC;
    char pad4BD[0x544 - 0x4BD];
    f32 f544, f548;
    char pad54C[0x654 - 0x54C];
    f32 f654;
    u16 h658;
    u8 b65A;
};
struct Obj {
    char pad0[4];
    World *world;
    char pad8[0x30 - 8];
    u8 b30;
    char pad31[0x104 - 0x31];
    S s;
};

extern "C" void func_003455F0(Obj *);
extern "C" void func_003630C0(Obj *, s32, f32, f32, f32, f32);
extern "C" void func_00363560(Obj *);
extern "C" void func_003F4B20(World *);
extern "C" void func_003F71A0(Obj *, s32);
extern "C" void func_0045B8C0(void *, World *, s32);
extern "C" void func_0046ADE8(void *, s32, f32 *, f32 *, f32 *, f32 *, f32 *, s32, f32);

static inline f32 fsqrt(f32 x) { f32 r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" void func_003663A0(Obj *self) {
    S *s = &self->s;
    f32 v[5];
    if (s->b65A == 0) {
        if (s->b467 == 3) return;
        if (s->b4BC != 0) return;
        f32 dx = s->f544;
        f32 dy = s->f548;
        f32 acc = s->f654;
        s->h658 = s->h658 + 1;
        acc += fsqrt(dx * dx + dy * dy);
        s->f654 = acc;
        if (s->h658 == 300) {
            if (acc < 60.0f) s->b65A = 1;
            s->h658 = 0;
            s->f654 = 0.0f;
        }
        if (s->b65A == 0) return;
    }
    World *w = self->world;
    func_0046ADE8(w->subDA50, self->b30, &v[4], &v[0], &v[1], &v[2], &v[3], w->bCBDE == 1, s->f4A4);
    func_003630C0(self, 0, s->f0, s->f4, s->f8, v[3]);
    func_003455F0(self);
    func_00363560(self);
    func_003F4B20(w);
    func_0045B8C0(w->subDA6C, w, w->iCBD8);
    func_003F71A0(self, 0);
    s->b65A = 0;
}
