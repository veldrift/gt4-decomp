/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *, void *); };
struct Obj { VEntry *vtbl; char pad[4]; char data[0x600]; };
struct Src { char pad[0x10]; char *data; };
extern "C" void func_00364818(Obj *, void *) throw();
extern "C" void func_00364998(Obj *self, Src *src) {
    __builtin_memcpy((char *)self->vtbl + 0x600, src->data, 0x1100);
    func_00364818(self, (char *)src + 0x6DC);
    self->pad[0] = 1;
}
