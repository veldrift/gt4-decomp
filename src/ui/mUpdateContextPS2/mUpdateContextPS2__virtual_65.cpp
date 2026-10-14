/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int handle; char pad[0xD0]; };
extern const char *D_0064D3D8[];
extern "C" void mUpdateContext__virtual_65(void *);
extern "C" int func_0055F420(const char *);
extern "C" void func_0055FAB0(void *, void *);
extern "C" void mUpdateContextPS2__virtual_65(char *self) {
    mUpdateContext__virtual_65(self);
    void *ctx = self + 0x160;
    Entry *p = (Entry *)(self + 0x1A0);
    const char **names = D_0064D3D8;
    int n = 1;
    do {
        p->handle = func_0055F420(*names++);
        func_0055FAB0(ctx, p);
        p++;
        n--;
    } while (n >= 0);
}
