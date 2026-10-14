/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta,index; int (*fn)(void *); };
struct Other { char pad[0x18]; int car; };
struct Obj { void *vt; char pad4[12]; float x,y,z; char pad1c[0x170]; Other *other; char pad190[0xdb]; unsigned char a,b; };
extern "C" int Automobile__getDrawMode(int) throw();
extern "C" int func_003FDD60(Other *,float *,float *);
extern "C" int func_0037BB68(Obj *p,int unused,Other *o) {
 float v[4];
 int r=1;
 if(o==p->other) {
  Entry *e=(Entry *)((char *)p->vt+0xb8);
  if(e->fn((char *)p+e->delta)!=6) return p->b;
  return p->a^1;
 }
 if(Automobile__getDrawMode(o->car)==2) {
  v[0]=p->x; v[1]=p->y; v[2]=p->z;
  r=func_003FDD60(o,v,0)^1;
 }
 return r;
}
