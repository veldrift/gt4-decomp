/* compiler: ee-gcc2.96-no-strict-aliasing */
#define absval(f) ((f) >= 0.0f ? (f) : -(f))
struct V4 {
    float x,y,z,w;
    V4() {}
    V4(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
    V4 &operator=(const V4 &o) {
        if(this != &o) { x=o.x; y=o.y; z=o.z; w=o.w; }
        return *this;
    }
    int operator==(const V4 &o) const { return x==o.x && y==o.y && z==o.z && w==o.w; }
    V4 operator-(const V4 &o) const { return V4(x-o.x,y-o.y,z-o.z,w-o.w); }
    void linear(const V4 &dest,const V4 &delta,float r) {
        if (*this == dest) return;
        if (absval(dest.x-x)<=absval(delta.x*r) && absval(dest.y-y)<=absval(delta.y*r) && absval(dest.z-z)<=absval(delta.z*r) && absval(dest.w-w)<=absval(delta.w*r)) {
            *this=dest;
        } else {
            x += delta.x*r;
            y += delta.y*r;
        }
    }
    void smooth(const V4 &dest,float r) {
        float a=x,b=y,c=z,d=w;
        x=a+(dest.x-a)*r;
        y=b+(dest.y-b)*r;
        z=c+(dest.z-c)*r;
        w=d+(dest.w-d)*r;
    }
};
struct VT { short delta, pad; void (*fn)(void *); };
struct M {
    int unk; VT *vt; char pad[0xC]; void *widget;
    V4 a,b; float f38; V4 c; float f4c,ratio;
    int flip,repeat,linear,back;
};
extern "C" void mMoveActor__doFlip(M *) throw();
extern "C" V4 mWidget__setPackChanged(const V4 &,float);
extern "C" void func_0025B538(void *,float,float,float,float);
static inline void approach(float &v,const float &dest,float step) {
    if(dest>v) { v+=step; if(v>dest) v=dest; }
    else if(v>dest) { v-=step; if(v<dest) v=dest; }
}
static inline void finish(M *p) {
    VT *v=(VT *)((char *)p->vt+0x198);
    v->fn((char *)p+v->delta);
}
static inline void apply(M *p,const V4 &v) { func_0025B538(p->widget,v.x,v.y,v.z,v.w); }
extern "C" void mMoveActor__update(M *p) {
    if (p->flip) {
        if (p->linear) p->c.linear(p->b,p->b-p->a,p->ratio);
        else p->c.smooth(p->b,p->ratio);
        approach(p->f4c,p->f38,p->ratio);
        if (p->repeat && p->c==p->b) {
            if (p->back) mMoveActor__doFlip(p); else finish(p);
        }
    } else {
        if (p->linear) p->c.linear(p->a,p->a-p->b,p->ratio);
        else p->c.smooth(p->a,p->ratio);
        approach(p->f4c,1.0f,p->ratio);
        if (p->repeat && p->c==p->a) {
            if (p->back) mMoveActor__doFlip(p); else finish(p);
        }
    }
    if(p->f4c==1.0f) func_0025B538(p->widget,p->c.x,p->c.y,p->c.z,p->c.w);
    else apply(p,mWidget__setPackChanged(p->c,p->f4c));
}
