/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Copy8 { char x[8]; };
struct Obj { char pad[8]; int type; char padc[0x58]; Copy8 data; };
extern "C" int func_0051BE28() throw();
extern "C" int func_0051BE60();
extern "C" Obj *func_0051DD88(int);
extern "C" int func_0051C8B0(int arg0, Copy8 *arg1) {
    int ret = func_0051BE28();
    if (ret == 0) {
        int status = 2;
        Obj *o = func_0051DD88(arg0);
        if (o) {
            if (o->type == 8) { *arg1 = o->data; status = 0; }
            else status = 0xCB2D;
        }
        func_0051BE60();
        ret = status;
    }
    return ret;
}
