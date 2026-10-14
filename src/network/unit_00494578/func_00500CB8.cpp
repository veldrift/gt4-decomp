/* compiler: ee-gcc2.96-nogcse */
struct S { char pad[0xA3C]; int field; };
struct Arg { int value, unused, value8; };
struct Request { char pad[0x18]; int value, flag; char tail[0x30]; };
extern "C" int func_0052F6F0(int *, int);
extern "C" int func_004F9800(S *);
extern "C" void func_004F8820(S *, int) throw();
extern "C" void func_004F8858(S *, int) throw();
extern "C" void func_004FB548(S *) throw();
extern "C" int func_004F0D48(S *);
extern "C" void func_00500DA0();
extern "C" int func_00505F98(Request *, void (*)(), int);
extern volatile int D_0085147C[1];
static inline volatile int *reset() { volatile int *p = D_0085147C; (void)(*p = 0); return p; }
extern "C" void func_00500CB8(S *s, Arg *arg) {
    int status = -999;
    Request request;
    int r = func_0052F6F0(&status, arg->value);
    if (r == 0) {
        if (func_004F9800(s) != 0) {
            request.flag = 1;
            request.value = s->field;
            r = func_00505F98(&request, func_00500DA0, arg->value8);
            if (r == 0) {
                volatile int *done = reset();
                for (;;) {
                    if (*done != 0) return;
                    func_004FB548(s);
                    if (func_004F0D48(s) != 1) return;
                }
            } else {
                func_004F8858(s, r);
            }
        }
    } else {
        func_004F8820(s, r);
    }
}
