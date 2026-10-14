/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xCBDE]; unsigned char mode; char pad2[0x10140-0xCBDF]; char *vt; };
struct Entry { short delta,index; };
struct VI { short delta,index; int (*fn)(void *); };
struct VF { short delta,index; float (*fn)(void *, int); };
extern "C" float DynamicsConductor__GetCourseLength(void *) throw();
extern "C" int func_0046ADE8(void *, int, int *, float *, float *, float *, float *, float, int);
static inline int count(Obj *o) {
    VI *v=(VI *)(o->vt+0x150);
    return v->fn((char*)o+v->delta);
}
static inline float limit(Obj *o, int i) {
    VF *v=(VF *)(o->vt+0x158);
    return v->fn((char*)o+v->delta,i);
}
extern "C" int func_0034C5E0(Obj *o, int *id, float *x, float *y, float *z, float *angle, int distance, int kind) {
    float d = (float)distance;
    float end = DynamicsConductor__GetCourseLength(o)-20.0f;
    float lower = -end;
    if (d < lower) d = lower;
    int clamp = o->mode == 1;
    if (clamp) end = limit(o,count(o)-2)-20.0f;
    if (end < d) d = end;
    int minus = -1;
    int r = func_0046ADE8((char*)o+0xDA50, (kind ^ minus) ? kind : 6, id,x,y,z,angle,d,clamp);
    if (r) {
        r = 1;
        if (distance < 0) r = minus;
    }
    return r;
}
