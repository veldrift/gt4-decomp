/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Handle { void *p; char pad[12]; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *, unsigned, unsigned, const char *, unsigned);
extern "C" Str *func_005CE388(Str *, unsigned, unsigned, Str *, unsigned, unsigned);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_00270F20(Handle *, void *) throw();
extern "C" void func_00270EC8(Handle *, int) throw();
extern "C" int func_00271D48(void *, char *, int, int *, int *);
extern "C" void func_002EFBF0(Handle *);
extern "C" void func_002FE278(Handle *, int);
extern "C" Handle *func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_002FC870(Handle *, int);
extern "C" void func_00314B20(Handle *, Str *);
extern "C" void func_00312318(Handle *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_002ED5C0(Handle *, int);
static inline void init(Str *s) {
 Rep *r = &D_00659FA8; char *d;
 if (r->sel) d = func_005C2560(r);
 else { d = (char *)(r+1); r->ref++; }
 s->p = d;
}
static inline void fini(Str *s) {
 Rep *r = (Rep *)(s->p - 16);
 if (--r->ref == 0) { int cap = r->cap + 16; func_00326798(r, cap, 4, func_005C11A8()->name); }
}
struct Reader : Handle {
 Reader(void *p) { func_00270F20(this,p); }
 void *get() { return p; }
 ~Reader() { func_00270EC8(this,2); }
};
struct TempStr : Str {
 TempStr(const char *b, int n) { Rep *r = &D_00659FA8; int d; if (r->sel) d = (int)func_005C2560(r); else { d = (int)(r+1); r->ref = r->ref + 1; } *(int *)&p = d; func_005C2630(this,0,-1,b,n); }
 ~TempStr() { fini(this); }
};
static inline void append(Str *s, const Str &t) { func_005CE388(s, ((Rep *)(s->p-16))->len, 0, (Str *)&t, 0, -1); }
extern "C" void MComm__receive(Handle *out, void *arg1) {
 int done = 0;
 Str s;
 union { char buf[256]; struct { Handle ret, value; } h; } u;
 int count;
 int ok = 1;
 Str *ps = &s;
 { Rep *r = &D_00659FA8; char *d; if (r->sel) d = func_005C2560(r); else { d = (char *)(r+1); r->ref++; } ps->p = d; }
 if (done == 0) {
   do {
   count = 0;
   ok = func_00271D48(Reader(arg1).get(), u.buf, 256, &count, &done);
   if (!ok) break;
   int n = count;
   if (n) {
      append(ps, TempStr(u.buf, n));
   }
   } while (done == 0);
 }
 Handle result;
 Handle *ph = &result;
 func_002EFBF0(ph);
 if (ok == 0) {
   void *obj = ph->p;
   func_002FE278(&u.h.value, 0);
   func_002EEEB0(&u.h.ret, obj, &u.h.value);
   func_00309378(&u.h.ret, 2);
   func_002FC870(&u.h.value, 2);
 } else {
   void *obj = ph->p;
   func_002FE278(&u.h.value, 1);
   func_002EEEB0(&u.h.ret, obj, &u.h.value);
   func_00309378(&u.h.ret, 2);
   func_002FC870(&u.h.value, 2);
   obj = ph->p;
   func_00314B20(&u.h.value, ps);
   func_002EEEB0(&u.h.ret, obj, &u.h.value);
   func_00309378(&u.h.ret, 2);
   func_00312318(&u.h.value, 2);
 }
 if (out != ph) {
   void *p = ph->p;
   if (p) func_003285A8(p);
   if (out->p) func_003285F8(out->p);
   out->p = p;
 }
 func_002ED5C0(ph, 2);
 fini(ps);
}
