/* compiler: ee-gcc2.96-nosib */
struct Obj { int a,b; unsigned size; int c; void *data; int e; };
extern "C" int func_0052E120(Obj *);
extern "C" int func_00538B08(void **, unsigned long);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" int func_0052D448(Obj *o,unsigned size) {
 if(!o) return 2;
 if(size<9) return 2;
 if(size&3) return 2;
 func_005A48D8(o,0,24);
 void **p=&o->data;
 if(func_00538B08(p,size)) return 100;
 if(!*p) return 100;
 o->size=size;
 return func_0052E120(o);
}
