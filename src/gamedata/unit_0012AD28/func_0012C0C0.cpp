/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct VE3 { s16 delta; s16 index; void (*fn)(void *, void *, s32, f32); };
struct VE2 { s16 delta; s16 index; void (*fn)(void *, void *); };
struct Rect { f32 x, y, w, h, s; };
static inline void setRect(Rect *r, f32 scale, f32 x, f32 y, f32 w, f32 h) {
    r->y=y; r->x=x; r->w=w; r->h=h; r->s=scale;
}
struct G {
    char pad0[0x64];
    char *vt;
    char pad68[0xE2E0 - 0x68];
    Rect r;
};

struct Table { char pad[0x78]; s32 cur; };
extern "C" Table D_0061850C;
extern "C" G *D_00618840;

extern "C" void func_00105250(char *);
extern "C" void func_00105280(char *, int);
extern "C" void *func_00105378(char *, void *);
extern "C" void func_001054C0(char *, s32, s32, s32, s32);
extern "C" f32 mWidget__getWindowX(void *);
extern "C" f32 mWidget__getWindowY(void *);
extern "C" f32 mWidget__getWindowW(void *);
extern "C" f32 mWidget__getWindowH(void *);
extern "C" void func_004A1638(s32);
extern "C" void func_004AB040(s32);

extern "C" void func_0012C0C0(void *widget) {
    char buf[0x40];
    s32 x = (s32)mWidget__getWindowX(widget);
    s32 y = (s32)mWidget__getWindowY(widget);
    s32 w = (s32)mWidget__getWindowW(widget);
    s32 h = (s32)mWidget__getWindowH(widget);
    func_004AB040(0x12);
    void *elem = (char *)&D_0061850C + D_0061850C.cur * 0x3C;
    func_00105250(buf);
    func_00105378(buf, elem);
    func_001054C0(buf, x, y, w, h);
    G *g = D_00618840;
    Rect *r = &g->r;
    setRect(r, 1.3f, (f32)(w / 2 - 60), 10.0f, 120.0f, 32.0f);
    G *a = D_00618840;
    VE3 *e1 = (VE3 *)(a->vt + 0x368);
    e1->fn((char *)a + e1->delta, buf, 0, 1.0f);
    G *b = D_00618840;
    VE2 *e2 = (VE2 *)(b->vt + 0x360);
    e2->fn((char *)b + e2->delta, buf);
    func_004A1638(0x12);
    func_00105280(buf, 2);
}
