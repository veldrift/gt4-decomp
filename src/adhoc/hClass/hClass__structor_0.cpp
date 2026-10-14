/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_0083CEF0[];
struct Base {
    int unk0;
    virtual ~Base();
};
struct Module : Base {
    char pad[0x24];
    Module(void *) __asm__("func_00305270");
};
struct hClass : Module {
    int f2c;
    short f30, f32;
    int f34;
    hClass() __asm__("func_002F3318");
    virtual ~hClass();
};
hClass::hClass() : Module(D_0083CEF0), f2c(0), f30(-1), f34(0) {}
