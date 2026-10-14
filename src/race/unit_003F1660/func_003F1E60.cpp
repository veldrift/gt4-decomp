/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct V8 { float f[8]; };
struct V16 { float f[16]; };
struct Car { char p[0x8C]; V8 a; V8 b; char q[0x104 - 0xCC]; char in[0x466]; };
struct Self { void *owner; char p[0xF8A0 - 4 + 0x10000 - 0x10000]; };
extern "C" Car *func_0034C190(void *, int);
extern "C" int func_00468C50(Car *);

extern "C" void func_003F1E60(char *self)
{
    int i = 0;
    char *owner = *(char **)self;
    if (*(int *)(self + 0xF8A0) > 0) {
        do {
            Car *car = func_0034C190(self, i);
            u8 *in = (u8 *)car + 0x104;
            i++;
            if (in[0x466] < 2 && in[0x441] == 0) {
                *(V16 *)&car->a = *(V16 *)(owner + 0x20);
                func_00468C50(car);
            }
        } while (i < *(int *)(self + 0xF8A0));
    }
}
