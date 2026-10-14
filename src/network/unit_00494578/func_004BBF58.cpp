/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x2c]; int *kind; char *buffer; };
extern "C" char *func_004C8C20(Obj *, int);
extern "C" void func_004C3F90(void *, int);
extern "C" int func_004BBF58(Obj *self) {
    if (*self->kind == 0x65) return 0;
    self->buffer = func_004C8C20(self, 0x5a8);
    if (!self->buffer) return 0x80000341;
    func_004C3F90(self->buffer, 0x5a8);
    int offset = 0x4a0;
    for (int i = 0; i < 42; i++, offset += 4)
        *(int *)(self->buffer + offset) = 0;
    *(short *)(self->buffer + 0x548) = 0x7fff;
    *(int *)(self->buffer + 0x54c) = 0;
    return 0;
}
