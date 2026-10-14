/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Inner { char pad[0xb0]; void *target; };
struct Obj { int a; Inner *inner; };
extern "C" float RaceCourse__getCourseLength(void *) throw();
extern "C" int func_003DE268(void *, int, int, float, float, int, float);
extern "C" int func_00396098(Obj *o, int a, int b, float x, int c, float y) {
    void *t = o->inner->target;
    return func_003DE268(t,a,b,x,y,c,RaceCourse__getCourseLength(o));
}
