/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { void *data; unsigned int desc; unsigned short x, y; };
struct Obj { char pad0[0x16]; unsigned short count; int pad18; Entry *entries; };
extern "C" int func_004A0F08(int);
extern "C" int func_004A0F38(int);
extern "C" int func_004A0F68(int);
extern "C" int func_004A1140(int, void *, int);
extern "C" void func_004A20C8();
extern "C" int func_004A4CA8(void *, void *, int, int, unsigned short, unsigned short);
extern "C" void func_005ADF20(int);
extern "C" void func_00499640(Obj *self) {
    char buf[0x60];
    func_004A20C8();
    for (int i = 0; i < self->count; i++) {
        Entry *e = &self->entries[i];
        int n = func_004A4CA8(buf, &e->desc, 0, 0, e->x, e->y);
        if (n != 0) {
            func_005ADF20(0);
            func_004A0F08(2);
            func_004A1140(2, buf, 6);
            func_004A1140(2, e->data, n);
            func_004A0F68(2);
            func_004A0F38(2);
        }
    }
}
