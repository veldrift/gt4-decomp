/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
 char p0[0x3a4];
 float a,b,c,d;
 char p1[0x10];
 float e,f,g,h;
 char p2[0x80];
 float oa,ob,oc,oe,of,og;
 char p3[8];
 float od;
 char p4[8];
 float oh;
};
extern "C" float func_0045C928(float) throw() __attribute__((const));
extern "C" float func_0045C9B0(float) throw() __attribute__((const));
extern "C" void func_0045C9F8(Obj *o) {
 float b=o->b, c=o->c, e=o->e, f=o->f, g=o->g, a=o->a;
 o->oa=a; o->ob=b; o->oc=c; o->oe=e; o->of=f; o->og=g;
 o->od=func_0045C928(o->d);
 o->oh=func_0045C9B0(o->h);
}
