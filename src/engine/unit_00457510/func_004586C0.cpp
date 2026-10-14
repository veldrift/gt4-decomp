/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buffer { char pad[0x10]; int size; };
struct Obj { char pad[0x2C]; Buffer *slots[2]; };
extern "C" int func_00458400(void *, void *, int) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" Buffer *func_004586C0(Obj *self, int which, int size) {
    int offset = which == 0;
    offset *= 4;
    Buffer **slot = (Buffer **)(offset + (int)self + 0x2C);
    Buffer *p = *slot;
    *slot = 0;
    func_00458400(self, p, (size - p->size + 15) & ~15);
    *slot = p;
    func_005A48D8(p, 0, size);
    return *slot;
}
