/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta,index; int (*fn)(void *); };
struct Obj { VEntry *vtbl; char pad[0x26c-4]; unsigned char flag; };
extern "C" int func_0037BA90(Obj *o) {
 VEntry *e=o->vtbl+23;
 int r=e->fn((char *)o+e->delta);
 int result=2;
 switch(r) {
 case 1: break;
 case 20: break;
 case 0:
 case 25: result=0; break;
 default: result=o->flag!=0; break;
 }
 return result;
}
