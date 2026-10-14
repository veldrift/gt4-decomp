struct VEntry { short delta; short index; int (*fn)(void *, void *); };
struct Blk { char b[0x11C0]; };
struct Obj { VEntry *vtbl; int pad; Blk body; };
extern "C" int func_0043A3C8(void *, int);
extern "C" int func_00435F18(void *, int);
extern "C" int func_0043DBA0(void *, int);
extern "C" int func_00438E60(void *, int);
extern "C" int func_00439750(void *, int);
extern "C" int func_00439A08(void *, int);
extern "C" int func_00439070(void *, int);

extern "C" int func_00437608(Obj *self, Blk *src) {
    self->body = *src;
    char *s = (char *)self;
    int r = func_0043A3C8(src, 0x11C0);
    r = func_00435F18(s + 0x11C8, r);
    r = func_0043DBA0(s + 0x11D0, r);
    r = func_00438E60(s + 0x1344, r);
    r = func_00439750(s + 0x13F4, r);
    r = func_00439A08(s + 0x1650, r);
    func_00439070(s + 0x16A4, r);
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, src);
}
