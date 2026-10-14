/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *, unsigned, int, const char *);
struct Rep { unsigned len, cap, ref; bool selfish;
 static void operator delete(void *p, unsigned n) { func_00326798(p, n, 4, func_005C11A8()->name); }
 void release() { if (--ref == 0) operator delete(this, sizeof(Rep) + cap); }
 char *data() { return (char *)(this + 1); }
 char &operator[](unsigned s) { return data()[s]; }
};
struct Str;
extern "C" Str *func_005CB5A0(void *, unsigned, int);
struct Str { char *p; char pad[12];
 Rep *rep() const { return (Rep *)p - 1; }
 unsigned length() const { return rep()->len; }
 void unique() { if (rep()->ref > 1) func_005CB5A0(this, length(), 1); }
 void selfish() { unique(); rep()->selfish = true; }
 char &operator[](unsigned pos) { selfish(); return (*rep())[pos]; }
};
struct Handle { int p; char pad[12]; int get() const { return p; } };
struct Obj { int ref; char *vt; };
struct Items { char pad[20]; int *list; char pad2[8]; int count; };
struct Owner { char pad[44]; Items *items; };
struct VE { short delta,index; int (*fn)(void *, int); };
struct SE { short delta,index; void (*fn)(Str *, void *); };
extern "C" void func_00309360(void *, void *);
extern "C" void func_00309378(void *, int);
extern "C" void func_002ECDE0(void *);
extern "C" void func_002EC260(void *, int, void *);
extern "C" void func_00306E80(void *);
extern "C" void func_002EC370(void *, int);
extern "C" void func_003069F8(int, void *, void *);
extern "C" void func_003041B8(void *, int);
extern "C" void func_002EFBF0(void *);
extern "C" int func_005DB110(const char *, ...);
extern "C" int hArray__size(void *);
extern "C" void func_002ED5C0(void *, int);
extern "C" int func_00322060(void *);
extern "C" void func_00305DF8(int, void *, void *);
extern "C" void func_002EA590(void *, int);
extern char D_00840F68[], D_00840F58[], D_00840EB8[], D_0069E448[], D_0069E450[], D_0069E428[];
static inline void stringify(Str *s, Obj *o) {
 SE *e = (SE *)(o->vt + 0x18);
 e->fn(s, (char *)o + e->delta);
}
static inline const char *cstr(Str *s) {
 if (((Rep *)s->p - 1)->len == 0) return D_0069E428;
 s->p[((Rep *)s->p - 1)->len] = 0;
 return s->p;
}
static inline void release(Str *s) { ((Rep *)s->p - 1)->release(); }
extern "C" void mRequire__execute(void *unused, Owner *owner) {
 int h[4]; Str s; int ctx[4], result[4]; Handle work, list;
 unsigned i = 0;
 Items *it = owner->items;
 int idx = it->count - 1;
 it->count = idx;
 func_00309360(h, it->list + idx);
 stringify(&s, (Obj *)h[0]);
 for (; i < s.length(); i++) {
  if (s[i] == '\\') s[i] = '/';
 }
 func_002ECDE0(ctx);
 func_002EC260(result, ctx[0], &s);
 if (!result[0]) {
  int n = 0;
  func_00306E80(&work);
  func_002EC370(&list, ctx[0]);
  func_003069F8(list.get(), &work, D_00840F68);
  func_003041B8(&list, 2);
  func_002EFBF0(&list);
  func_003069F8(work.get(), &list, D_00840F58);
  func_005DB110(D_0069E448);
  int count = hArray__size((void *)list.get());
  for (; n < count;) {
   Str tmp;
   Obj *o = (Obj *)list.get();
   VE *e = (VE *)(o->vt + 0x70);
   int index = n++;
   Obj **p = (Obj **)e->fn((char *)o + e->delta, index);
   stringify(&tmp, *p);
   func_005DB110(D_0069E450, cstr(&tmp));
   release(&tmp);
  }
  func_002ED5C0(&list, 2);
  func_003041B8(&work, 2);
 }
 func_00305DF8(func_00322060(owner), result, D_00840EB8);
 func_003041B8(result, 2);
 func_002EA590(ctx, 2);
 release(&s);
 func_00309378(h, 2);
}
