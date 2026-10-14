/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { char name[16]; int value; };
struct Obj { char pad[0x70]; char name[16]; int value; };
extern Entry D_008511F8[];
extern int D_00851478;
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" void func_005A6AB0(void *, void *, int) throw();
extern "C" void func_004FF0E8(Obj *self) {
    if (D_00851478 < 32) {
        for (int i = 0; i < D_00851478; i++) {
            if (func_0057F238(D_008511F8[D_00851478].name, self->name) == 0)
                return;
        }
        func_005A6AB0(D_008511F8[D_00851478].name, self->name, 16);
        int n = D_00851478;
        int value = self->value;
        D_00851478 = n + 1;
        D_008511F8[n].value = value;
    }
}
