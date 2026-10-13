/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;

struct func_00450F50_elem {
    char pad0[0x18];
    float unk18;
    float unk1C;
    float unk20;
};

extern "C" void func_00458A30(Obj *o, int flags, float a, float b, float c);

extern "C" void func_00450F50(int *arg0, unsigned int arg1, float fparg0, float fparg1, float fparg2)
{
    char *temp_v1;

    temp_v1 = (char *)arg0 + arg1 * 0x38 + 0x94;
    if (arg1 < 4U) {
        struct func_00450F50_elem *e = (struct func_00450F50_elem *)temp_v1;
        float d = fparg1 - fparg2;
        e->unk18 = fparg0;
        e->unk20 = fparg1;
        e->unk1C = d;
        func_00458A30((Obj *)*arg0, arg1, fparg0, fparg1, fparg2);
    }
}
