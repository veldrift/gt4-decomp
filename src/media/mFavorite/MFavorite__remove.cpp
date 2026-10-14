/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; int pad[3]; };
struct Info { const char *name; };
struct VEntry { short delta, index; void (*fn)(Str *, void *); };
struct Obj { int pad; char *vtbl; };
extern char D_00693BE8[];
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" int func_00447BB8(const char *);
extern "C" int func_00447C78(const char *);
extern "C" void func_001BFEA8(void *, void *) throw();
extern "C" void func_001BFE50(void *, int) throw();
extern "C" void func_00430460(int, int);
static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_00693BE8;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}
extern "C" void MFavorite__remove(void *unused, void *arg1, int n, Obj **args) {
 if (n > 0) {
  Str s;
  Obj *o = *args;
  VEntry *e = (VEntry *)(o->vtbl + 0x18);
  e->fn(&s, (char *)o + e->delta);
  const char *name = c_str(&s);
  release(&s);
  int r = func_00447BB8(name);
  if (r == -1) r = func_00447C78(name);
  func_001BFEA8(&s, arg1);
  func_00430460(*(int *)(s.p + 0x10), r);
  func_001BFE50(&s, 2);
 }
}
