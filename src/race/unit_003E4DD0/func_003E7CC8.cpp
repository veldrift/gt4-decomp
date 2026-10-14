/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Texture {
    int resource, flags, width, height, a10, a14, a18, a1c;
    float u, v;
    int a28, a2c, a30, owned, a38;
    Texture(int, int, int) asm("func_001052E0");
    ~Texture() asm("func_00105280");
};
struct Inner { char pad[0x914]; int w; char pad918[4]; int h; };
struct Self { char pad[0x38]; Inner *inner; };
extern "C" void func_003E7F08(Self *, int, int);
extern "C" void func_00105AD8(Texture *, Texture *, int, int);
extern "C" void pglPushAttrib(int);
extern "C" void func_001056A0(Texture *);
extern "C" void func_00105708(Texture *);
extern "C" void func_004A3078(int);
extern "C" void func_004A3230(int);
extern "C" void func_004A5688();
extern "C" void func_00105728(Texture *);
extern "C" void func_004AB040(int);
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004A29A8(int);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" int GSBuffer__getBufferWidth(Texture *);
extern "C" int func_00105818(Texture *);
extern "C" void func_004A6498(int, int, int, int, int, int, int, int);

extern "C" void func_003E7CC8(Self *self, Texture *tex, int arg2, int arg3) {
    Inner *in = self->inner;
    int w = in->w;
    int h = in->h;
    if (w >= 0x41) w = 1;
    if (h >= 0x41) h = 1;
    if (w <= 0) w = 1;
    if (h <= 0) h = 1;
    int big = tex->height >= 0x101;
    if ((w == 1 && h == w) || big) {
        func_003E7F08(self, arg2, arg3);
        return;
    }
    int tw = GSBuffer__getBufferWidth(tex) / w;
    int th = tex->height / h;
    Texture a(0, tw, th);
    Texture b(0x31, tw, th);
    func_00105AD8(&b, tex, 0, 0);
    pglPushAttrib(0x887);
    func_001056A0(&a);
    func_00105708(&b);
    func_004A3078(0);
    func_004A3230(1);
    func_003E7F08(self, 1, arg3);
    func_004A5688();
    func_00105728(&a);
    func_004AB040(5);
    func_004AB040(8);
    func_004A1638(6);
    func_004A2808(0x68, 1.0f);
    func_004A29A8(0);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
    int bw = tex->width;
    int bh = func_00105818(tex);
    func_004A6498(0, 0, bw, bh, 0, 0, (b.a10 + b.a18) - (h >= 2), (b.a14 + b.a1c) - (w >= 2));
    func_004A29A8(1);
}
