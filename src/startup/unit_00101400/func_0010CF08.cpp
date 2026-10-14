typedef int s32;
struct Obj { char pad0[0x64]; s32 f64; char pad1[0xCE0 - 0x68]; s32 fce0; };
struct VEntry { short delta; short pad; void (*fn)(void *self, s32 arg); };

extern "C" s32 D_00622F4C;
extern "C" char D_0068D068[];
extern "C" void func_0010CEB8(void);
extern "C" void func_0042FC10(void *arg0, void *arg1);

extern "C" void func_0010CF08(Obj *self) {
    VEntry *e = (VEntry *)((char *)self->f64 + 0x328);
    e->fn((char *)self + e->delta, 0);
    s32 v = self->fce0;
    if (v >= 3) {
        if (v < 5) {
            return;
        }
        if (v == 7) {
            func_0010CEB8();
            return func_0042FC10((char *)(D_00622F4C + 0x3A368), D_0068D068);
        }
    }
    VEntry *e2 = (VEntry *)((char *)self->f64 + 0x328);
    e2->fn((char *)self + e2->delta, 2);
}
