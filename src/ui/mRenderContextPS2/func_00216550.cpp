/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001056A0(void *);
extern "C" void func_00105728(void *);
extern "C" void func_004A1638(int);
extern "C" void func_004A2980(int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A2A10(int);
extern "C" void func_004A4550(int, int);
extern "C" void pglPushAttrib(int);
extern "C" void func_004A5688(void);
extern "C" void func_004A6788(float, float, float, float, float, float, float, float);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_004AB040(int);
extern "C" void func_00216550(void *a, void *b, float *r, int flag) {
    if (flag != 0) func_004A2980(0xFFFFFF);
    pglPushAttrib(0x887);
    func_00105728(a);
    func_001056A0(b);
    func_004A2A10(0);
    func_004A4550(3, 0);
    func_004A4550(2, 0);
    func_004AB040(4);
    func_004AB040(5);
    func_004A1638(6);
    func_004A29A8(0);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
    float x = r[0];
    float y = r[1];
    float x2 = x + r[2];
    float y2 = y + r[3];
    func_004A6788(x, y, x2, y2, x, y, x2, y2);
    func_004A5688();
    if (flag != 0) func_004A2980(-1);
}
