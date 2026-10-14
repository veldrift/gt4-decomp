/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x2C];
    float f2C;
    float f30;
    float f34;
    int i38;
    short i3C;
    unsigned char i3E;
    char pad3F[0xA9];
    char *data;
};
extern unsigned char D_00623E54;
extern "C" void func_00464ED8(Obj *obj) {
    char *data = obj->data;
    float speed = *(float *)(data + 0x56C);
    obj->f34 = 0.0f;
    obj->f30 = speed;
    obj->i38 = 0;
    obj->i3E = 0;
    obj->i3C = 0;
    if (D_00623E54 == 0) {
        float a = obj->f2C;
        float b = obj->f34;
        if (b < a) {
            float x = a - *(float *)(data + 0x54C);
            obj->f2C = x;
            if (x < b) obj->f2C = b;
        }
    }
}
