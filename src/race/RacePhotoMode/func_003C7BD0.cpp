/* compiler: ee-gcc2.96-nosib */
struct Cam { char pad[0x1E668]; int mode; };
extern "C" void func_001056A0(void *);
extern "C" void func_00105728(void *);
extern "C" void func_004AA168(int);
extern "C" int func_004A7D90(float, float, float, float, float, float, float);

extern "C" void func_003C7BD0(Cam *o, void *p)
{
    if (o->mode != 0) {
        func_001056A0(p);
        func_00105728(p);
        func_004AA168(0x808080);
        int m = o->mode;
        switch (m) {
        case 2:
            func_004A7D90(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 255.0f);
            break;
        case 4:
            func_004A7D90(1.5f, 0x1.e66666p-1f, 0x1.333332p-1f, 0.0f, 1.0f, 0x1.333332p-2f, 255.0f);
            break;
        }
    }
}
