struct Self{int flags;float angle,x,y,z;};
struct Vec3{float x,y,z;}; struct Vec4{float x,y,z,w;};
extern "C" void func_004A0690();extern "C" void func_004A06F0();
extern "C" void func_004A53F8();extern "C" void func_004A5400();
extern "C" void func_004A7454();extern "C" void func_004A7844(float,float,float);
extern "C" void func_004A79B0(float);extern "C" void func_004A79D8(float);extern "C" void func_004A7988(float);extern "C" void func_004A7A54();
extern "C" void func_004A7AA8(Vec4*,const Vec4*);
extern "C" float func_00344888(void*,float);extern "C" float func_00344858(void*,float);extern "C" float func_003448B8(void*,float);
extern "C" float func_00344798(void*,float);extern "C" float func_003447F8(void*,float);extern "C" float func_00344828(void*,float);
extern "C" void func_003FCEA8(Self*self,Vec3*position,void*other,float time){
 float &py=position->y;float &pz=position->z;
 func_004A0690();func_004A53F8();func_004A7454();
 func_004A7844(-self->x,-self->y,-self->z);func_004A79B0(self->angle);
 func_004A7844(-position->x,-py,-pz);
 if((self->flags>>2)&1)func_004A79D8(func_00344888(other,time)*57.2957763671875f);
 if(self->flags&1)func_004A7988(-func_00344858(other,time)*57.2957763671875f);
 if((self->flags>>1)&1)func_004A79B0(-func_003448B8(other,time)*57.2957763671875f);
 float x=-func_00344798(other,time);float y=-func_003447F8(other,time);float z=-func_00344828(other,time);
 func_004A7844(x,y,z);func_004A7A54();
 Vec4 v;float &vy=v.y;float &vz=v.z;v.x=vy=vz=0.0f;v.w=1.0f;
 func_004A7AA8(&v,&v);
 position->x=v.x;py=vy;pz=vz;
 func_004A5400();func_004A06F0();
}
