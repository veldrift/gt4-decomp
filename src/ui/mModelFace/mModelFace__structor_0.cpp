/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Obj {
    char pad0[4];
    void *vt;
    char pad8[0x2B8 - 8];
    char *s2B8;
    s32 f2BC;
    char pad2C0[0x2C8 - 0x2C0];
    char *s2C8;
    s32 f2CC;
    char pad2D0[0x2D8 - 0x2D0];
    char *s2D8;
    char pad2DC[4];
    s32 f2E0;
    float v2E4[3];
    float v2F0[3];
    float v2FC[3];
    unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1;
};
extern Rep D_00659FA8;
extern char mModelFace__vtable[];
extern "C" char *func_005C2560(Rep *r);
extern "C" int mWidget__structor_0(void *);
extern "C" void MModel__structor_0(void *);
extern "C" void func_00201EC8(void *);
extern "C" void func_00210830(void *);
extern "C" void func_0021B6D0(void *);
extern "C" void func_00210810(void *);
extern "C" void func_0021B480(void *);

#define GRAB(dst) { Rep *r = &D_00659FA8; char *d; if (r->sel != 0) { d = func_005C2560(r); } else { d = (char *)(r + 1); r->ref++; } dst = d; }
struct Vec3 { float x, y, z; };

extern "C" int mModelFace__structor_0(Obj *o) {
    char **p1 = &o->s2B8;
    char **p2 = &o->s2C8;
    char **p3 = &o->s2D8;
    mWidget__structor_0(o);
    o->vt = mModelFace__vtable;
    MModel__structor_0((char *)o + 0xA0);
    func_00201EC8((char *)o + 0xEC);
    func_00210830((char *)o + 0x154);
    GRAB(*p1);
    o->f2BC = 0;
    func_0021B6D0((char *)o + 0x2C0);
    func_0021B6D0((char *)o + 0x2C4);
    GRAB(*p2);
    o->f2CC = 0;
    func_00210810((char *)o + 0x2D0);
    func_00210810((char *)o + 0x2D4);
    GRAB(*p3);
    func_0021B480((char *)o + 0x2DC);
    o->f2E0 = 1;
    float z = 0.0f;
    Vec3 *a = (Vec3 *)o->v2E4;
    Vec3 *b = (Vec3 *)o->v2F0;
    Vec3 *c = (Vec3 *)o->v2FC;
    a->x = z; a->y = z; a->z = z;
    b->x = z; b->y = z; b->z = z;
    c->x = z; c->y = z; c->z = z;
    o->b0 = 0; o->b1 = 0; o->b2 = 1; o->b3 = 0; o->b4 = 1; o->b5 = 0; o->b6 = 1; o->b7 = 0; o->b8 = 1; o->b9 = 0;
}
