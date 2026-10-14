/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cam { int f0; char p4[0x34 - 4]; void *f34; };
struct Self {
    char p0[8];
    float f8, fC, f10, f14, f18, f1C;
    char p20[0x48 - 0x20];
    float f48;
    Cam *f4C;
};
struct Glob { char p[0x18]; char *f18; };
extern Glob *D_00621B44;
extern char D_006A44F0[];
extern "C" void func_0040AD10(float *, float, float, float) throw();
extern "C" int func_0040B3C8(float *, int, float) throw();
extern "C" void func_0049CC48(void *);
extern "C" void func_0049FD50(int, void *, void *, void *, int, int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" int *func_004A5B70(int);
extern "C" void func_004A7550(float *);
extern "C" void func_004A7698(float *);

extern "C" void func_0040B4E0(Self *self) {
    float m[16];
    float v[3];
    int s2 = 1;
    func_004A7550(m);
    v[0] = -m[12];
    v[1] = -m[13];
    v[2] = -m[14];
    func_004A53F8();
    func_0040AD10(m, self->f8, self->fC, self->f10);
    m[12] = self->f14;
    m[13] = self->f18;
    m[14] = self->f1C;
    func_004A7698(m);
    float d = (self->f14 - v[0]) * m[4] + (self->f18 - v[1]) * m[5] + (self->f1C - v[2]) * m[6];
    if (!(d < 0.0f)) s2 = 0;
    int *s1 = func_004A5B70(1);
    int c = func_0040B3C8(&m[4], s2, self->f48);
    s1[0] = c;
    s1[1] = c;
    s1[2] = c;
    s1[3] = c;
    Glob *g = D_00621B44;
    if (g) func_0049CC48(g->f18 + self->f4C->f0 * 0x28);
    func_004A2808(0x64, 1.0f);
    func_0049FD50(4, self->f4C->f34, D_006A44F0, s1, 0, 0);
    func_004A5400();
    if (g) func_0049CC48(g->f18);
    func_004A2808(0x68, 1.0f);
}
