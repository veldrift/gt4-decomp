struct Owner;struct Car;struct Contact;
struct Drive {unsigned char unknown0[0x461];unsigned char reverse;unsigned char unknown462[4];signed char mode;unsigned char engaged;unsigned char unknown468[0x3c];float position;unsigned char unknown4a8[9];unsigned char flags;unsigned char blocked;unsigned char unknown4b3[0x89];float vx,vy;};
struct Car {unsigned char unknown0[0x104];Drive drive;unsigned char unknown648[0x354];float position;};
extern "C" Car*func_0034C190(Owner*,int);
extern "C" int func_0034C210(Owner*);
extern "C" int func_00358608(Owner*,int,float);
extern "C" int func_0045CC08(Contact*);
extern "C" void func_0035ACD8(Car*,int);
extern "C" void func_0035B060(Car*,float,float);
inline float root(float v){float r;asm("sqrt.s %0,%1":"=f"(r):"f"(v));return r;}
extern "C" void func_00359008(Owner*self,int index){
 if(((unsigned char*)self)[0xcbde]==2)return;
 Drive*d=&func_0034C190(self,index)->drive;
 float position=func_0034C190(self,index)->position;
 if(func_0034C210(self))return;
 if(func_00358608(self,index,position)==1){
  float speed=root(d->vx*d->vx+d->vy*d->vy);
  d->flags|=1;
  if(speed>1.38888871669769287109375f){
   Contact*contact=(Contact*)((char*)self+0xda78+index*1264);
   if(!func_0045CC08(contact)&&(unsigned)((unsigned char)d->mode-1)>=2&&!d->engaged)func_0035ACD8(func_0034C190(self,index),1);
  }else if(speed<0.8333332538604736328125f)func_0035ACD8(func_0034C190(self,index),0);
 }else{d->flags&=0xfe;func_0035ACD8(func_0034C190(self,index),0);}
 if(d->engaged==1&&(d->mode==0||d->mode==3)&&!d->blocked){
  if(d->reverse)func_0035ACD8(func_0034C190(self,index),5);
  else func_0035ACD8(func_0034C190(self,index),4);
 }
 return func_0035B060(func_0034C190(self,index),d->position,position);
}
