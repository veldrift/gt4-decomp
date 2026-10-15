/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 index; s32 (*fn)(void *); };
struct VO { char pad[4]; VE *vtbl; };
struct H { s32 *p; int pad[3]; };
struct Stk { char pad[0x14]; s32 *arr; char pad2[8]; s32 count; };
struct Ctx { char pad[0x2C]; Stk *stk; };
extern "C" void func_002F3478(s32, void *, void *);
extern "C" void func_00307728(void *, s32);
extern "C" void func_00307D90(void *, void *, void *, void *);
extern "C" void func_00323B60(void *, s32);
extern "C" void func_00323D08(void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

static inline s32 *pop(Stk *s) {
    return &s->arr[--s->count];
}

static inline char *attr(char *s) { return s + 8; }

static inline s32 vcall(char *o, int off) {
    VE *e = (VE *)((char *)((VO *)o)->vtbl + off);
    return e->fn(o + e->delta);
}

extern "C" void mAttributePush__execute(char *self, Ctx *c) {
    H h0;
    H h1;
    H *ph0 = &h0;
    char *q = self;
    s32 *b = pop(c->stk);
    func_00323D08(ph0);
    func_002F3478(vcall((char *)*b, 0x50), &h0, attr(q));
    H *ph1 = &h1;
    func_00307D90(ph1, attr(q), b, &h0);
    Stk *s = c->stk;
    s32 *p = s->arr + s->count;
    if (p != (s32 *)ph1) {
        s32 newVal = *(s32 *)ph1;
        if (newVal != 0) func_003285A8(newVal);
        s32 oldVal = *p;
        if (oldVal != 0) func_003285F8(oldVal);
        *p = newVal;
    }
    s->count = s->count + 1;
    func_00307728(ph1, 2);
    func_00323B60(&h0, 2);
}
