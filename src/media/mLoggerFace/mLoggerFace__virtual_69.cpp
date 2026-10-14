/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[0x2A4]; int active; };
struct Self { char pad0[0xA4]; Obj *obj; void *target; int enabled; };
extern "C" void mColorChipFace__virtual_69(Self *, void *, int);
extern "C" float func_00122CC0(Obj *);
extern "C" void func_002289F8(void *, float);
extern "C" void func_001206A0(Obj *, void *);
extern "C" void mLoggerFace__virtual_69(Self *self, void *arg1, int arg2) {
    mColorChipFace__virtual_69(self, arg1, 0);
    if (self->enabled != 0) {
        Obj *o = self->obj;
        if (o != 0) {
            if (o->active != 0) {
                void *p = self->target;
                if (p != 0) {
                    return func_002289F8(p, func_00122CC0(o));
                }
            } else if (arg2 != 0) {
                func_001206A0(o, arg1);
            }
        }
    }
}
