struct Inner { char pad0[8]; int number; char padC[0x2060-0xC]; int value; };
struct Obj { char pad0[0x3C]; int state; int spare; Inner *inner; };
extern char D_006C41A0[];
extern char D_006C40D8[];
extern "C" int func_0053A878(char *) throw();
extern "C" int func_0053C2F0(Obj *, char *, char *) throw();
extern "C" int func_0053EF68(Obj *);
extern "C" int func_0053E8D0(Obj *arg0, int arg1, int arg2) {
 if (arg0 == 0) return 2;
 if (arg0->state != 0) return 0xD6DA;
 if (arg2 == 0) return 2;
 if (func_0053EF68(arg0) != 0) return 0x64;
 int r = func_0053C2F0(arg0, D_006C41A0, D_006C40D8);
 if (r == 0) {
  arg0->state = 5;
  func_0053A878((char *)arg0->inner + 0x10);
  Inner *p = arg0->inner;
  p->value = arg2;
  p->number = arg1;
 }
 return r;
}
