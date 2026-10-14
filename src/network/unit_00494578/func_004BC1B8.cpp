/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { char pad[0x2C]; int *p; };
extern O *D_006452D4;
extern "C" int func_004BC098() throw();
extern "C" void func_004BC6E8(O *);
extern "C" int func_004C99B8(O *, int);
extern "C" int func_004BC1B8(int a) {
    if (*D_006452D4->p == 0x65) return 0x80000276;
    func_004BC098();
    func_004BC6E8(D_006452D4);
    return func_004C99B8(D_006452D4, a);
}
