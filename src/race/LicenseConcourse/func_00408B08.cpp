/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 {float x,y,z;};
struct Geo {char pad[0x20];};
struct Self {char pad[0x18];int valid;char gap[0x10];V3 v;float f;};
extern "C" {
float func_00344AA8(void*,int,float);
float func_00344C08(void*,int,float);
void CarGeometry__structor_0(Geo*,void*,int);
int func_0038DC18(Geo*);
float CarGeometry__GetSeatPosition_X(Geo*,float);
float CarGeometry__GetSeatPosition_Z(Geo*,float);
float CarGeometry__GetShiftPosition_X(Geo*,float);
void func_004081B8(Self*,int,int,V3*,V3*,float,float) throw();
float func_0057D118(float,float);
}
extern "C" void func_00408B08(Self *self,int mode,int n,void *obj){
 V3 pos;Geo geo;V3 diff;
 Geo *g=&geo;
 CarGeometry__structor_0(g,obj,0);
 float x,z;float angle=0;
 if(func_0038DC18(g)==0){self->valid=0;return;}
 float seat=CarGeometry__GetSeatPosition_X(g,angle);
 angle=CarGeometry__GetShiftPosition_X(g,angle);int side=0;if(!(seat<angle))side=1;

 switch(mode){
 case 0:
 if(side==0){angle=0x1.91eb84p+0f;seat=0;x=func_00344AA8(obj,0,seat)-0.5f;z=CarGeometry__GetSeatPosition_Z(g,seat);pos.y=seat;pos.z=z;pos.x=x;}
 else{angle=-0x1.91eb84p+0f;seat=0;x=func_00344AA8(obj,1,seat)+0.5f;z=CarGeometry__GetSeatPosition_Z(g,seat);pos.y=seat;pos.z=z;pos.x=x;}
 break;
 case 1:
 if(side==0){seat=0;x=func_00344AA8(obj,0,seat)-0.75f;z=CarGeometry__GetSeatPosition_Z(g,seat);pos.y=seat;pos.x=x;pos.z=z+1.0f;}
 else{seat=0;x=func_00344AA8(obj,1,seat)+0.75f;z=CarGeometry__GetSeatPosition_Z(g,seat);pos.y=seat;pos.x=x;pos.z=z+1.0f;}
 diff.x=pos.x-CarGeometry__GetSeatPosition_X(g,0);
 diff.z=pos.z-CarGeometry__GetSeatPosition_Z(g,0);
 angle=func_0057D118(-diff.x,-diff.z);
 break;
 case 2:
 default:
 if(side==0){seat=0;x=func_00344AA8(obj,1,seat)+0.75f;z=func_00344C08(obj,1,seat);pos.y=seat;pos.z=z;pos.x=x;}
 else{seat=0;x=func_00344AA8(obj,0,seat)-0.75f;z=func_00344C08(obj,0,seat);pos.y=seat;pos.z=z;pos.x=x;}
 diff.x=pos.x-CarGeometry__GetSeatPosition_X(g,0);
 diff.z=pos.z-CarGeometry__GetSeatPosition_Z(g,0);
 angle=func_0057D118(-diff.x,-diff.z);
 break;
 }
 func_004081B8(self,mode,n,&pos,&self->v,angle,self->f);
}
