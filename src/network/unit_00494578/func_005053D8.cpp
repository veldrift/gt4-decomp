extern short D_0064A164;
extern char D_006C1140[];
extern "C" int func_005049C8(void) throw();
extern "C" int func_0052FA88(void);
extern "C" void func_0057D9C0(const char *, ...);
extern "C" int func_005053D8(void) {
 if (D_0064A164 != 1) return -12;
 int r=func_005049C8();
 if (r != 0) return r;
 int e=func_0052FA88();
 if (e == 0) return e;
 func_0057D9C0(D_006C1140,e);
 return -8;
}
