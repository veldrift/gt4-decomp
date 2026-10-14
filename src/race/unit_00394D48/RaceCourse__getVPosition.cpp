/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { unsigned short a; short b;
 short high() const { return b; }
 int valid() const { return high() >= 0; }
};
struct Vec { float x,y,z; int id; };
struct Search { char pad[0x2C]; Pair id; };
struct Course { int pad; void *data; };
extern "C" void *CourseData__getRunway(void *);
extern "C" int GT4Course__RunwayData__search(void *, Search *, Vec *);
extern "C" float GT4Course__RunwayData__getVCoord(void *, Vec *, Search *);
extern "C" float RaceCourse__getVPosition(Course *self, Vec *pos) {
    Pair id;
    Search search;
    Vec point;
    int invalid=-1;
    int n=pos->id;
    int hi=n >> 16;
    id.a=n;
    id.b=hi;
    if (!id.valid() || id.high() == 0) {
        Pair *sid = &search.id;
        Search *ps = &search;
        float x=pos->x;
        float y=pos->y+1000.0f;
        float z=pos->z;
        sid->a=invalid;
        point.x=x;
        point.y=y;
        point.z=z;
        sid->b=invalid;
        if (GT4Course__RunwayData__search(CourseData__getRunway(self->data), ps, &point)!=0) {
            id=*sid;
            pos->id=(id.b << 16) | id.a;
        } else {
            pos->id=invalid;
            return 0.0f;
        }
    }
    Search *ps = &search;
    *(Pair *)ps=id;
    return GT4Course__RunwayData__getVCoord(CourseData__getRunway(self->data), pos, ps);
}
