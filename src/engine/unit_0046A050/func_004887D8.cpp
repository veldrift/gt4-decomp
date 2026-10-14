/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { float x, y, z, w; };
extern "C" void func_00487830(float *out, const float *v, float angle) throw();
extern "C" void func_00488748(void *out, void *v, void *fb) throw();
extern "C" void func_0048D4C0(void *, V3 *, V3 *);
extern "C" float func_0059D2A0(float);

static inline float fmax_(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float fmin_(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float frsq(float a, float b) { float r; __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline float dot(const V3 *a, const V3 *b) {
 const float &x=b->x, &y=b->y, &z=b->z;
 float bx=x, ax=a->x;
 float by=y, ay=a->y;
 float bz=z, az=a->z;
 return ax*bx+ay*by+az*bz;
}
extern "C" void func_004887D8(float *out, V3 *a, V3 *b) {
    V3 sp;
    float ang;
    if (dot(a,b) + 1.0f > 0.0f) {
        func_0048D4C0(&sp, a, b);
        float len2 = sp.x * sp.x + sp.y * sp.y + sp.z * sp.z;
        float d = dot(a,b);
        float r = frsq(1.0f, len2);
        sp.x *= r;
        sp.y *= r;
        sp.z *= r;
        d = fmax_(d, -1.0f);
        d = fmin_(d, 1.0f);
        ang = 1.5707963f - func_0059D2A0(d);
    } else {
        V3 fb;
        V3 *fp = &fb;
        fp->x = 1.0f;
        fb.y = 0.0f;
        fb.z = 0.0f;
        func_00488748(&sp, b, fp);
        ang = 0x1.921fb4p+1f;
    }
    func_00487830(out, (float *)&sp, ang);
}
