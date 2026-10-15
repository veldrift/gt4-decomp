/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Sub { char pad0[8]; u16 w; u16 h; };
struct Obj { char pad0[8]; int f8; char padc[0xC]; Sub *f18; Sub *f1C; };
struct Obj2 { char pad0[0x18]; int f18; Sub *f1C; };
extern "C" void func_001056A0(void *);
extern "C" int func_00105818(void *);
extern "C" int func_00499728(void *);
extern "C" void func_0049CC48(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004A2980(int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A2A10(int);
extern "C" void pglPushAttrib(int);
extern "C" void func_004A5688(void);
extern "C" void func_004A5FE0(int);
extern "C" void func_004A6498(int, int, int, int, int, int, int, int);
extern "C" void func_004AA168(int);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_004AB040(int);

extern "C" int func_00473B18(Obj *a, Obj2 *b, Obj2 *c, float f) {
    Sub *sb = b->f1C; Sub *sc = c->f1C;
    int w = sb->w; int h = sb->h;
    if (sc->w != w || sc->h != h) return 0;
    if (w != a->f8 || h != func_00105818(a)) return 0;
    pglPushAttrib(0x8C7);
    func_001056A0(a);
    func_004A2A10(0);
    func_004A5FE0(0);
    func_004AB040(3);
    func_004AB040(4);
    func_004AB040(8);
    func_004A29A8(0);
    func_004A2808(0x44, 1.0f);
    func_004AA168(0x80FFFFFF);
    func_00499728(b);
    func_0049CC48(b->f18);
    func_004A6498(0, 0, w, h, 0, 0, w, h);
    func_004AA1D8(1.0f, 1.0f, 1.0f, f);
    func_004A2980(0xFFFFFF);
    func_00499728(c);
    func_0049CC48(c->f18);
    func_004A6498(0, 0, w, h, 0, 0, w, h);
    func_004A2980(-1);
    func_004A5688();
    return 1;
}
