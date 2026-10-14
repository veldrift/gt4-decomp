/* compiler: ee-gcc2.96-no-strict-aliasing */
struct B32 { char x[32]; };
struct B28 { char x[28]; };
struct VE { short d, p; int (*fn)(void *, void *); };
struct Src { B32 e[1000]; B28 tail; };
struct Self {
    VE *vptr;
    int pad;
    B32 e[1000];
    char gap[0x81C8 - 0x7D08];
    B28 tail;
    int pad2[3];
    int f81F0;
};
extern "C" int func_0043DEF0(void *self, void *src);

static inline int read32(char *p, B32 *dst) { *dst = *(B32 *)p; return sizeof(B32); }
static inline int read28(char *p, B28 *dst) { *dst = *(B28 *)p; return sizeof(B28); }

extern "C" void func_00435BC8(Self *self, Src *src) {
    char *p = (char *)src;
    for (int i = 0; i < 1000; i++) p += read32(p, &self->e[i]);
    p += read28(p, &self->tail);
    func_0043DEF0((char *)self + 0x7D08, p);
    self->f81F0 = 0;
    VE *v = (VE *)((char *)self->vptr + 0x20);
    v->fn((char *)self + v->d, src);
}
