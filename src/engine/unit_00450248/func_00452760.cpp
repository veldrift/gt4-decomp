/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Inner {
    char pad0[0x18];
    void *f18;
};

struct Self {
    Inner *inner;
};

extern "C" void *func_00450FE0(Self *) throw();
extern "C" void func_00452418(float, float, Self *) throw();
extern "C" void func_00452480(Self *) throw();
extern "C" void ModelSet2__begin(void *, void *);
extern "C" void ModelSet2__end(void *);
extern "C" void ModelSet2___render(void *, int, void *);
extern "C" void func_004A60E0(float, float, float, float);
extern "C" void func_004A6100(float, float, float, float);

extern float D_008465B0[4];

extern "C" void func_00452760(int arg0, float t)
{
    Self *self = (Self *)arg0;
    void *s2 = self->inner != 0 ? self->inner->f18 : 0;
    void *s0 = func_00450FE0(self);
    if (s2 != 0 && s0 != 0) {
        ModelSet2__begin(s2, s0);
        func_004A6100(0.0f, 0.0f, 0.0f, 0.0f);
        func_004A60E0(1.0f, 1.0f, 1.0f, t);
        ModelSet2___render(s2, 2, s0);
        ModelSet2__end(s2);
    }
}
