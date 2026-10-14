struct S { char matrix[80]; float angle,offset,x,y,z; };
extern "C" void func_004A53F8(); extern "C" void func_004A5400();
extern "C" void func_004A7454(); extern "C" void func_004A74A0();
extern "C" void func_004A7550(void*); extern "C" void func_004A7698(void*);
extern "C" void func_004A7844(float,float,float);
extern "C" void func_004A7988(float); extern "C" void func_004A79B0(float);
extern "C" void func_0044EF18(S* s,float x,float y,float z) {
 void* m=s->matrix+16;
 s->y=y;s->z=z;s->x=x;
 func_004A53F8();func_004A7550(m);func_004A7454();func_004A7988(-s->angle);func_004A79B0(180.0f);
 func_004A7698(m);func_004A74A0();func_004A7844(-s->x,-s->y,-s->z);func_004A7844(0.0f,-s->offset,0.0f);
 func_004A7550(m);func_004A5400();
}
