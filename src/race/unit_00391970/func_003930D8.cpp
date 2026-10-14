/* compiler: ee-gcc2.96-no-strict-aliasing */
struct H { int a[5]; };
struct Big { char a[0x124]; };
struct Small { char a[32]; };
extern "C" int func_003919A8(Big *, const Big *) throw();
extern "C" void *func_00462CC0(Small *, const Small *);
struct A { H h; int a[2]; Big b[2]; Small c[2]; };
struct B { H h; int k; Big b; };
struct C { H h; Small a[3]; int b[3]; };
struct E { H h; Small a[11]; int b[11]; };
struct Obj { H h; A a; B b; C c; E e[4]; char pad[0x44]; int last; };
static inline void copyInts(int *d,const int *s,int n) {
 int k=n-1;
 do { *d++=*s++; k--; } while(k!=-1);
}
static inline void copyA(A *d,const A *s) {
 d->h=s->h;
 copyInts(d->a,s->a,2);
 Big *bd=d->b; int k=1; const Big *bs=s->b;
 do { func_003919A8(bd++,bs++); k--; } while(k!=-1);
 Small *cd=d->c; const Small *cs=s->c; k=1;
 do { func_00462CC0(cd++,cs++); k--; } while(k!=-1);
}
static inline void copyB(B *d,const B *s) {
 d->h=s->h; d->k=s->k;
 func_003919A8(&d->b,&s->b);
}
static inline void copyC(C *d,const C *s) {
 d->h=s->h;
 Small *ad=d->a; int k=2; const Small *as=s->a;
 do { func_00462CC0(ad++,as++); k--; } while(k!=-1);
 copyInts(d->b,s->b,3);
}
static inline void copyE(E *d,const E *s) {
 d->h=s->h;
 Small *ad=d->a; const Small *as=s->a; int k=10;
 do { func_00462CC0(ad++,as++); k--; } while(k!=-1);
 copyInts(d->b,s->b,11);
}
extern "C" Obj *func_003930D8(Obj *d,const Obj *s) {
 int tmp[2];
 int old=d->b.k;
 char *base=(char *)d+8;
 for(int i=0;i<2;i++) tmp[i]=d->a.a[i];
 copyA(&d->a,&s->a);
 copyB(&d->b,&s->b);
 copyC(&d->c,&s->c);
 int j=0; int off=0;
 for(;j<4;j++,off+=0x1a0) copyE((E *)((char *)d+off+0x474),(const E *)((char *)s+off+0x474));
 d->last=s->last;
 d->h=s->h;
 for(int i=0;i<2;i++) ((int *)(base+0x20))[i]=tmp[i];
 d->b.k=old;
 return d;
}
