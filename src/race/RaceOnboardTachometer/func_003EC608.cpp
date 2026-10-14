/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Builder { char data[0x990]; };
struct V3 { float x,y,z; };
extern "C" int PGLXshapeBuilder__structor_1(Builder *, void *);
extern "C" void PGLXshapeBuilder__structor_2(Builder *, int);
extern "C" void func_004945F0(Builder *, int);
extern "C" void func_00494640(Builder *, int);
extern "C" void func_00494780(Builder *, V3 *, void *, void *, void *);
extern "C" void func_004949A0(Builder *);
extern "C" void *func_00494E50(Builder *, int, int);
extern "C" void func_0057D8A0(float, float *, float *);
extern "C" void func_003EC608(char *self) {
 Builder b;
 V3 v;
 float sine, cosine;
 float radius = *(float *)(self+0x88c);
 if (!(radius <= 0.0f)) {
  float end = *(float *)(self+0x4c);
  float angle = 0.0f;
  float low = *(float *)(self+0x1c);
  float step = 0.0f;
  float start = *(float *)(self+0x48);
  start += (end-start) * (*(float *)(self+0x894)-low) / (*(float *)(self+0x20)-low);
  float span = end-start;
  int count = (int)(span * 36.0f / 360.0f);
  float outer = radius + *(float *)(self+0x890);
  if (end <= start) count = 0;
  else {
   if (count < 2) count = 2;
   angle = start * 0x1.1df468p-6f;
   step = span * 0x1.1df468p-6f / (float)count;
  }
  int next = (*(int *)(self+0x85c)+1)&1;
  *(int *)(self+0x85c) = next;
  PGLXshapeBuilder__structor_1(&b, ((void **)(self+0x864))[next]);
  func_00494640(&b, 0x44);
  func_004945F0(&b, 0);
  v.z = 0.0f;
  if (count > 0) {
   for (int i=0; i<count+1; i++) {
    float current=angle;
    angle += step;
    func_0057D8A0(current, &sine, &cosine);
    float c = cosine;
    float s = sine;
    v.x = c * radius;
    v.y = s * radius;
    c *= outer;
    s *= outer;
    func_00494780(&b, &v, 0, 0, self+0x898);
    v.x = c;
    v.y = s;
    func_00494780(&b, &v, 0, 0, self+0x898);
   }
  }
  func_004949A0(&b);
  *(void **)(self+0x860) = func_00494E50(&b,0,0);
  PGLXshapeBuilder__structor_2(&b,2);
 }
}
