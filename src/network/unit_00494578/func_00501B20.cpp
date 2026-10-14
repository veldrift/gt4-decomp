/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00501A78(void *, const void *) throw();
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void func_0060F378(void *, int);
struct Guard {
 void *p;
 Guard(void *q) { p = q; func_00576100(q); }
 ~Guard() { func_00576140(p); }
};
extern "C" int func_00501B20(char *self, const void *data) {
 char *queue = self + 0x218;
 int result = func_00501A78(self, data);
 if (result) {
  int one = 1;
  char *entry = queue + (*(int *)queue << 7);
  int *header = (int *)(entry + 12);
  func_005A48D8(header, 0, 128);
  *header = *(int *)(self + 0xA8);
  func_005A4724(entry + 16, data, *(int *)(self + 0x9C) - 4);
  { Guard guard(self + 0x628); func_0060F378(queue, 1); }
  unsigned next = *(unsigned *)(self + 0xA8) + 1;
  if (next == 0) next = one;
  *(unsigned *)(self + 0xA8) = next;
  return 1;
 }
 return result;
}
