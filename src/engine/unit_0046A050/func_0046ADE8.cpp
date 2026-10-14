/* compiler: ee-gcc2.96-no-strict-aliasing */
struct View { int data,count,pad[2]; };
struct Entry { char pad[0x10]; short id; char pad12[2]; float distance; };
extern "C" void func_00469F08(View *,void *,int);
extern "C" Entry *func_00469FC8(View *,int);
extern "C" float func_0046A0B0(void *);
extern "C" float func_0046A0C8(void *,int *,int *,float,float,float);
extern "C" int func_0046B480(void *,int,int,float,float *,float *,float *,int *,int *);
extern "C" int func_0046BB48(void *,int);
extern "C" float func_0057D118(float,float);
extern "C" int func_0046ADE8(void **self,int kind,int *outId,float *outX,float *outY,float *outZ,float *outAngle,int clamp,float distance) {
 float x0,x1,y0,y1,z0,z1;
 int i,id;
 View view;
 int otherId;
 float length=func_0046A0B0(self);
 int key=func_0046BB48(self,kind);
 if(key==-1) return 0;
 func_00469F08(&view,self,key);
 int count=view.count;
 if(clamp) {
  float min=func_00469FC8(&view,count-1)->distance-length;
  if(distance<min) distance=min;
 }
 int index=count-1;
 while(distance<0.0f) distance+=length;
 while(distance>=length) distance-=length;
 for(i=0;i<count;i++) {
  if(distance<=func_00469FC8(&view,i)->distance) {index=i;break;}
 }
 func_0046B480(self,key,index,distance,&x0,&y0,&z0,0,0);
 func_0046B480(self,key,index,distance+10.0f,&x1,&y1,&z1,0,0);
 short recordId=func_00469FC8(&view,index)->id;
 *outX=x0;*outY=y0;id=recordId;
 *outZ=func_0046A0C8(*self,&id,&i,x0,y0,z0);
 if(i) {
  otherId=-1;
  z0+=1.0f;
  *outZ=func_0046A0C8(*self,&otherId,&i,x0,y0,z0);
  if(i==0) id=otherId;
 }
 *outAngle=func_0057D118(x0-x1,y1-y0);
 *outId=id;
 return 1;
}
