/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
struct Point { Vec pos; char pad[0x24]; signed char flag; };
struct Owner { int a; void *course; };
struct Search { char pad[0x2c]; short a,b; };
extern "C" void func_003956F8(void *, void *) throw();
extern "C" void *CourseData__getRunway(void *);
extern "C" int GT4Course__RunwayData__search(void *, void *, const Vec *);
extern "C" void func_00395760(Owner *o, Point *p) {
    Search s;
    Vec v;
    s.a = -1;
    s.b = -1;
    v.x = p->pos.x;
    v.z = p->pos.z;
    v.y = p->pos.y + 5.0f;
    if (GT4Course__RunwayData__search(CourseData__getRunway(o->course), &s, &v)) {
        p->flag = 0;
        func_003956F8(p, &s);
        return;
    }
    p->flag = 1;
}
