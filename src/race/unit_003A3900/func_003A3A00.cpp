/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Texture;
struct Self {
    Texture *tex;
    float unk4;
    char pad8[0x1C];
    float unk24;
};
extern "C" Texture *func_003A1E10(const char *s);
extern "C" void func_003AEF18(Texture *t, float x, float y, unsigned xf, unsigned yf);
extern "C" void func_004A2808(s32, float);
extern "C" void func_004AA1D8(float, float, float, float);

extern "C" void func_003A3A00(Self *arg0) {
    func_004A2808(0x44, 1.0f);
    func_004AA1D8(1.0f, 1.0f, 1.0f, arg0->unk4 * 0.5f * (1.0f - arg0->unk24));
    if (arg0->tex == 0) {
        arg0->tex = func_003A1E10("JP/gt_logo_mini");
    }
    func_003AEF18(arg0->tex, 604.0f, 441.0f, 0xD, 1);
}
