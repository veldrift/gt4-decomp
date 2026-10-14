/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[8]; int width; };
extern "C" void func_001056A0(void *);
extern "C" int func_00105818(void *);
extern "C" void func_004A1638(int);
extern "C" void func_004AA168(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004A6290(int, int, int, int);
extern "C" void func_003BB288(void *unused, Obj *obj, float amount) {
    func_001056A0(obj);
    func_004A1638(6);
    float one = 1.0f;
    float blend = one - amount;
    func_004AA168(0xFFFFFF);
    int width = obj->width;
    int height = func_00105818(obj);
    func_004A2808(0x68, blend);
    func_004A6290(0, 0, width, height);
    func_004A2808(0x62, blend);
    func_004A6290(0, 0, width, height);
}
