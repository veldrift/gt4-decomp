/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Entry { u16 index,value; int spare; };
struct Obj { char pad[0x10]; Entry *entries; int spare14; unsigned char *ready; int spare1C; u16 *max; };
extern "C" void func_004C3A48(Obj *) throw();
extern "C" int func_004C3B80(Obj *, u16 *, u16 *, u16 *) throw();
extern "C" void func_004C3AD0(Obj *, u16, u16) throw();
extern "C" Entry *func_004C3C90(Obj *o, u16 value) {
 u16 a,b,c;
 c = value;
 if (*o->ready == 0) func_004C3A48(o);
 if (func_004C3B80(o, &a, &b, &c) == -1) return 0;
 u16 *p = o->max;
 if (*p < b) *p = b;
 Entry *e = o->entries + b;
 e->index = b;
 e->value = c;
 func_004C3AD0(o, a, b);
 return o->entries + (u16)(b + 1);
}
