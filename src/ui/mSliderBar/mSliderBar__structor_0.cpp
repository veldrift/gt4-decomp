/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Range { int index, min, max, step, extra; };
struct Vec { float x,y,z; Vec() : x(0.0f), y(0.0f), z(0.0f) {} };
struct Slider { int first; void *vt; char pad8[0xB8]; int c0,c4,c8; Range range; int e0,e4,e8; Vec vec; int f8,fc,f100,f104,f108,f10c; };
extern char mSliderBar__vtable[];
extern "C" void *mFBox__structor_0(Slider *);
extern "C" void func_002FA120(void *);
extern "C" void func_0025B4C8(Slider *, float, float);
extern "C" void func_00265F10(Slider *, int);
extern "C" void func_00206858(Slider *, int);
extern "C" void func_0057CD90(Range *, int, int);
inline void *operator new(unsigned int, void *p) { return p; }
extern "C" void mSliderBar__structor_0(Slider *self) {
 Range *r = &self->range;
 mFBox__structor_0(self);
 self->vt = mSliderBar__vtable;
 self->c0 = 0;
 self->c4 = 0;
 func_002FA120(&self->c8);
 r->index = 0;
 r->min = 0;
 r->max = 1;
 r->step = 1;
 r->extra = 0;
 self->e0 = 0;
 self->e4 = 1;
 self->e8 = 1;
 Vec *v = &self->vec;
 new (v) Vec;
 self->f8 = 0; self->fc = 0; self->f100 = 0; self->f104 = 0; self->f108 = 0; self->f10c = 0;
 func_0025B4C8(self, 256.0f, 24.0f);
 func_00265F10(self, 1);
 func_00206858(self, 0);
 func_0057CD90(r, 0, 2);
 r->step = 0;
}
