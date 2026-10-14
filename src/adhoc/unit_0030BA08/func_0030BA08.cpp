/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct Entry { short delta; short pad; void (*fn)(); };
struct Obj { int word; Entry *vt; };
struct Handle { Obj *p; char pad[12]; };
extern char D_0083F6E0[];
extern "C" void func_00309348(Handle*,int*) throw();
extern "C" void func_00309360(Handle*,Handle*) throw();
extern "C" void func_00309378(Handle*,int) throw();
extern "C" void func_0030BB18(Handle*);
extern "C" void func_003069F8(void*,Handle*,void*);
extern "C" Handle *func_0030BA08(Handle*self,Obj*arg){
 Handle a;
 Handle b;
 int zero[4];
 zero[0]=0;
 func_00309348(&a,zero);
 func_0030BB18(&b);
 Entry*e=&arg->vt[10];
 void*r=((void*(*)(void*))e->fn)((char*)arg+e->delta);
 func_003069F8(r,&b,D_0083F6E0);
 Handle*pb=&b;
 Obj*p=pb->p;
 if(p){
  Entry*e=&p->vt[21];
  ((void(*)(void*,Handle*,int,int))e->fn)((char*)p+e->delta,&a,0,0);
 }
 Obj*q=a.p;
 if(q){
  Entry*e=&q->vt[9];
  ((void(*)(void*,Obj*))e->fn)((char*)q+e->delta,arg);
 }
 func_00309360(self,&a);
 func_00309378(&b,2);
 func_00309378(&a,2);
 return self;
}
