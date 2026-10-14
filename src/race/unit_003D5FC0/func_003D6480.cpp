struct Vec {float x,y,z,w;}; struct Mat {float m[16];};
struct Object {int unknown[2];virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void apply(float); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void bounds(Vec*,void*);};
struct Owner {int unknown;Mat saved;};
extern "C" void RaceEntryCar__update(int);extern "C" void func_004A53F8();extern "C" void func_004A7454();extern "C" void func_004A7A54();extern "C" void func_004A7550(Mat*);extern "C" void func_004A7AA8(Vec*,const Vec*);extern "C" void func_004A7988(float);extern "C" void func_004A74B4(const Mat*);extern "C" void func_004A7774(const Mat*);extern "C" void func_004A7698(const Mat*);extern "C" void func_004A5400();extern "C" void func_003D6700(Owner*,Object*,float);
extern "C" void func_003D6480(Owner*self,const Vec*direction,Object*object,float amount){
 Mat old;Vec transformed,source;
 RaceEntryCar__update(0);func_004A53F8();func_004A7454();
 object->apply(amount);
 func_004A7A54();func_004A7550(&old);
 source.x=direction->x;source.y=direction->y;source.z=direction->z;source.w=0;
 func_004A7AA8(&transformed,&source);
 Mat rotation;
 if(transformed.x==0 && transformed.z==0){func_004A7454();func_004A7988(90.0f);}
 else{
  float x=transformed.x,y=transformed.y,z=transformed.z;
  rotation.m[0]=z;
  rotation.m[4]=0;
  rotation.m[8]=-x;
  rotation.m[12]=0;
  rotation.m[1]=-x*y;
  rotation.m[5]=z*z-(-x*x);
  rotation.m[9]=-z*y;
  rotation.m[13]=0;
  rotation.m[2]=0;
  rotation.m[6]=0;
  rotation.m[10]=0;
  rotation.m[14]=0;
  rotation.m[3]=0;
  rotation.m[7]=0;
  rotation.m[11]=0;
  rotation.m[15]=1;
  func_004A74B4(&rotation);
 }
 object->bounds(&source,&rotation);
 Mat projection;float ix=1.0f/(rotation.m[0]-source.x),iy=1.0f/(rotation.m[1]-source.y);
 projection.m[0]=ix*0.98f;projection.m[1]=0;projection.m[2]=0;projection.m[3]=0;projection.m[4]=0;projection.m[5]=iy*0.98f;projection.m[6]=0;projection.m[7]=0;projection.m[8]=0;projection.m[9]=0;projection.m[10]=0;projection.m[11]=0;projection.m[12]=-(ix*source.x)*0.98f+0.01f;projection.m[13]=-(iy*source.y)*0.98f+0.01f;projection.m[14]=0;projection.m[15]=1;
 func_004A7774(&projection);func_003D6700(self,object,amount);func_004A7698(&old);func_004A7550(&self->saved);func_004A5400();
}