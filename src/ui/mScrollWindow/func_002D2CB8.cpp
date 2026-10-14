/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_002D3430(void *, void *, float *, float *);
extern "C" void mWidget__setWindowPosition(void *, float, float);
struct Obj { char pad[0xC0]; void *child; };
extern "C" void func_002D2CB8(Obj *self, void *component) {
    float position[2];
    if (component) {
        func_002D3430(self, component, &position[0], &position[1]);
        mWidget__setWindowPosition(self->child, position[0], position[1]);
    }
}
