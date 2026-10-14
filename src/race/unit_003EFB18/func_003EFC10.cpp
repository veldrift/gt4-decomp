extern "C" float func_0057D6C0(float,float);
struct S{float low,scale,high;union{int zeroBits;float zeroValue;}zero;float factor,extra;};
extern "C" void func_003EFC10(S* self,float exponent,float factor,float extra,float a,float b){
 self->zero.zeroBits=0;
 self->factor=1.0f-factor*0.1f;
 self->extra=extra;
 float scale;
 if(exponent==self->zero.zeroValue)scale=1.0f;else scale=func_0057D6C0(2.0f,exponent);
 float spread=(a-b)*0.2f/2000.0f;
 self->scale=scale;
 self->low=scale*(1.0f-spread);
 self->high=scale*(1.0f+spread);
}
