/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Part { unsigned char bytes[0x88]; };
struct Obj { char pad[0xC]; Part part; unsigned short counter[2]; };
extern "C" void func_00251838(Obj *self, int i) {
    self->counter[i] = 0;
    self->part.bytes[i * 2 + 0x70] = 0;
    self->part.bytes[i * 2 + 0x71] = 0;
}
