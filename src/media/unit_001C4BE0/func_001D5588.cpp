struct Obj { char pad[0x7C]; void *f7C; };
extern "C" void ModelSet2__begin(Obj *self, void *v);
extern "C" void ModelSet2__end(Obj *self);
extern "C" void ModelSet2___render(Obj *self, int arg1, void *v);
extern "C" void func_004A60E0(float a, float b, float c, float d);
extern "C" void func_004A6100(float a, float b, float c, float d);

extern "C" void func_001D5588(Obj *self, int arg1, float fparg0) {
    if (!(fparg0 < 0.0078125f)) {
        ModelSet2__begin(self, self->f7C);
        func_004A60E0(1.0f, 1.0f, 1.0f, fparg0);
        func_004A6100(0.0f, 0.0f, 0.0f, 0.0f);
        ModelSet2___render(self, arg1, self->f7C);
        ModelSet2__end(self);
    }
}
