struct Local { float a; int b; float c; int d; };
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A74B4(void *p);
extern "C" void func_004A7AA8(void *p, Local *l);
extern "C" float func_0057D1F0(float x);
extern "C" float func_0057D380(float x);

extern "C" void func_001D68B8(void *arg0, void *arg1, float fparg0, float fparg1) {
    Local L;
    float x = fparg1 * 6.2831853f;
    float t20 = func_0057D380(fparg0 * 0.017453292f);
    float r;
    L.a = 1.0f;
    L.b = 0;
    r = func_0057D1F0(x * 0.5f);
    t20 = t20 * r;
    L.c = t20;
    L.d = 0;
    func_004A53F8();
    func_004A74B4(arg1);
    func_004A7AA8(arg0, &L);
    func_004A5400();
}
