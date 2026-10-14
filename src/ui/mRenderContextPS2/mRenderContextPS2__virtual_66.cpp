/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rect { char pad0[0x10]; int x, y, dx, dy; };
struct Ctx { int m0, m4, m8, mC, m10, m14, m18, m1C; float f20, f24; int m28, m2C, m30, m34, m38; };
extern "C" void func_00105280(Ctx *, int);
extern "C" void func_00105378(Ctx *, Rect *);
extern "C" void func_00105528(Ctx *);
extern "C" void func_001055C0(Ctx *);
extern "C" void func_001056A0(Ctx *);
extern "C" void func_00105728(Rect *);
extern "C" int func_00105918(Ctx *);
extern "C" void func_00105AD8(Rect *, Ctx *, int, int);
extern "C" Rect *func_00214F80(int) throw();
extern "C" int func_00215B80(void *) throw();
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004A29A8(int);
extern "C" void func_004A2C58(int, int, float);
extern "C" void func_004A4550(int, int);
extern "C" void pglPushAttrib(int);
extern "C" void func_004A5688(void);
extern "C" void func_004A6788(float, float, float, float, float, float, float, float);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_004AB040(int);
extern "C" void mRenderContextPS2__virtual_66(void *self, int n, float f) {
    Ctx c;
    if (!(f <= 0.0f) && n < 6) {
        pglPushAttrib(0x887);
        Rect *r = func_00214F80(func_00215B80(self));
        func_00105378(&c, r);
        c.m4 = 0;
        func_00105528(&c);
        func_001056A0(&c);
        func_00105728(r);
        func_004A4550(3, 1);
        func_004A4550(2, 1);
        func_004AB040(4);
        func_004AB040(5);
        func_004A1638(6);
        func_004A29A8(0);
        func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
        for (int i = 0; i < n; i++) {
            func_004A2C58(n, i, f);
            func_004A2808(100, 1.0f / (float)(i + 1));
            float w = (float)c.m18;
            func_004A6788(0.0f, 0.0f, w, (float)func_00105918(&c), (float)r->x, (float)r->y, (float)(r->x + r->dx), (float)(r->y + r->dy));
        }
        func_00105AD8(r, &c, 1, 1);
        func_001055C0(&c);
        func_004A5688();
        func_00105280(&c, 2);
    }
}
