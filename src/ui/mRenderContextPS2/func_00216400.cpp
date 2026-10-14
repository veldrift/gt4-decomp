/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rect { char pad0[0x10]; int x, y, dx, dy; };
struct Ctx { char pad[8]; int width; };
extern "C" void func_001056A0(Ctx *);
extern "C" void func_00105728(Rect *);
extern "C" int func_00105818(Ctx *);
extern "C" void func_004A1638(int);
extern "C" void func_004A2980(int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A4550(int, int);
extern "C" void pglPushAttrib(int);
extern "C" void func_004A5688(void);
extern "C" void func_004A6788(float, float, float, float, float, float, float, float);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_004AB040(int);
extern "C" void func_00216400(Rect *r, Ctx *c, int mode, float dx, float dy) {
    func_004A2980(0xFFFFFF);
    pglPushAttrib(0x887);
    func_00105728(r);
    func_001056A0(c);
    func_004A4550(3, mode);
    func_004A4550(2, mode);
    func_004AB040(4);
    func_004AB040(5);
    func_004A1638(6);
    func_004A29A8(0);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
    float w = (float)c->width;
    float h = (float)func_00105818(c);
    float x0 = (float)r->x + dx;
    float x1 = (float)(r->x + r->dx) + dx;
    float y1 = (float)(r->y + r->dy) + dy;
    float y0 = (float)r->y + dy;
    func_004A6788(0.0f, 0.0f, w, h, x0, y0, x1, y1);
    func_004A5688();
    func_004A2980(-1);
}
