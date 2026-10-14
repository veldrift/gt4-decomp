
typedef int s32;
typedef unsigned int u32;
extern void func_0038B8D8(void *self, void *val);
extern void RaceTrainingBase__initialize(void *b, s32 x);
extern void func_003DF970(void *arg0, s32 arg1);
extern void RaceDisplay__virtual_06(void *arg0, s32 arg1);
inline static void reset_call(void *s)
{
  func_0038B8D8(s, 0);
}

extern void RaceMission__initialize(void *arg0, s32 arg1)
{
  char *self = (char *) arg0;
  void *new_var;
  char *t0;
  char *t2;
  t0 = self + 0x22778;
  t2 = self + 0xE440;
  reset_call(arg0);
  new_var = arg0;
  RaceTrainingBase__initialize(new_var, arg1);
  if (((u32) ((*((s32 *) (self + 0xCC8))) - 2)) < 2U)
  {
    reset_call(arg0);
  }
  else
  {
    func_0038B8D8(arg0, t0);
    func_003DF970(t0, (s32) (self + 0x22748));
  }
  RaceDisplay__virtual_06(t2, 1);
  *((s32 *) (t2 + 8)) = (s32) (self + 0x22748);
}
