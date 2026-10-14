/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, float); };
struct Target { char *vtbl; };
struct Obj { char pad[0xC40]; float value; Target *target; };
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7550(void *);
extern "C" void func_004A7890(float, float, float);
static inline void call(Obj *self, float value) {
    Target *target = self->target;
    VEntry *e = (VEntry *)(target->vtbl + 0x10);
    e->fn((char *)target + e->delta, value);
}
extern "C" void DevelopCamera__virtual_01(Obj *self, float value) {
    float matrix[16];
    if (self->value != 0.0f) {
        func_004A53F8();
        func_004A7454();
        call(self, value);
        func_004A7550(matrix);
        func_004A5400();
        float scale = matrix[5] / matrix[0];
        func_004A7890(scale, 1.0f / scale, 1.0f);
    }
    call(self, value);
}
