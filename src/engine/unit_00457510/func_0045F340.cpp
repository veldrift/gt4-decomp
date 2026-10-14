/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,o) (*(float *)((p)+(o)))
#define I(p,o) (*(int *)((p)+(o)))
#define P(p,o) (*(char **)((p)+(o)))
struct Vec { float x,y; float spare[2]; };
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" float func_0045F5F8(char *, Vec *, float *, float *);
extern "C" void func_0045F928(char *, float *, float *);
extern "C" void func_00350530(char *, int, int, float);
static inline float cross(char *pos, Vec *v) { return F(pos,0) * v->y - F(pos,4) * v->x; }
extern "C" void func_0045F340(char *p) {
    Vec impulse;
    float m1[4];
    float m2[4];
    Vec local1;
    Vec local2;
    int ix = I(p,0x40c);
    int iy = I(p,0x410);
    char *q = P(p,0x4a8) + ix * 0x4f0;
    char *r = q + iy * 0x44 + 8;
    m1[0] = func_0057D1F0(F(p,0x39c));
    float c1 = func_0057D2B8(F(p,0x39c));
    m1[2] = c1;
    m1[3] = m1[0];
    m1[1] = -c1;
    m2[0] = func_0057D1F0(F(q,0x39c));
    float c2 = func_0057D2B8(F(q,0x39c));
    float n2 = -c2;
    float d2 = m2[0];
    m2[2] = c2;
    m2[1] = n2;
    m2[3] = d2;
    float *a = m1, *b = m2;
    float t = func_0045F5F8(p, &impulse, a, b);
    float amount = (t < 0.0f ? -t : t) / 15000.0f;
    F(p,0x448) += amount;
    F(q,0x448) += amount;
    func_0045F928(p,a,b);
    I(r,0x20) |= 2;
    I(r,0x3c) = I(p,0x44c);
    I(r,0x40) = I(p,0x408);
    char *pos = p + 0x414;
    Vec *la = &local1, *lb = &local2;
    float mass1 = F(p,0);
    F(p,0x3c4) += impulse.x * mass1;
    F(p,0x3c8) += impulse.y * mass1;
    la->x = a[0] * impulse.x + m1[2] * impulse.y;
    la->y = m1[1] * impulse.x + m1[3] * impulse.y;
    F(p,0x3d0) += cross(pos,la) * F(p,4);
    float mass2 = F(q,0);
    F(q,0x3c4) -= impulse.x * mass2;
    F(q,0x3c8) -= impulse.y * mass2;
    lb->x = b[0] * impulse.x + m2[2] * impulse.y;
    lb->y = m2[1] * impulse.x + m2[3] * impulse.y;
    F(q,0x3d0) -= (F(r,0) * lb->y - F(r,4) * lb->x) * F(q,4);
    func_00350530(P(p,0x450),1,I(p,0x408)+8,amount);
    func_00350530(P(q,0x450),1,I(p,0x410),amount);
}
