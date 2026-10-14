extern "C" void func_00395910(int, float *, int *, float *);
extern "C" void func_004A0690(void);
extern "C" void func_004A06F0(void);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7844(float, float, float);
extern "C" void func_004A7A54(void);
extern "C" void func_004A7AA8(void *, void *);

extern "C" float func_003FE358(int a, float *p, int *q)
{
    float v[4];
    float r[4];
    float pl[4];
    float res = 0.0f;
    int o1 = 4, o2 = 8;
    float *vy = (float *)((char *)v + o1);
    float *vz = (float *)((char *)v + o2);
    v[0] = res;
    *vy = res;
    *vz = res;
    v[3] = 1.0f;
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    float t1 = *(float *)((char *)p + o1) + 3.0f;
    float t2 = *(float *)((char *)p + o2);
    float t0 = p[0];
    func_004A7844(-t0, -t1, -t2);
    func_004A7A54();
    func_004A7AA8(v, v);
    r[0] = v[0];
    r[1] = *vy;
    r[2] = *vz;
    func_00395910(a, r, q, pl);
    if (*q >= 0 && pl[1] != 0.0f)
        res = -(r[0] * pl[0] + r[2] * pl[2] + pl[3]) / pl[1];
    func_004A5400();
    func_004A06F0();
    return res;
}
