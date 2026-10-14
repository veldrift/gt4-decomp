/* compiler: ee-gcc2.96-no-strict-aliasing */
struct P8 { int a,b; };
struct Sub { P8 a,b; int pad[7]; char *ptr; int tail[5]; };
struct Rw { char pad[0x84]; char *tab; };
struct In { int pad; void *inner; };
struct Obj { int header[2]; Sub e[8]; char pad[0x488-0x228]; In *in; };
extern "C" Rw *CourseData__getRunway(void *);
extern "C" char *func_0045CF18(Obj *o, char *h) {
 int flag=((int *)h)[0];
 int size=((int *)h)[1];
 h+=8;
 char *end=h+size;
 if(flag==0) {
  for(int i=0;i<8;i++) {
   P8 t1=o->e[i].a;
   P8 t2=o->e[i].b;
   o->e[i]=((Sub *)h)[i];
   Rw *r=CourseData__getRunway(o->in->inner);
   o->e[i].ptr=r->tab+(int)((Sub *)h)[i].ptr*16;
   o->e[i].a=t1;
   o->e[i].b=t2;
  }
  end=h+0x220;
 }
 return end;
}
