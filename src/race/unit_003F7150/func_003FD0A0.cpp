struct Obj;
extern "C" float func_00344798(Obj *, float);
extern "C" float func_003447F8(Obj *, float);
extern "C" float func_00344828(Obj *, float);
extern "C" float func_00344858(Obj *, float);
extern "C" float func_00344888(Obj *, float);
extern "C" float func_003448B8(Obj *, float);
extern "C" void func_004A0690(void);
extern "C" void func_004A06F0(void);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7844(float, float, float);
extern "C" void func_004A7988(float);
extern "C" void func_004A79B0(float);
extern "C" void func_004A79D8(float);
extern "C" void func_004A7AA8(void *, void *);

extern "C" void func_003FD0A0(int *flags, float *pos, Obj *o, float t)
{
    float v[4];
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    if ((*flags >> 2) & 1) func_004A79D8(func_00344888(o, t) * 0x1.ca5dc0p+5f);
    if (*flags & 1) func_004A7988(-func_00344858(o, t) * 0x1.ca5dc0p+5f);
    if ((*flags >> 1) & 1) func_004A79B0(-func_003448B8(o, t) * 0x1.ca5dc0p+5f);
    float a = -func_00344798(o, t);
    float b = -func_003447F8(o, t);
    func_004A7844(a, b, -func_00344828(o, t));
    float x0 = pos[0];
    int o1 = 4, o2 = 8;
    float *py = (float *)((char *)pos + o1);
    float *pz = (float *)((char *)pos + o2);
    float *vy = (float *)((char *)v + o1);
    float *vz = (float *)((char *)v + o2);
    v[0] = x0;
    *vy = *py;
    *vz = *pz;
    v[3] = 1.0f;
    func_004A7AA8(v, v);
    pos[0] = v[0];
    *py = *vy;
    *pz = *vz;
    func_004A5400();
    func_004A06F0();
}
