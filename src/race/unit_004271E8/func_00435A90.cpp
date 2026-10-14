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
extern "C" int func_0043E098(void *self, void *src);

static inline int write32(char *p, B32 *src) { *(B32 *)p = *src; return sizeof(B32); }
static inline int write28(char *p, B28 *src) { *(B28 *)p = *src; return sizeof(B28); }

extern "C" void func_00435A90(Self *self, Src *src) {
    char *p = (char *)src;
    for (int i = 0; i < 1000; i++) p += write32(p, &self->e[i]);
    p += write28(p, &self->tail);
    func_0043E098((char *)self + 0x7D08, p);
    VE *v = (VE *)((char *)self->vptr + 0x20);
    v->fn((char *)self + v->d, src);
}
