/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Factors { float v[4]; };
struct Geo { char pad[0x20]; };
struct Data { char pad[0xE0]; unsigned char v[4]; };
struct Out { char pad[0x10]; float x0,x1,z0,z1,y0,y1,y2,y3; };
extern Factors D_006A4530;
extern "C" void CarGeometry__structor_0(Geo *,void *,int);
extern "C" int func_0038DC00(Geo *);
extern "C" unsigned char *func_00359538(void *);
extern "C" float func_00344AA8(void *,int,float);
extern "C" float func_00344C08(void *,int,float);
extern "C" float func_00344C88(void *,int);
extern "C" float func_00344CE8(void *,int);
extern "C" void func_0040BAB0(Out *o,void *a) {
 Factors f=D_006A4530;
 Geo geo;
 CarGeometry__structor_0(&geo,a,0);
 int p=func_0038DC00(&geo);
 if(p) {
 unsigned char *cp=(unsigned char *)(p+0xE0);
 for(int i=0;i<4;i++,cp++) {
  if(*cp) f.v[i]=(float)*cp/255.0f; else f.v[i]=0x1.b1b1b0p-1f;
 }
 }
 switch(*func_00359538(a)) {
 case 1:
  { float t=func_00344AA8(a,0,0);o->x0=o->x1=t;
  }
  { float t=func_00344AA8(a,2,0);o->z0=o->z1=t;
  }
  { float t=func_00344C08(a,0,0);
  float result=t*f.v[1]+func_00344C88(a,0)+0x1.ae1476p-6f;
  o->y0=o->y1=result;
  }
  { float t=func_00344C08(a,2,0);
  float result=t*f.v[3]-func_00344C88(a,2)-0x1.ae1476p-6f;
  o->y2=o->y3=result;
  }
  break;
 case 2:
  { float t=func_00344AA8(a,0,0);o->x0=o->x1=t;
  }
  { float t=func_00344AA8(a,1,0);
  o->z0=t*f.v[2]+func_00344CE8(a,1)*0.5f+0x1.ae1476p-6f;
  }
  { float t=func_00344AA8(a,2,0);
  o->z1=t*f.v[2]-func_00344CE8(a,2)*0.5f-0x1.ae1476p-6f;
  }
  { float t=func_00344C08(a,0,0);
  float result=t*f.v[1]+func_00344C88(a,0)+0x1.ae1476p-6f;
  o->y0=o->y1=result;
  }
  o->y2=func_00344C08(a,1,0)*f.v[3];
  o->y3=func_00344C08(a,2,0)*f.v[3];
  break;
 case 3:
  { float t=func_00344AA8(a,0,0);
  o->x0=t*f.v[0]+func_00344CE8(a,0)*0.5f+0x1.ae1476p-6f;
  }
  { float t=func_00344AA8(a,1,0);
  o->x1=t*f.v[0]-func_00344CE8(a,1)*0.5f-0x1.ae1476p-6f;
  }
  { float t=func_00344AA8(a,2,0);o->z0=o->z1=t;
  }
  o->y0=func_00344C08(a,0,0)*f.v[1];
  o->y1=func_00344C08(a,1,0)*f.v[1];
  { float t=func_00344C08(a,2,0);
  float result=t*f.v[3]-func_00344C88(a,2)-0x1.ae1476p-6f;
  o->y2=o->y3=result;
  }
  break;
 case 0:
 default:
  { float t=func_00344AA8(a,0,0);
  o->x0=t*f.v[0]+func_00344CE8(a,0)*0.5f+0x1.ae1476p-6f;
  }
  { float t=func_00344AA8(a,1,0);
  o->x1=t*f.v[0]-func_00344CE8(a,1)*0.5f-0x1.ae1476p-6f;
  }
  { float t=func_00344AA8(a,2,0);
  o->z0=t*f.v[2]+func_00344CE8(a,2)*0.5f+0x1.ae1476p-6f;
  }
  { float t=func_00344AA8(a,3,0);
  o->z1=t*f.v[2]-func_00344CE8(a,3)*0.5f-0x1.ae1476p-6f;
  }
  o->y0=func_00344C08(a,0,0)*f.v[1];
  o->y1=func_00344C08(a,1,0)*f.v[1];
  o->y2=func_00344C08(a,2,0)*f.v[3];
  o->y3=func_00344C08(a,3,0)*f.v[3];
  break;
 }
}
