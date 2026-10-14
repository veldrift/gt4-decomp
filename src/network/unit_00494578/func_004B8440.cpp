/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Entry { int x[2]; };
struct Bank { char pad[0x214]; s32 count; };
struct Obj {
    char pad0[0x858];
    s32 sel;
};
extern "C" void func_004B49B8(void *, void *, void *, s32) throw();
extern "C" void func_004B6880(void *) throw();
extern "C" void func_004B8440(Obj *self) {
    char buf[0x800];
    char *a1 = (char *)self + (1 - self->sel) * 0x41C;
    Bank *b = (Bank *)(a1 + 0x20);
    Entry *p;
    s32 i = 0;
    if (b->count > 0) {
        p = (Entry *)(a1 + 0x238);
        a1 = (char *)p;
        do {
            i += 1;
            func_004B49B8(self, p++, buf, 0x400);
            a1 = (char *)p;
        } while (i < b->count);
    }
    func_004B6880(self);
}
