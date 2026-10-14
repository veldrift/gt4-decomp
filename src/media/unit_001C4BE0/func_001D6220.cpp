struct A { char p[0x1A0]; float f1a0; float f1a4; };
struct B { char p[8]; int f8; };
extern "C" int func_00105818(void *);
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004A2980(int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A6140(int, int, int, int);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_004AB040(int);

extern "C" void func_001D6220(A *a, B *b) {
    float thr = 0.0078125f;
    func_004A1638(6);
    func_004AB040(5);
    func_004A29A8(0);
    func_004A2980(0xFFFFFF);
    if (a->f1a0 > thr) {
        func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
        func_004A2808(0x62, a->f1a0);
        int s = b->f8;
        func_004A6140(0, 0, s, func_00105818(b));
    }
    float f2 = a->f1a4;
    if (f2 > thr) {
        float r = 1.0f / (f2 - a->f1a0);
        if (r <= 0.9921875f || r >= 1.0078125f) {
            func_004A2808(0x89, 1.0f);
            func_004AA1D8(1.0f, 1.0f, 1.0f, r);
            int s = b->f8;
            func_004A6140(0, 0, s, func_00105818(b));
        }
    }
}
