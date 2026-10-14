typedef int s32;
typedef float f32;
struct Vec {
    f32 x;
    f32 y;
    f32 z;
};
struct Node {
    char pad0[0xD0];
    Vec v;
    f32 fDC;
};
struct Thing {
    char pad0[0x50];
    Node *f50;
};
struct Sub {
    char pad0[0x10];
    Thing *f10;
    char pad1[0x14];
    s32 f28;
};
struct Obj {
    Sub *f0;
    char pad4[0x5B8];
    s32 f5BC;
};
extern "C" void ModelSet2__render(s32 a, s32 b);
extern "C" void func_004A1638(s32 a);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7844(f32 a, f32 b, f32 c);
extern "C" void func_004A7900(f32 a, f32 b, f32 c);
extern "C" void func_004AB040(s32 a);
extern "C" void func_004533A8(Obj *arg0) {
    Sub *m = arg0->f0;
    if (m != 0) {
        s32 s1;
        if (arg0->f5BC != 0) {
            s1 = arg0->f5BC;
        } else {
            s1 = m->f28;
        }
        Thing *t = m->f10;
        Node *s0 = 0;
        if (t != 0) {
            s0 = t->f50;
        }
        if (s1 != 0 && s0 != 0) {
            func_004A53F8();
            f32 f20 = s0->fDC * 0.5f;
            Vec *vp = &s0->v;
            func_004A7844(vp->x, vp->y, vp->z);
            func_004A7900(f20, f20, f20);
            func_004A1638(0xE);
            func_004A1638(0x13);
            ModelSet2__render(s1, 0);
            func_004AB040(0x13);
            func_004AB040(0xE);
            func_004A5400();
        }
    }
}
