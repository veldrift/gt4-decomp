/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Info { const char *name; };
struct Holder { char pad[4]; float *out; };
extern Rep D_00659FA8;
extern char D_006972B0[], D_006972B8[], D_006972C0[];
extern "C" int func_0020EEA0(void *, Str *);
extern "C" void func_0020FC58(void *, int);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" int func_0057F260(const char *) throw();
extern "C" double func_005A2F70(const char *);
extern "C" int func_005A2F88(const char *) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" Info *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" int func_005CD320(void *, const char *, unsigned int, unsigned int);
static inline int clamp(int x) { if (x < 0) x = 0; if (x >= 256) x = 255; return x; }
extern "C" void MColorReader__virtual_03(Holder *self, void *reader, void *tag) {
 Str s;
 int v[4];
 float f[4];
 if (func_005CD320(tag, D_006972B0, 0, func_0057F260(D_006972B0)) == 0) {
  Rep *r = &D_00659FA8;
  char *d;
  int i, t;
  if (r->sel != 0) d = func_005C2560(r);
  else { d = (char *)(r + 1); r->ref++; }
  s.p = d;
  func_0020EEA0(reader, &s);
  func_005A48D8(v, 0, 16);
  v[3] = 255;
  i = 0;
  while ((t = func_0020EEA0(reader, &s)) != -1 && t != 0x7d) {
   const char *c = D_006972B8;
   if (*(int *)(s.p - 16) != 0) {
    s.p[*(int *)(s.p - 16)] = 0;
    c = s.p;
   }
   v[i++] = func_005A2F88(c);
   if (i >= 4) break;
  }
  if (t != 0x7d) func_0020FC58(reader, 1);
  self->out[0] = (float)clamp(v[0]) / 255.0f;
  self->out[1] = (float)clamp(v[1]) / 255.0f;
  self->out[2] = (float)clamp(v[2]) / 255.0f;
  self->out[3] = (float)clamp(v[3]) / 255.0f;
  Rep *q = (Rep *)(s.p - 16);
  if (--q->ref == 0) { int cap = q->cap + 16; func_00326798(q, cap, 4, func_005C11A8()->name); }
 } else if (func_005CD320(tag, D_006972C0, 0, func_0057F260(D_006972C0)) == 0) {
  Rep *r = &D_00659FA8;
  char *d;
  int i, t;
  if (r->sel != 0) d = func_005C2560(r);
  else { d = (char *)(r + 1); r->ref++; }
  s.p = d;
  func_0020EEA0(reader, &s);
  func_005A48D8(f, 0, 16);
  f[3] = 1.0f;
  i = 0;
  while ((t = func_0020EEA0(reader, &s)) != -1 && t != 0x7d) {
   const char *c = D_006972B8;
   if (*(int *)(s.p - 16) != 0) {
    s.p[*(int *)(s.p - 16)] = 0;
    c = s.p;
   }
   f[i++] = (float)func_005A2F70(c);
   if (i >= 4) break;
  }
  if (t != 0x7d) func_0020FC58(reader, 1);
  self->out[0] = f[0];
  self->out[1] = f[1];
  self->out[2] = f[2];
  self->out[3] = f[3];
  Rep *q = (Rep *)(s.p - 16);
  if (--q->ref == 0) { int cap = q->cap + 16; func_00326798(q, cap, 4, func_005C11A8()->name); }
 }
}
