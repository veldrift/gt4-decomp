struct Obj { void *field0; };
extern "C" void func_004595C8(void *);
extern "C" void func_00459610(void *, float);

extern "C" void RaceCarModel__virtual_32(Obj *arg0, float value) {
    func_004595C8(arg0->field0);
    func_00459610(arg0->field0, value);
}
