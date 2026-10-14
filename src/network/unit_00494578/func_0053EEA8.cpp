struct Pair { int a,b; };
struct Inner { char pad0[0xC]; int flag; char pad10[0x2078-0x10]; int value; };
struct Obj { char pad0[0x1C]; Pair pair; int number; char pad28[0x3C-0x28]; int state; int spare; Inner *inner; int spare48; int value; };
extern char D_0053DD38[];
extern "C" int func_0053E118(Obj *, int, char *) throw();
extern "C" int func_0053EF68(Obj *);
extern "C" int func_0053EEA8(Obj *o, Pair p, int n, int v, int x) {
 if (!o) return 2;
 if (o->state) return 0xD6DA;
 if (func_0053EF68(o)) return 0x64;
 int r = func_0053E118(o, 0x1000, D_0053DD38);
 if (r == 0) {
  o->number = n;
  Inner *q = o->inner;
  o->pair = p;
  q->flag = 1;
  q->value = v;
  o->value = x;
 }
 return r;
}
