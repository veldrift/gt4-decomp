/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
struct Search { char pad[0x2c]; unsigned short a; short b; };
struct Owner { int pad; void *course; };
extern "C" void *CourseData__getRunway(void *);
extern "C" int GT4Course__RunwayData__search(void *, void *, const Vec *);
extern "C" int func_003FCB20(Owner *o, const Vec *p) {
    Search s;
    Vec v;
    unsigned short *h = &s.a;
    *h = -1;
    s.b = -1;
    v.x = p->x;
    v.y = p->y + 10.0f;
    v.z = p->z;
    if (GT4Course__RunwayData__search(CourseData__getRunway(o->course), &s, &v))
        return (s.b << 16) | *h;
    return -1;
}
