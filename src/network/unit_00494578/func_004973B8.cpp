/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char pad[0x20]; int handle, width, height; };
extern "C" void func_004971A0(int,int,int) throw();
extern "C" void func_00497200(int,int,int) throw();
extern "C" void func_004A4550(int,int);
extern "C" void func_004A4910();
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004A6668(float,float,float,float,float,float,float,float);
extern "C" void func_004973B8(S *p, int w, int h) {
    int pw = p->width;
    int ph = p->height;
    if (pw < w) w = pw;
    if (ph < h) h = ph;
    func_004971A0(p->handle, pw, ph);
    func_00497200(p->handle, pw, ph);
    func_004AA1D8(1.0f,1.0f,1.0f,1.0f);
    func_004A4550(3,1);
    func_004A4550(2,1);
    while (w >= 2 || h >= 2) {
        int nw = w >> 1;
        int nh = h >> 1;
        if (nw * 2 != w) nw *= 2;
        if (nh * 2 != h) nh *= 2;
        if (nw <= 0) nw = 1;
        if (nh <= 0) nh = 1;
        func_004A4910();
        func_004A6668(0.0f,0.0f,(float)nw,(float)nh,0.0f,0.0f,(float)w,(float)h);
        w = nw;
        h = nh;
    }
}
