struct Vec3 { float x; float y; float z; };
struct Y4 { char pad0[4]; void *p4; };
struct X80 { char pad0[0x80]; Y4 *y80; };
struct Self { char pad0[0x6C]; X80 *x6c; char pad1[0xE330 - 0x70]; int e330; };

extern char D_006883F8[];

extern "C" void func_0044EEA8(void *arg0);
extern "C" void func_0044F058(void *arg0, int arg1, float arg2, float arg3, float arg4, float arg5);
extern "C" void func_0044E660(int arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5);
extern "C" void CameraBase__structor_1(void *arg0, int arg1);

extern "C" void func_0033E960(Self *arg0, int arg1, int arg2, Vec3 *arg3, int arg4, float fparg0) {
    char buf[0x70];
    int s3 = arg0->e330;
    func_0044EEA8(buf);
    func_0044F058(buf, arg2, arg3->x, arg3->y, arg3->z, fparg0);
    func_0044E660(arg1, arg0->x6c->y80->p4, buf, arg4, s3 >> 1, s3);
    *(int *)buf = (int)D_006883F8;
    CameraBase__structor_1(buf, 0);
}
