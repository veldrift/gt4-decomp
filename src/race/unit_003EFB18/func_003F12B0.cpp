struct Owner;
struct Car;
extern "C" Car *func_0034C190(void *self, int index);
extern "C" void func_003C0F08(int a, int b, void *c);
extern "C" void func_003EFF98(void *a);
extern "C" void func_003F0230(void *a, void *b, int c);
extern "C" int func_003F12A0(void *a);

extern "C" void func_003F12B0(char *arg0) {
    char buf[0x30];
    int s1 = 0;
    int s3 = *(int *)(arg0 + 0xF8A0);
    int s4 = *(int *)arg0;
    if (s3 > 0) {
        do {
            char *s0 = (char *)func_0034C190(arg0, s1);
            if (*(signed char *)(s0 + 0x56A) == 0) {
                func_003EFF98(s0);
                func_003F0230(s0, buf, func_003F12A0(arg0));
                func_003C0F08(s4, s1, buf);
            }
            s1 += 1;
        } while (s1 < s3);
    }
}
