/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x34];
    float value;
    char pad38[7];
    unsigned char flag;
    char pad40[0xA8];
    char *data;
};
extern "C" void func_00463CD8(Obj *obj, int mode) {
    char *data = obj->data;
    char *p = data + 0x104;
    char *params = *(char **)(data + 0x10);
    float skill = (float)*(signed char *)(data + 0x5B3);
    *(int *)(p + 0x514) = 0;
    if (mode >= 13) {
        unsigned char flag = obj->flag;
        float dt = *(float *)(obj->data + 0x54C);
        if (flag == 0) {
            if (*(short *)(p + 0x4FA) < ((*(unsigned short *)(params + 0x262) * 3) >> 2)) {
                obj->flag = 1;
                flag = 1;
            }
        } else {
            if (*(short *)(p + 0x4FA) >= (*(unsigned short *)(params + 0x262) * 15) / 16) {
                obj->flag = 0;
                flag = 0;
            }
        }
        if (flag) {
            obj->value = obj->value + dt * (5.0f - skill * 0x1.999998p-3f);
            if (obj->value > 1.0f) obj->value = 1.0f;
        } else {
            obj->value = obj->value - dt * (10.0f - skill * 0x1.999998p-2f);
            if (obj->value < 0.0f) obj->value = 0.0f;
        }
    } else {
        float ratio = (float)(*(short *)(p + 0x4FA) - *(unsigned short *)(params + 0x262)) / (float)*(unsigned short *)(params + 0x200);
        obj->value = (0.625f - skill * 0x1.0624dcp-9f) - (ratio + ratio);
        if (obj->value > 1.0f) {
            obj->value = 1.0f;
            return;
        }
        if (obj->value < 0.0f) obj->value = 0.0f;
    }
}
