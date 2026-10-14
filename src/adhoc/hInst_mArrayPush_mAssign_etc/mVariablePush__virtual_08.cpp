/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEntry { short delta, index; int (*fn)(void *); };
struct Obj { int ref; VEntry *vt; };
struct Vec { int x; s32 *begin; s32 *end; };
struct Items { int x; s32 *vars; char pad[12]; s32 *list; char pad2[8]; int count; };
struct Rhs { char pad[16]; Vec vec; };
struct Owner { char pad[36]; Rhs *rhs; int x; Items *items; };
struct Self { char pad[8]; Vec vec; int x; int idx; };
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_0030F628(s32 *, void *, int);
extern "C" int func_0030F648(void *);
extern "C" void func_0030BB18(void *);
extern "C" int func_00301828(void *, void *, void *);
extern "C" void func_00301228(void *, int);
extern "C" void func_00309378(void *, int);
extern "C" void func_00323D08(void *);
extern "C" void func_00321E38(void *, void *, void *);
extern "C" void func_002F3478(void *, void *, void *);
extern "C" int func_00307D90(void *, void *, void *, void *);
extern "C" void func_00307728(void *, int);
extern "C" void func_00323B60(void *, int);
static inline int vcall(s32 p, int off) {
 Obj *o = (Obj *)p;
 VEntry *e = (VEntry *)((char *)o->vt + off);
 return e->fn((char *)o + e->delta);
}
static inline int vcallref(s32 *p, int off) { return vcall(*p, off); }
static inline void assign(s32 *dst, s32 *src) {
 if (dst != src) {
  s32 n = *src;
  if (n) func_003285A8(n);
  s32 old = *dst;
  if (old) func_003285F8(old);
  *dst = n;
 }
}
static inline void push(Items *it, s32 *src) {
 s32 *dst = it->list + it->count;
 assign(dst, src);
 it->count = it->count + 1;
}
extern "C" void mVariablePush__virtual_08(Self *self, Owner *owner) {
 struct Frame { s32 common[12]; s32 a[4], b[4], c[4], d[4], e[4], f[4]; } sp;
 s32 *slot = owner->items->vars + self->idx;
 if (*slot && vcall(*slot, 0x98)) {
  push(owner->items, slot);
  return;
 }
 Vec *vec = &self->vec;
 if ((unsigned)(vec->end - vec->begin) < 2) {
  int idx = self->idx;
  Items *it = owner->items;
  func_0030F628(sp.a, vec, 0);
  func_0030BB18(sp.b);
  func_00301828(sp.common, sp.a, sp.b);
  s32 *v_vars = it->vars;
  s32 *dst = v_vars + idx;
  assign(dst, sp.common);
  push(owner->items, dst);
  func_00301228(sp.common, 2);
  func_00309378(sp.b, 2);
  return;
 }
 func_00323D08(sp.common);
 func_00321E38(owner, sp.common, vec);
 func_0030BB18(sp.c);
 if (vcall(sp.common[0], 0x58)) {
  Vec *v = &owner->rhs->vec;
  s32 *src = owner->items->vars + (((int)v->end - (int)v->begin) >> 2);
  assign(sp.c, src);
  if (func_0030F648(vec) == 1) {
   void *p = (void *)vcallref(sp.c, 0x50);
   func_0030F628(sp.d, vec, 0);
   func_002F3478(p, sp.common, sp.d);
  }
 }
 int idx = self->idx;
 Items *it = owner->items;
 func_0030F628(sp.f, vec, 0);
 func_00307D90(sp.e, sp.f, sp.c, sp.common);
 s32 *v_vars2 = it->vars;
 s32 *dst = v_vars2 + idx;
 assign(dst, sp.e);
 push(owner->items, dst);
 func_00307728(sp.e, 2);
 func_00309378(sp.c, 2);
 func_00323B60(sp.common, 2);
}
