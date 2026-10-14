struct Vec { float x,y,z; };
struct Obj { char pad[0x6c]; float angle; };
struct Input { char pad[0x30]; float width,height; };
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" void func_00371530(Obj *, Vec *, Vec *) throw();
inline void set(Vec *v, float x, float y, float z) { v->x=x; v->y=y; v->z=z; }
extern "C" void func_003716A8(Obj *o, Input *in) {
    Vec a,b;
    Vec *pb = &b;
    float rad = o->angle * 0x1.921fb4p+1f / 180.0f;
    float h = in->height * 0x1.111110p-3f;
    float w = in->width * 0x1.111110p-3f;
    float s = func_0057D1F0(rad);
    float c = func_0057D2B8(rad);
    set(&a, s*w, 0.0f, c*w);
    set(pb, -c*h, 0.0f, s*h);
    func_00371530(o, &a, pb);
}
