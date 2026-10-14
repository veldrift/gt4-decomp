/* compiler: ee-gcc2.96-nsa-nosib */
struct Obj { char pad[0x128]; int mode; };
extern "C" void func_001056A0(void *);
extern "C" void func_00105728(void *);
extern "C" void func_004AA168(int);
extern "C" int func_004A7D90(float, float, float, float, float, float, float);
extern "C" void func_00334CB8(Obj *o, void *p) {
    if (o->mode != 0) {
        func_001056A0(p);
        func_00105728(p);
        func_004AA168(0x808080);
        switch(o->mode) {
        case 2:
            func_004A7D90(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 255.0f);
            break;
        case 4:
            func_004A7D90(1.5f, 0.95f, 0.6f, 0.0f, 1.0f, 0.3f, 255.0f);
            break;
        }
    }
}
