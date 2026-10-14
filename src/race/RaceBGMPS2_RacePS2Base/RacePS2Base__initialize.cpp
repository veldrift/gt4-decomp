/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef unsigned int u32; typedef short s16; typedef signed char s8; typedef float f32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern "C" {
void func_00102438(); void func_0033D080(char *); void func_0033DD18(char *); void RaceBase__initialize(char *); void RaceCourse__update(s32);
void func_00395B60(char *); s32 func_00395C68(char *); void func_00396A48(char *); void func_00398400(char *,s32); void func_00398A70(char *);
void func_003B70C8(char *); void func_003C2070(char *); void func_003CEB90(char *,s32,s32,char *); void func_003E4DD0(char *);
void func_003E7538(char *); void func_003E75E0(char *,s32); s32 func_00437260(s32); void func_0044E500(); void func_004635E0(s32);
void func_00496008(s32); void func_00496488(s32,s32,s32);
}
struct VEntry { s16 delta; s16 index; void (*fn)(char *); };
extern s32 D_00621B48,D_00621B44,RigidBodyManager__carCollision_,D_006D6054,D_00622F4C,D_00620200;
extern char *D_006D6060; extern f32 RaceCarSound__visual_volume_;
static inline void set1(s32 v) { D_00621B48=v; }
static inline void set2(s32 v) { D_00621B44=v; }
static inline void set3(char *v) { D_006D6060=v; }
static inline u32 mode(char *p) { return M2C_FIELD(p, u32 *, 0xCC8); }
static inline void clear(float *p) { *p = 0.0f; }
static inline int mode4(u32 x) { return (x ^ 4) == 0; }
extern "C" void RacePS2Base__initialize(char *arg0) {
    f32 *var_v0;
    s32 *var_v1;
    s32 temp_a1;
    char *temp_s1;
    char *temp_s2;
    s32 var_a0;
    u32 temp_a0;
    u32 var_v0_2;
    char *temp_a1_2;
    char *temp_a1_3;
    char *temp_s0;
    char *temp_s0_2;
    VEntry *temp_v0;
    VEntry *temp_v0_2;
    char *temp_v1;

    temp_s0 = arg0 + 0x31D0;
    temp_s1 = arg0 + 0x3238;
    temp_s2 = arg0 + 0x35E8;
    M2C_FIELD(arg0, s32 *, 0xD80) = 0;
    RaceBase__initialize(arg0);
    func_00396A48(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4));
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 8) = temp_s0;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 0x10) = temp_s1;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 0xC) = temp_s2;
    func_003E7538(temp_s0);
    func_003E75E0(temp_s0, M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4), s32 *, 0x68));
    temp_a1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4), s32 *, 0x80);
    M2C_FIELD(temp_s0, s32 *, 0x38) = temp_a1;
    func_003C2070(temp_s1);
    set1(M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4), s32 *, 0x80));
    set2(M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4), s32 *, 0x9C));
    set3(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80));
    RigidBodyManager__carCollision_ = M2C_FIELD(arg0, s32 *, 0x70) + 0xDA6C;
    temp_a1_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4);
    D_006D6054 = M2C_FIELD(temp_a1_2, s32 *, 0xBC);
    func_003E4DD0(temp_s2);
    func_00395B60(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80));
    temp_s0_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4), char **, 0x80);
    func_00496008(0x7F7F7F7F);
    func_00496488(M2C_FIELD(arg0, s32 *, 0xD94), M2C_FIELD(arg0, s32 *, 0xD98), M2C_FIELD(temp_s0_2, s32 *, 0xB0));
    func_00398400(temp_s0_2, M2C_FIELD(arg0, s32 *, 0xD94));
    temp_a1_3 = arg0 + 0xDA0;
    M2C_FIELD(temp_a1_3, s32 *, 0x7C) = (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4), s32 *, 0x98);
    M2C_FIELD(temp_a1_3, s32 *, 0x80) = (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4), s32 *, 0x94);
    M2C_FIELD(temp_a1_3, s32 *, 0x88) = (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80), char **, 4), s32 *, 0xA0);
    func_003CEB90(arg0 + 0x3628, func_00395C68(M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80)), M2C_FIELD(arg0, s32 *, 0x70), M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), char **, 0x80));
    func_003B70C8(arg0 + 0xCF68);
    func_0044E500();
    temp_v0 = (VEntry *)(M2C_FIELD(arg0, char **, 0x64) + 0x338);
    temp_v0->fn(arg0 + temp_v0->delta);
    func_0033D080(arg0 + 0xCF88);
    RaceCourse__update((u32) mode(arg0) >= 2U);
    RaceCarSound__visual_volume_ = 1.0f;
    func_00398A70(arg0 + 0xE170);
    func_004635E0(func_00437260(D_00622F4C + 0x38CB0));
    M2C_FIELD(arg0, s32 *, 0xCF38) = 0;
    M2C_FIELD(arg0, s32 *, 0xCF3C) = 0;
    var_v1 = (s32 *)(arg0 + 0xCF50);
    M2C_FIELD(arg0, s32 *, 0xCF40) = 0;
    var_v0 = (f32 *)(arg0 + 0xCF48);
    var_a0 = 1;
    do {
        var_a0 -= 1;
        *var_v0 = 1.0f;
        *var_v1 = 0;
        var_v1++;
        var_v0++;
    } while (var_a0 >= 0);
    M2C_FIELD(arg0, s8 *, 0xCF5A) = 0;
    M2C_FIELD(arg0, s8 *, 0xCF59) = -1;
    M2C_FIELD(arg0, s8 *, 0xCF5B) = 0;
    M2C_FIELD(arg0, s32 *, 0xCF60) = (s32) D_00620200;
    M2C_FIELD(arg0, s32 *, 0xCF64) = 0;
    M2C_FIELD(arg0, s32 *, 0xCF84) = 0;
    func_00102438();
    func_0033DD18(arg0);
    if (mode(arg0) < 2U || (mode(arg0) - 2 < 2U && M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), s32 *, 0xDC) == 0 && M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), s32 *, 0xF0) == 0)) {
        clear((float *)(arg0 + 0xE3D4));
    }
    if ((mode(arg0) - 2 < 2U || mode4(mode(arg0))) && M2C_FIELD(M2C_FIELD(arg0, char **, 0x6C), s32 *, 0xDC) == 0) {
        temp_v0_2 = (VEntry *)(M2C_FIELD(arg0, char **, 0x64) + 0x480);
        temp_v0_2->fn(arg0 + temp_v0_2->delta);
    }
}
