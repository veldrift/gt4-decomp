/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { unsigned short lo; short hi; };
struct Search { int a; float b; int c; unsigned char d; char padD[3]; unsigned char e; char pad11[3]; float f,g,h,i,j,k; Pair pair; };
struct Vec { float x,y,z; };
struct Vec4 { float x,y,z,w; };
struct Owner { int a; void *course; };
extern "C" void *CourseData__getRunway(void *);
extern "C" int GT4Course__RunwayData__search(void *,void *,const Vec *);
extern "C" void func_00395930(Owner *o,Vec *p,int *id,int *flag,Vec4 *out) {
 Search s;
 Vec v;
 Pair *pair = &s.pair;
 int minus = -1;
 pair->lo = minus;
 float z = p->z;
 v.x = p->x;
 v.z = z;
 v.y = p->y+1.0f;
 pair->hi = minus;
 if(GT4Course__RunwayData__search(CourseData__getRunway(o->course),&s,&v)) {
  out->x = s.h;
  out->y = s.i;
  out->z = s.j;
  out->w = s.k;
  *id = (pair->hi<<16)|pair->lo;
  *flag = *(int *)((char *)&s+0xc);
  return;
 }
 out->x = 0.0f;
 out->y = 1.0f;
 out->z = 0.0f;
 out->w = 0.0f;
 *id = minus;
 *flag = 0;
}
