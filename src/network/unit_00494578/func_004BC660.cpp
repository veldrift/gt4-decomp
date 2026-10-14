/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char pad[0x2C]; int *p2C; char pad30[8]; int *p38; };
extern S *D_006452D4;
extern "C" void func_004BC6E8(void *);
extern "C" int func_004BFC70(void *, int);
extern "C" int func_004BC098() throw();
extern "C" int func_004BC660() {
    int result = 0x8000024F;
    if (*D_006452D4->p2C == 0x65) return result;
    func_004BC6E8(D_006452D4);
    int r = func_004BFC70(D_006452D4, 0x300);
    if (r == 0) {
        func_004BC098();
        *D_006452D4->p38 = 0;
    }
    return r;
}
