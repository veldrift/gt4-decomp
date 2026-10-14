/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Stream {
    int f0, f4, f8, fC, f10, f14;
    char pad18[0x20];
    int f38, f3C, f40;
    char pad44[12];
};
struct Info { char pad0[0x16]; unsigned short kind, count; char pad1[0x1e]; char *boxes; };
struct Obj { char pad[0x2c]; Info *tbl[1]; };
extern "C" int func_004552E8(Info *,int);
extern "C" int func_00494F80(Stream *,int,int);
extern "C" int func_00494FC8(Stream *);
extern "C" float *func_00495560(Stream *);
extern "C" void func_004550B0(char *,float *,float *);
static inline char *more(Stream *s) { return s->f40 == 0 ? &s->pad18[16] : 0; }
static inline float fsqrt(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct Vec { float v[4]; float &operator[](int j) { return v[j]; } };
extern "C" void func_00458AB8(Obj *o, int idx, float *out, float a, float b, float c) {
    Vec mins;
    Vec maxs;
    Info *info = o->tbl[idx / 2];
    if (!info) return;
    float start;
    float factor = 1.0f / (b - c);
    float end = out[1];
    start = out[0];
    int n = info->count;
    float range = end - start;
    a *= factor;
    b *= factor;
    c *= factor;
    if (range == 0.0f) return;
    float scaleR = c / range;
    float low = b - c;
    float scaleX = a / out[2];
    for (int j=0; j<3; j++) mins[j] = maxs[j] = 0.0f;
    for (int i = 0; i < n; i++) {
        Stream it;
        func_00494F80(&it,func_004552E8(info,i),1);
        while (more(&it)) {
            float *p = func_00495560(&it);
            float y = p[1];
            float z = p[2];
            float radius = fsqrt(y*y + z*z);
            p[0] *= scaleX;
            float scale = ((radius - start) * scaleR + low) / radius;
            p[1] = y * scale;
            p[2] = z * scale;
            for (int j=0; j<3; j++) {
                if(p[j]<mins[j]) mins[j]=p[j];
                if(maxs[j]<p[j]) maxs[j]=p[j];
            }
            func_00494FC8(&it);
        }
    }
    out[0] = low;
    out[1] = b;
    out[2] = a;
    int kind = info->kind;
    if (kind >= 2) {
        func_004550B0(info->boxes,mins.v,maxs.v);
        func_004550B0(info->boxes + 0x28,mins.v,maxs.v);
    }
}
