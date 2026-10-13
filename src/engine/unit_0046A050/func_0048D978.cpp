
typedef float f32;
struct func_0048D978_arg0
{
  f32 unk0;
  f32 unk4;
  f32 unk8;
  f32 unkC;
  f32 unk10;
  f32 unk14;
  f32 unk18;
  f32 unk1C;
  f32 unk20;
};
extern void func_0048D978(struct func_0048D978_arg0 *arg0, f32 fparg0)
{
  f32 t0 = arg0->unk0;
  f32 t4 = arg0->unk4;
  f32 t8 = arg0->unk8;
  f32 tC = arg0->unkC;
  f32 t10 = arg0->unk10;
  f32 t14 = arg0->unk14;
  f32 t18 = arg0->unk18;
  f32 t1C = arg0->unk1C;
  f32 t20 = arg0->unk20;
  arg0->unk4 = (f32) (t4 / fparg0);
  arg0->unk20 = (f32) (t20 / fparg0);
  arg0->unk8 = (f32) (t8 / fparg0);
  arg0->unkC = (f32) (tC / fparg0);
  arg0->unk10 = (f32) (t10 / fparg0);
  arg0->unk14 = (f32) (t14 / fparg0);
  arg0->unk18 = (f32) (t18 / fparg0);
  arg0->unk1C = (f32) (t1C / fparg0);
  arg0->unk0 = (f32) (t0 / fparg0);
}
