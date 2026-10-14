struct VEntry { short delta; short index; int (*fn)(void *, void *); };
struct C { VEntry *vtbl; };
struct Blk { char b[0x11C0]; };
struct Obj { VEntry *vtbl; int pad; Blk body; };
extern "C" int func_0043A398(void *, int);
extern "C" int func_00435EB0(void *, int);
extern "C" int func_0043DB20(void *, int);
extern "C" int func_00438D88(void *, int);
extern "C" int func_00439700(void *, int);
extern "C" int func_004398E0(void *, int);
extern "C" int func_00439010(void *, int);

extern "C" int func_004374A8(Obj *self, Blk *dst) {
    *dst = self->body;
    char *s = (char *)self;
    int r = func_0043A398(dst, 0x11C0);
    r = func_00435EB0(s + 0x11C8, r);
    r = func_0043DB20(s + 0x11D0, r);
    r = func_00438D88(s + 0x1344, r);
    r = func_00439700(s + 0x13F4, r);
    r = func_004398E0(s + 0x1650, r);
    func_00439010(s + 0x16A4, r);
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, dst);
}
