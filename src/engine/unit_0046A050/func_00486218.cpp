
extern int func_00486090(int lo, int hi, const float *keys, float t);
inline int inline_fn()
{
  return ~3;
}

extern void func_00486218(float *keys, int arg1, float *out0, float *out1, float fparg0)
{
  float third = 0x1.555554p-2f;
  float x = fparg0;
  int idx = func_00486090(0, arg1 & inline_fn(), keys, fparg0);
  const float *q = keys + idx;
  float p0 = *q;
  q++;
  float p1 = *q;
  q++;
  float p2 = *q;
  q++;
  float p3 = *q;
  q++;
  float c2 = p2 * 0x1.8p+1f;
  float p5 = q[1];
  float c3 = p3 * 0x1.8p+1f;
  float d1 = x - p0;
  float p4 = q[0];
  float c1 = p1 * 0x1.8p+1f;
  float d2 = p4 - p0;
  float t = d1 / d2;
  float u = ((c2 - p1) - c3) + q[1];
  float v = (c1 - (c2 + c2)) + c3;
  float w = c2 - c1;
  *out0 = u;
  *out1 = u * 0x1.8p+1f;
  *out0 = (*out0) * t;
  *out1 = (*out1) * t;
  *out0 = (*out0) + v;
  *out1 = (*out1) + (v + v);
  *out0 = (*out0) * t;
  *out1 = (*out1) * t;
  *out0 = (*out0) + w;
  *out1 = (*out1) + w;
  *out0 = (*out0) * t;
  *out1 = (*out1) * third;
  *out0 = (*out0) + p1;
}
