/* compiler: ee-gcc2.96-no-strict-aliasing */
struct H { int a[5]; };
struct Big { char a[0x124]; };
struct Small { char a[32]; };
extern "C" void SePlayer__Stop(Small *,int);
extern "C" void func_00559378(int);
struct A { H h; int a[2]; Big b[2]; Small c[2]; };
struct B { H h; int k; Big b; };
struct C { H h; Small a[3]; int b[3]; };
struct E { H h; Small a[11]; int b[11]; };
struct Obj { H h; A a; B b; C c; E e[4]; char pad[0x44]; int last; };
extern "C" void RaceCarSound__playStop(Obj *o,int how) {
 if(o->last) {
  o->last=0;
  for(int i=0;i<2;i++) func_00559378(o->a.a[i]);
  for(int i=0;i<2;i++) SePlayer__Stop(&o->a.c[i],how);
  func_00559378(o->b.k);
  for(int i=0;i<3;i++) SePlayer__Stop(&o->c.a[i],how);
  for(int i=0;i<4;i++) {
   for(int j=0;j<11;j++) SePlayer__Stop(&o->e[i].a[j],how);
  }
 }
}
