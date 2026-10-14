/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int *values; char pad[20]; };
struct Obj { char pad0[0x88]; Entry *entries; char pad1[0x10]; unsigned short count; char pad2[0x1e]; unsigned int n; };
extern "C" int func_00524F70(Obj *, int) throw();
extern "C" void func_00526040(Obj *, int *, unsigned short *);
extern "C" int func_005250B8(Obj *self) {
    unsigned short index;
    int unused = 0;
    unsigned int i = 0xfffe;
    index = i;
    if (!self) return 2;
    if (self->entries) {
    func_00526040(self, &unused, &index);
    unsigned int current = index;
    if (current < self->count) {
        if (current != i) {
            i = 0;
            goto test;
            while (i < self->n) {
                if (*(int *)(index * 4 + *(int *)((char *)self->entries + i * 24))) {
                    int r = func_00524F70(self, i & 0xff);
                    if (r) return r;
                }
                ++i;
            test:;
            }
        }
    }
    }
    return 0;
}
