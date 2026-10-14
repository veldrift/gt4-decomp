/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mesh { int p0; char *data; };
extern "C" int func_003C9F18(int) throw();
extern "C" int func_0041B3D0(unsigned);
extern "C" Mesh *ModelSet2__searchModelName(void *, int, int *);
extern "C" void ModelSet2__begin(void *, int);
extern "C" void ModelSet2__end(void *);
extern "C" int ModelSet2___render(void *, char *, int);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7698(int);
extern "C" void func_004A7844(float, float, float);
extern "C" void func_004A7B60(int, int);

extern "C" void func_003D0BD0(void *self, int arg1, int arg2, float *pos)
{
    int count;
    int i;
    int name;
    Mesh *m;
    int k;
    ModelSet2__begin(self, 0);
    for (i = 0; i < 0x15; i++) {
        if (i < 0x14) {
            name = func_0041B3D0(i);
        } else {
            if (arg1 == 0)
                break;
            name = arg1;
        }
        m = ModelSet2__searchModelName(self, name, &count);
        if (m != 0 && count > 0) {
            func_004A53F8();
            int h = func_003C9F18(name);
            if (h != 0) {
                func_004A7698(h);
                for (k = 0; k < count; k++)
                    ModelSet2___render(self, m->data + k, 0);
            }
            func_004A5400();
        }
    }
    m = ModelSet2__searchModelName(self, (int)"SKINNING", &count);
    if (m != 0) {
        func_004A53F8();
        func_004A7844(pos[0], pos[1], pos[2]);
        func_004A7B60(arg2, 0x14);
        for (k = 0; k < count; k++)
            ModelSet2___render(self, m->data + k, 0);
        func_004A5400();
    }
    ModelSet2__end(self);
}
