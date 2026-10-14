/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Obj;
struct VEG { short delta; short index; Obj *(*fn)(void *, s32); };
struct VES { short delta; short index; void (*fn)(void *, s32); };
struct VEV { short delta; short index; void (*fn)(void *); };
struct VT { char pad[0x38]; VES e38; char pad2[8]; VEV e48; };
struct Obj { VT *vt; char pad[0xAC]; s32 w; s32 h; };
struct VTS { char pad[0xC8]; VEG eC8; };
struct G { char pad[0x20]; s32 f20; };

extern char D_006184D0[];
extern "C" void RaceDisplay__setProjectionMatrix(void *, f32, f32, f32, f32);

extern "C" void RaceSplitDisplayBase__initialize(void *arg0) {
    s32 i;
    s32 wb = 0x140, hb = 0x1C0, wa = 0x280, ha = 0xE0;
    G *g = (G *)D_006184D0;
    for (i = 0; i < 2; i++) {
        VEG *e = &(*(VTS **)arg0)->eC8;
        Obj *o = e->fn((char *)arg0 + e->delta, i);
        if (g->f20 != 0) {
            VES *e2 = &o->vt->e38;
            e2->fn((char *)o + e2->delta, 9);
        } else {
            VES *e2 = &o->vt->e38;
            e2->fn((char *)o + e2->delta, 8);
        }
        VEV *e3 = &o->vt->e48;
        e3->fn((char *)o + e3->delta);
        if (g->f20 != 0) {
            RaceDisplay__setProjectionMatrix(o, -106.666664f, 320.0f, 480.0f, 0.0f);
            o->w = wb;
            o->h = hb;
        } else {
            f32 f = -10.0f;
            if (i != 0) {
                f = 0.0f;
            }
            RaceDisplay__setProjectionMatrix(o, 0.0f, 640.0f, f + 240.0f, f);
            o->w = wa;
            o->h = ha;
        }
    }
}
