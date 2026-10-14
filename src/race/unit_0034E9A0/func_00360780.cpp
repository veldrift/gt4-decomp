struct Sub { char p0[0x2E]; unsigned short m2E; unsigned short m30; };
struct Buf { float f0; int f4; unsigned short h8; char pad[0x100 - 0xA]; };
struct Info { char p[4]; unsigned char m4; };
struct Cfg { char p[0x120]; unsigned char m120; };
struct O {
    char p0[0x48]; float m48;
    char p1[0x200 - 0x4C]; unsigned short m200;
    char p2[0x234 - 0x202]; unsigned char m234, m235, m236;
    char p3[0x29C - 0x237]; float m29C[16];
    float m2CC_;
    char p4[1];
};
extern "C" void func_0034F3F8(void *, Buf *, int);
extern "C" Info *func_00359510(void *);
extern "C" void func_00360520(void *, int);
extern "C" int func_003F1F78(void *);
extern "C" void func_003F3278(void *, int, float);
extern "C" float func_003F86E8(void *, Buf *);
extern "C" void func_00360780(char *o, Cfg *cfg, int a2)
{
    Buf buf;
    Sub *s1 = (Sub *)(o + 0x234);
    float t = (float)*(unsigned short *)(o + 0x200) * 0x1.acee9cp-4f / *(float *)(o + 0x29C + ((unsigned char *)o)[0x236] * 4);
    *(float *)(o + 0xFD8) = t;
    if (t > 0x1.4d5554p+8f) *(float *)(o + 0xFD8) = 0x1.4d5554p+8f;
    float f20 = *(float *)(o + 0x48);
    float p = *(float *)(o + 0x1010) * *(float *)(o + 0x2CC) * (float)func_00359510(o)->m4;
    *(float *)(o + 0x1020) = p;
    *(float *)(o + 0x101C) = f20 / (2.0f * p);
    func_0034F3F8(o + 0x134, &buf, a2);
    if (func_003F1F78(s1)) {
        int a = s1->m2E - 0x1F4;
        int b = buf.h8;
        if (a < b) b = a;
        s1->m30 = b;
    }
    func_00360520(o, a2);
    func_003F3278(o, cfg->m120, buf.f0);
    *(float *)(o + 0xFE0) = func_003F86E8(o, &buf);
}
