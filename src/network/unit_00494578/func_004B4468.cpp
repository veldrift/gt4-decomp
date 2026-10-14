/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int malloc(int) throw();
extern "C" int func_004B4598(void *);
struct Obj { char *volatile mem; int two,b,n; int pad; char *start,*volatile head; };
inline char *take(char **p,int n) { char *r=*p; *p+=n; return r; }
extern "C" int func_004B4468(char *p, int n) {
 int two=n*2,a=n*4,b=a+two,size=a+(a+b)*2+256;
 Obj *o=(Obj *)p;
 o->n=n; o->two=two; o->b=b;
 char *mem=(char *)malloc(size);
 char *cur=mem+256;
 (void)(o->mem=mem);
 o->start=mem;
 (void)(o->head=take(&cur,a));
 char *x=p+8,*y=p+12;
 for(int off=32,i=0;i<2;i++,off+=0x41c) {
  *(char **)(x+off)=cur;
  cur+=a;
  *(char **)(y+off)=cur;
  cur+=b;
 }
 func_004B4598(p);
 return size;
}
