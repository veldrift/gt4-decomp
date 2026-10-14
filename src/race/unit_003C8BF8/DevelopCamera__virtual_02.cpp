/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, float); };
struct Target { char *vtbl; };
struct Obj { char pad[0xC40]; float value; Target *target; };
extern "C" void func_004A79D8(float);
extern "C" void DevelopCamera__virtual_02(Obj *self, float value) {
    func_004A79D8(self->value);
    Target *target = self->target;
    VEntry *e = (VEntry *)(target->vtbl + 0x18);
    e->fn((char *)target + e->delta, value);
}
