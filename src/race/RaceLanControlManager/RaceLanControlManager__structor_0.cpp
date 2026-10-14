/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VBase { char pad0[0x3C]; virtual ~VBase(); };
struct Base : VBase { char pad40[0x20]; Base() __asm__("func_0055ECF8"); virtual ~Base(); };
struct RaceLanControlManager : Base {
    int f60;
    const int f64;
    int f68, f6C, f70, f74, f78, f7C, f80;
    RaceLanControlManager(int) __asm__("func_00335E88");
    virtual ~RaceLanControlManager();
};
RaceLanControlManager::RaceLanControlManager(int arg1) : f64(arg1), f7C(1) {
    f60=0;
    f68=0;
    f6C=0;
    f70=0;
    f74=0;
    f78=0;
    f80=0;
}
