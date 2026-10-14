/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long s64;
struct V { short d, i; s32 (*fn)(void *, void *); };
struct W { short d, i; void (*fn)(void *); };
struct VT64 { char p[0x2C0]; W w2C0; char q[0x300 - 0x2C0 - 8]; V v300; };
struct B64 { char p[0x64]; VT64 *vt; };
struct P0 { s64 pad[4]; };
struct P1 { P0 *u0; };
struct P2 { char p[8]; P1 *u8; };
struct S4 { char p[0x60]; P2 *u60; char q[0xC]; s32 u70; };
struct Rec { s64 u0; s64 u8; s32 u10; s32 u14; s32 u18; void *u1C; };
struct B {
    char p0[0x64]; VT64 *vt; char p1[0x6C - 0x68]; S4 *u6C;
    char p2[0xCC8 - 0x70]; s32 uCC8;
    char p3[0xF0F8 - 0xCCC]; s32 uF0F8; s32 uF0FC;
};
struct A { char p[0x46C]; s32 u46C; char q[4]; s32 u474; char r[0x4B0 - 0x478]; s32 u4B0; };
extern "C" void func_0010FE40(void *);
extern "C" void func_001234F0(int);
extern "C" Rec *func_001D3A60(void);
extern "C" void func_001D3AD0(void *);
extern "C" void func_00387EF0(void *, s32, int);
extern "C" void func_003BFCB0(void *, s32);
extern "C" void func_003BFFE8(void *);
extern "C" void func_003C0008(void *);
extern "C" void func_003EA2A8(void *);
extern "C" void func_003EA410(void *);
extern "C" s32 func_003EB0D0(void *);
extern "C" void func_0042FC98(s32, void *);
extern "C" s64 func_004454C0(void *);
extern "C" s64 SPEC_DATABASE__RaceSpec__getCourseCode(s32);
extern char D_0068D288[], D_0068D290[], D_0068D2B0[];
extern s32 D_00618714, D_00618718, D_00622F4C;
extern "C" void func_0010FEE8(A *a, B *b) {
    S4 *s4 = b->u6C;
    func_003EA410(b);
    func_003BFCB0(s4, 1);
    s32 saved = a->u4B0;
    s32 one = 1;
    D_00618718 = one;
    func_001234F0((int)b);
    for (;;) {
        func_0010FE40(D_0068D288);
        if (D_00618714 < 0) break;
        b->uF0FC = D_00618714;
        Rec *r = func_001D3A60();
        s64 *s0 = (s64 *)((char *)s4->u60->u8->u0 + 0x20);
        s32 s2 = s4->u70;
        func_001D3AD0(r);
        r->u0 = func_004454C0(s0);
        r->u8 = SPEC_DATABASE__RaceSpec__getCourseCode(s2);
        V *v = &b->vt->v300;
        s32 res = v->fn((char *)b + v->d, &r->u14);
        r->u1C = b;
        r->u10 = res;
        r->u18 = -1;
        func_0042FC98(D_00622F4C + 0x3A368, D_0068D290);
        b->uF0F8 = 0;
        func_003C0008(s4);
        func_0010FE40(D_0068D2B0);
        func_003BFFE8(s4);
        if (b->uF0F8 != 0) a->u4B0 = 1;
        func_00387EF0(b, b->uCC8, 1);
        W *w = &b->vt->w2C0;
        w->fn((char *)b + w->d);
    }
    func_001234F0(0);
    a->u4B0 = saved;
    if (func_003EB0D0(b) != 0) {
        a->u4B0 = 0;
        a->u46C = 0;
        a->u474 = 0;
    }
    func_003BFCB0(s4, 0);
    func_003EA2A8(b);
}
