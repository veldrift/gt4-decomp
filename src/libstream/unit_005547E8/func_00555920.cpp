
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int s128;
typedef unsigned int u128;
void *memcpy(void *, const void *, unsigned int);
s32 func_00561040(s32, void *, void *);
s32 func_005A48D8(void *, s32, s32);
struct func_00555920_temp_s0
{
  s8 unk0;
  char pad1[0x3];
  s32 unk4;
  s32 unk8;
  s32 unkC;
  s32 unk10;
};
struct func_00555920_temp_s1
{
  s32 unk0;
};
void func_00555920(s32 arg0, s32 arg1)
{
  struct func_00555920_temp_s0 *temp_s0;
  char *temp_s1;
  s32 k;
  temp_s1 = ((char *) arg0) + (arg1 * 0x114);
  temp_s0 = (struct func_00555920_temp_s0 *) (temp_s1 + 0x4C);
  func_005A48D8((void *) temp_s0, 0, 0x3C);
  temp_s0->unk0 = 0;
  k = 0x5A;
  temp_s0->unk4 = -1;
  temp_s0->unk10 = k;
  temp_s0->unk8 = 0;
  temp_s0->unkC = 0;
  func_00561040(((struct func_00555920_temp_s1 *) temp_s1)->unk0, (void *) (temp_s1 + 0x88), (void *) temp_s0);
}
