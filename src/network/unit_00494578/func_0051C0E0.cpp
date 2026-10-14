extern "C" int func_0051BE28(void) throw();
extern "C" int func_0051BE60(void) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
struct Global { int active; int handle; void *data; };
struct Ops { char pad[0x14]; int (*open)(int *, long, int, int *); char pad2[0x6c-0x18]; void (*get)(void *); };
extern "C" Global D_00863798;
extern "C" Ops *D_0064B4B0;
extern "C" int func_0051C0E0(void **arg) {
    int r = func_0051BE28();
    if (r == 0) {
        int result = 5;
        if (D_00863798.active == 0) {
            long token[2];
            int params[3];
            func_005A48D8(params, 0, 12);
            params[0] = 3;
            D_0064B4B0->get(token);
            result = D_0064B4B0->open(&D_00863798.handle, token[0], 0, params);
            if (result == 0) {
                D_00863798.active = 1;
                D_00863798.data = *arg;
            }
        }
        func_0051BE60();
        r = result;
    }
    return r;
}
