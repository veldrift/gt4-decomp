/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
#define F(p,o) (*(float *)((p)+(o)))
extern "C" int Automobile__getDrawMode(u8 *);
extern "C" int func_00368398(u8 *);
extern u8 D_00843630[];
extern "C" void func_00350080(u8 *p) {
    u8 *s = p + 0x104;
    u8 *g = D_00843630;
    if (Automobile__getDrawMode(p) != 3) {
        s[0x605] = 0;
        s[0x606] = 0;
        s[0x604] = 0;
        F(s,0x504) = 0.0f;
        return;
    }
    u8 *v = *(u8 **)(p+0x10);
    u8 *prm = v+0x234;
    float threshold = (float)*(unsigned short *)(v+0x202)*0x1.acee9cp-4f;
    if (func_00368398(prm) && F(s,0x4FC) < threshold) {
        s[0x605] = 0;
        s[0x604] = 0;
        return;
    }
    float x = F(s,0x4F0);
    if (x > 1.0f) x = 1.0f;
    float ratio = F(s,0x4EC)/(F(s,0x4EC)+F(s,0x4E8));
    float delta = x-ratio;
    float amount = delta;
    if (delta < 0.0f) amount = -delta;
    amount += ratio;
    if (s[0x522] != 1) amount *= 0.5f;
    if (func_00368398(prm)) amount *= 0.5f;
    int n = (int)(amount * 127.0f * F(g,0x64));
    if (n >= 128) n = 127;
    s[0x604] = (s[0x604]+n)/2;
    if (delta < 0.0f) delta = 0.0f;
    delta /= 1.0f-ratio;
    delta = 1.0f-delta;
    delta *= delta;
    delta *= delta;
    delta *= delta;
    delta *= delta;
    delta = 1.0f-delta;
    delta = delta*0x1.333332p-1f+0x1.999998p-2f;
    if (func_00368398(prm)) delta *= 0.5f;
    int n2 = (int)(delta * 127.0f * F(g,0x68));
    if (n2 >= 128) n2 = 127;
    s[0x605] = (s[0x605]+n2)/2;
    int n3 = (int)((float)s[0x606]*F(g,0x6C));
    if (n3 >= 128) n3 = 127;
    s[0x606] = n3;
    F(s,0x504) *= F(g,0x70);
}
