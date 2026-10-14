/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xEE0]; int count; char padEE4[0x30C4-0xEE4]; int values[48]; char blocks[1][128]; };
extern "C" int func_004FA178(Obj *, int) throw();
extern "C" void func_00576100(Obj *);
extern "C" void func_00576140(Obj *);
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" int func_004FB050(Obj *o, int n, void *dst, unsigned int size) {
 if (n < 0 || n >= o->count) return 0;
 int i = func_004FA178(o, n);
 if (i == -1) return 0;
 func_00576100(o);
 func_005A4724(dst, (void *)(i * 128 + (int)o + 0x3184), size);
 int *p = (int *)(i * 4 + (int)o + 0x30C4);
 i = *p;
 *p = 0;
 func_00576140(o);
 return i;
}
