/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { short x, y; };
struct Obj {
 int zero;
 char pad4[0x6B0-4];
 int x6b0,x6b4,x6b8,x6bc;
 char pad6c0[0x708-0x6C0];
 float x708, x70c;
 Pair pairs[20];
 short x760, x762;
 int values[20];
 int x7b4, x7b8, x7bc, x7c0;
 char pad7c4[0x7DC-0x7C4];
 void *vt;
};
extern char HumanModel__vtable[];
extern "C" int func_003B08C8(void *) throw();
extern "C" int func_003B0830(void *) throw();
extern "C" void func_003B0ED8(void *);
extern "C" void HumanModel__structor_0(Obj *p) {
 p->vt = HumanModel__vtable;
 p->zero = 0;
 func_003B08C8((char *)p + 0x10);
 p->x6b0 = 0;
 p->x6b4 = 0;
 p->x6b8 = 0;
 p->x6bc = 1;
 func_003B0830((char *)p + 0x6C0);
 p->x7b4 = 0;
 short empty = -1;
 p->x708 = 0.5f;
 p->x70c = 0.25f;
 p->x7b8 = 0;
 p->x7bc = 0;
 p->x7c0 = 0;
 int *value = p->values;
 short *pair = &p->pairs[0].y;
 for (int i = 0; i < 20; ++i, pair += 2, ++value) {
  pair[-1] = empty;
  pair[0] = empty;
  *value = 0;
 }
 p->x760 = -1;
 p->x762 = -1;
 return func_003B0ED8(p);
}
