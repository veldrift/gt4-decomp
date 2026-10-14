/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, int, float, int, int); };
struct Self { char pad[0x10140]; VEntry *vtbl; };
struct Entrant { char pad[0x75F]; unsigned char flag; };
extern "C" Entrant *func_0034C190(Self *, int);
extern "C" void DynamicsConductorLicense__ProcessStartLine(Self *self, int a, float f, int b, int c) {
    func_0034C190(self, a)->flag = 0;
    VEntry *e = &self->vtbl[20];
    e->fn((char *)self + e->delta, a, f, b, c);
}
