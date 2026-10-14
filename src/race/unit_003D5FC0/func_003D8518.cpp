/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#include "m2c_macros.h"
struct Header { int x0; int x4; int x8; void * xc; int x10; int x14; int x18; int x1c; int x20; int x24; int x28; int x2c; int x30; int x34; int x38; int x3c; int x40; int x44; int x48; int x4c; int x50; int x54; int x58; int x5c; int x60; int x64; int x68; int x6c; int x70; int x74; int x78; int x7c; float x80; float x84; int x88; int x8c; int x90; int x94; int x98; int x9c; int xa0; int xa4; int xa8; };
struct Sub8 { char pad[0x110]; int matrix[6][16]; };
struct Sub4 { char pad[0xfb0]; char rows[1]; };
struct SubC { char pad[0xa0]; int map[6]; };
struct List { int n; int pad; char **items; };
struct Group { char pad[0x60]; List *list; };
extern int D_006184F0;
extern "C" {
void func_003BECB0(void *,void *);
void RaceDisplayObjectBase__setLocation(void *, short, short);
void RaceMiniMap__virtual_07(void *, short, short);
void RaceDisplayObjectBase__setAlignment(void *, signed char, signed char);
void func_003ADF00(void *);
void func_003AE2B8(void *, int);
void RaceMessageDisplay__setMessage(void *, const char *, float, float);
int func_003D8BE8(void *, void *);
void func_003D92B0(void *);
int func_00445AE8(void *, void *);
void func_00474F38(void *, int, int, int);
void func_00475D88(void *, void (*)(void *), void *);
void func_003D7910(void *);
void *exception__structor_0(int);
}
extern "C" void func_003D8518(char *arg0, char *arg1, u32 arg2) {
    s32 *var_a0;
    s32 *var_a1;
    s32 *var_a4;
    s32 *var_a5;
    s32 temp_v0;
    s32 var_a6;
    s32 var_s3;
    s32 var_s4;
    s32 var_v1;
    char *var_a2;
    char *var_a3;
    char *var_s2;
    char *temp_a1;
    char *temp_s0;
    char *temp_s1;
    char *temp_s2;
    char *temp_s3;
    char *temp_s4;
    char *temp_s6;
    char *temp_v0_2;
    char *var_s1;

    temp_s1 = arg0 + 0x358;
    temp_s2 = arg0 + 0x298;
    temp_s3 = arg0 + 0x300;
    temp_s4 = arg0 + 0x328;
    temp_s6 = arg0 + 0x394;
    M2C_FIELD(arg0, void **, 0xC) = arg1;
    ((Header *)arg0)->x10 = 0;
    ((Header *)arg0)->x18 = (s32) (arg2 < 2U);
    ((Header *)arg0)->x1c = 0;
    ((Header *)arg0)->x20 = 0;
    ((Header *)arg0)->x24 = 0;
    ((Header *)arg0)->x28 = 2;
    ((Header *)arg0)->x2c = 2;
    ((Header *)arg0)->x30 = 0;
    ((Header *)arg0)->x34 = 0;
    ((Header *)arg0)->x38 = 0;
    ((Header *)arg0)->x3c = arg2;
    ((Header *)arg0)->x40 = 0;
    ((Header *)arg0)->x44 = 1;
    ((Header *)arg0)->x4c = 0;
    ((Header *)arg0)->x50 = 0;
    ((Header *)arg0)->x54 = 0;
    ((Header *)arg0)->x58 = 0;
    ((Header *)arg0)->x5c = 0;
    ((Header *)arg0)->x60 = 0;
    ((Header *)arg0)->x64 = 0;
    ((Header *)arg0)->x68 = 1;
    ((Header *)arg0)->x6c = 0;
    ((Header *)arg0)->x70 = 1;
    ((Header *)arg0)->x74 = 1;
    ((Header *)arg0)->x78 = 1;
    ((Header *)arg0)->x7c = 0;
    ((Header *)arg0)->x80 = -1.0f;
    ((Header *)arg0)->x84 = 1.0f;
    ((Header *)arg0)->x88 = 0;
    ((Header *)arg0)->x8c = 0;
    ((Header *)arg0)->x90 = 0;
    ((Header *)arg0)->x94 = 2;
    ((Header *)arg0)->x98 = 1;
    ((Header *)arg0)->x9c = -1;
    ((Header *)arg0)->xa0 = 0;
    ((Header *)arg0)->xa4 = 0;
    ((Header *)arg0)->xa8 &= ~0xFF;
    ((Header *)arg0)->xa8 = (((Header *)arg0)->xa8 & 0xFFFF00FF) | 0x100;
    func_003BECB0(temp_s2,arg1);
    M2C_FIELD(temp_s2, s32 *, 0x40) = 1;
    M2C_FIELD(temp_s2, s32 *, 0x44) = 0;
    RaceDisplayObjectBase__setLocation(temp_s3, 0, 0);
    RaceMiniMap__virtual_07(temp_s3, 0x56, 0xB);
    RaceDisplayObjectBase__setAlignment(temp_s3, 0, 2);
    RaceDisplayObjectBase__setLocation(temp_s4, 0, 0);
    RaceMiniMap__virtual_07(temp_s4, 0x28, 0x44);
    RaceDisplayObjectBase__setAlignment(temp_s4, 0, 0);
    M2C_FIELD(temp_s4, s32 *, 0x18) = 1;
    func_003ADF00(temp_s1);
    M2C_FIELD(arg0, s32 *, 0x358) = (s32) (M2C_FIELD(arg0, s32 *, 0x358) & ~0xFF);
    RaceDisplayObjectBase__setLocation(temp_s1, 0, 0x1E0);
    RaceMiniMap__virtual_07(temp_s1, D_006184F0 ? 0x356 : 0x280, 0x2A);
    func_003AE2B8(temp_s1, 1);
    RaceMessageDisplay__setMessage(temp_s6, 0, 0.0f, 0.0f);
    M2C_FIELD(temp_s1, f32 *, 0xC) = 1.0f;
    var_a6 = 0;
    M2C_FIELD(temp_s6, s32 *, 0x20) = 0x80A7A5A5;
    M2C_FIELD(arg0, s32 *, 0x504) = 0x80A7A5A5;
    struct SubC *subc = (struct SubC *)(arg0 + 12);
    struct Sub4 *sub4 = (struct Sub4 *)(arg0 + 4);
    struct Sub8 *sub8 = (struct Sub8 *)(arg0 + 8);
    int color=0x157529FF;
    var_a5 = (s32 *)(arg0 + 0x100);
    var_a4 = (s32 *)(arg0 + 0xE8);
    var_a3 = arg0 + 0xE2;
    var_a2 = arg0 + 0xDC;
    var_a1 = (s32 *)(arg0 + 0xC4);
    var_a0 = (s32 *)(arg0 + 0xAC);
    do {
        *var_a0 = 0;
        *var_a1 = 0;
        *var_a2 = 0;

        *var_a3 = 0;
        var_v1 = 0xF;
        *var_a4 = 0;
        *var_a5 = color;
        for (int j = 15; j >= 0; j--) {
            sub8->matrix[var_a6][j] = 0;
        }
        var_a6 += 1;
        var_a5++;
        var_a4++;
        var_a3 += 1;
        var_a2 += 1;
        var_a1++;
        var_a0++;
    } while (var_a6 < 6);
    var_s4 = 0;
    ((Header *)arg0)->x10 = (s32) M2C_FIELD(M2C_FIELD(*M2C_FIELD(M2C_FIELD(arg1, void **, 0x60), void ***, 8), void **, 0x18), s32 *, 4);
    var_s3 = 0;
    if (((Group *)arg1)->list->n > 0) {
        var_s2 = sub4->rows;
        var_s1 = arg0 + 0x12E0;
        do {
            temp_s0 = ((Group *)arg1)->list->items[var_s3];
            var_s3 += 1;
            int valid = func_003D8BE8(arg0, temp_s0);
            temp_a1 = var_s1;
            if (valid != 0) {
                *var_s2 = 0;
                var_s2 += 0x80;
                func_00445AE8(temp_s0 + 0x20, temp_a1);
                subc->map[M2C_FIELD(temp_s0, s32 *, 0x3444)] = var_s4;
                var_s4 += 1;
            }
            var_s1 += 0x10;
        } while (var_s3 < ((Group *)arg1)->list->n);
    }
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        temp_v0_2 = (char *)exception__structor_0(0x19C);
        func_00474F38(temp_v0_2, M2C_FIELD(arg0, s32 *, 0), 0, M2C_FIELD(arg0, s32 *, 8));
        M2C_FIELD(arg0, void **, 4) = temp_v0_2;
        M2C_FIELD(temp_v0_2, s32 *, 0x10) = 0;
        func_00475D88(M2C_FIELD(arg0, void **, 4), func_003D7910, arg0);
    }
    func_003D92B0(arg0);
}
