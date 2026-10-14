typedef int s32;

struct V {
    char pad[6];
    short x;
    short y;
    short z;
};

extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7550(s32 arg0);
extern "C" void func_004A7988(float arg0);
extern "C" void func_004A79B0(float arg0);
extern "C" void func_004A79D8(float arg0);

extern "C" void func_001025E8(s32 arg0, V *arg1) {
    func_004A53F8();
    func_004A7454();
    func_004A7988((float)arg1->x * (1.40625f / 256.0f));
    func_004A79B0((float)arg1->y * (1.40625f / 256.0f));
    func_004A79D8((float)arg1->z * (1.40625f / 256.0f));
    func_004A7550(arg0);
    func_004A5400();
}
