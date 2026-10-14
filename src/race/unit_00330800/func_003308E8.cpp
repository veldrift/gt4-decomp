typedef int s32;

struct Src {
    s32 p0;
    s32 pad4;
    s32 n8;
    s32 c12;
};

struct Out {
    s32 p0;
    float f4;
    float f8;
};

struct Loc {
    char pad[0x28];
    float a;
    char pad2[0xC];
    float b;
};

extern "C" s32 func_00105818(void *arg0);
extern "C" void func_004A5178(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3);
extern "C" void RaceEntryCar__update(s32 arg0);
extern "C" void func_004A7550(void *arg0);

extern "C" void func_003308E8(Out *o, Src *s, s32 c, s32 d) {
    Loc L;
    s32 r = func_00105818(s);
    s32 q = d * s->c12 / r;
    func_004A5178(s->p0, 0x30, s->n8, c, q, 8, 4, o->p0);
    RaceEntryCar__update(1);
    func_004A7550(&L);
    RaceEntryCar__update(0);
    o->f4 = L.b;
    o->f8 = L.a;
}
