/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef long s64;
struct VEntry { short delta; short index; int (*fn)(void *, int *); };
struct Obj { char pad[0x64]; VEntry *vt; int pad68; char *owner; };
extern "C" char *func_00445450(s64 *);
extern "C" s64 func_004454C0(s64 *);
extern "C" int func_00447CA0(s64, char *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" char *func_005A609C(char *, const char *);
struct State { unsigned char n; volatile int mode; };
static inline bool modeOK(State *s) { return s->mode >= 3; }
static inline int getMode(Obj *self, State *s) { VEntry *e = self->vt + 0x60; return e->fn((char *)self + e->delta, (int *)s); }
extern "C" void RaceBase__createThumbnailBasic(Obj *self, char *out) {
    State sp;
    func_005A48D8(out, 0, 0xe8);
    char *owner = self->owner;
    s64 *car = (s64 *)**(char ***)(*(char **)(owner + 0x60) + 8);
    car += 4;
    *(s64 *)(out + 0) = func_004454C0(car);
    *(s64 *)(out + 8) = *(s64 *)(owner + 0x78);
    out[0x50] = 0;
    out[0x90] = 0;
    out[0x10] = 0;
    int mode = getMode(self, &sp);
    *(int *)(out + 0xe0) = 0;
    sp.mode = mode;
    out[0xd9] = sp.n;
    out[0xd8] = *(unsigned char *)&sp.mode;
    *(bool *)(out + 0xe4) = modeOK(&sp) && mode < 11;
    char *name = func_00445450(car);
    if (name) func_005A609C(out + 0x90, name);
    func_00447CA0(*(s64 *)(owner + 0x78), out + 0x50);
}
