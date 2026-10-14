/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void (*fn)(void *, char *); };
struct Row { char pad[0x3C]; char text[0x80]; int dirty; };
struct Result { char pad[0xC]; Entry *vtbl; char pad10[0x50]; Row rows[6]; };
extern "C" void ResultArcade__setCarName(Result *self, int index) {
    Entry *e = self->vtbl + 10;
    e->fn((char *)self + e->delta, self->rows[index].text);
    self->rows[index].dirty = 1;
}
