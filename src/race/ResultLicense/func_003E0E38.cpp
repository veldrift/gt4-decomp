/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Vec { float x, y, z; };
struct Data { float x0, y0, x1, y1; char *name; };
struct Tmp { char pad[0x14]; float f14; char pad18[8]; };
struct Buf { char b[0x40]; };
struct Glob { char pad[0x3A360]; s32 f3A360; };
struct Obj {
    char pad0[0x564]; void *o564; float o568; char pad56C[0xC]; s32 o578; s32 o57C; float o580;
};
extern Glob *D_00622F4C;
extern "C" s32 func_0057F238(const char *, const char *) throw();
extern "C" void func_0049E2D8(Vec *, Vec *);
extern "C" void func_0033DD88(void *, float, float, float, float);
extern "C" void func_0033DE30(void *, Tmp *);
extern "C" void func_003EFEA8(Tmp *);
extern "C" void func_00454C58(s32, s32, float);
extern "C" void pglPushAttrib(s32);
extern "C" void func_004A5688(void);
extern "C" void func_004AA4A0(void);
extern "C" void func_00105250(Buf *);
extern "C" void func_00105280(Buf *, s32);
extern "C" void func_003E1FF0(Obj *, Buf *);
extern "C" void func_003E0FF8(Obj *, Buf *);
extern "C" void func_003E13E8(Obj *, Buf *);
extern "C" void func_003E0E38(Obj *self, s32 a1, s32 a2, Data *data) {
    Vec v;
    Tmp t;
    Buf buf;
    if (func_0057F238("screen", data->name) == 0) {
        v.x = data->x0;
        v.y = data->y0;
        v.z = 0;
        func_0049E2D8(&v, &v);
        float fx = v.x, fy = v.y;
        v.z = 0;
        v.x = data->x1;
        v.y = data->y1;
        func_0049E2D8(&v, &v);
        float x1 = v.x, y1 = v.y;
        if (self->o564) func_0033DD88(self->o564, fx, fy, x1 - fx, y1 - fy);
        self->o568 = self->o568 * 0x1.f5c28ep-1f;
        if (self->o564) {
            func_003EFEA8(&t);
            t.f14 = t.f14 * self->o568;
            func_0033DE30(self->o564, &t);
        }
    } else if (self->o57C != 0) {
        if (self->o580 > 0.0f) {
            if (self->o578 != 0) func_00454C58(self->o578, -1, self->o580);
        }
        pglPushAttrib(0x8C7);
        func_00105250(&buf);
        func_003E1FF0(self, &buf);
        func_004AA4A0();
        if (D_00622F4C->f3A360 == 0) func_003E0FF8(self, &buf);
        else func_003E13E8(self, &buf);
        func_00105280(&buf, 2);
        func_004A5688();
        self->o580 = 0.0f;
    }
}
