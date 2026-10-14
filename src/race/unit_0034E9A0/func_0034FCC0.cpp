struct Parameters{char unknown[48];float low,high,quadratic,thresholdLow,thresholdHigh,outputLow,outputHigh,limit;};
extern Parameters D_00843630;
struct Wheel{char unknown0[32];float speed;char unknown24[0x65];unsigned char mode;char unknown8A[0x29];unsigned char active;char unknownB4[56];};
struct Context{char unknown[0x2D4];float values[0];};
struct Self{char unknown[16];Context*context;char unknown14[0x150];Wheel wheels[0];};
struct Selection{unsigned char unknown,count;char unknown2[18];unsigned char entries[0];};
extern "C" int Automobile__getDrawMode(Self*);
extern "C" Selection*func_00359510(Context*);
extern "C" float func_0034FCC0(Self*self,int index,float*out){
 if(Automobile__getDrawMode(self)!=3)return 0.0f;
 Context*context=self->context;Parameters*parameters=&D_00843630;
 Selection*selection=func_00359510(context);Wheel*wheel=&self->wheels[index];
 int enabled=1;
 if(!wheel->active)goto disabled;
 {int mode=wheel->mode;if(mode<0)goto disabled;if(mode<2)goto checked;if(mode>=13){enabled=0;goto checked;}if(mode>=7)goto checked;}
 disabled:enabled=0;
 checked:;
 if(!enabled){*out=parameters->outputLow;return 0.0f;}
 int kind=0;if(index<selection->count)kind=selection->entries[index];
 float value=context->values[kind];
 if(value<0.135f)value=parameters->low;
 else if(value>0.35499998f)value=parameters->high;
 else value=parameters->low+(value-0.135f)*(parameters->high-parameters->low)/0.21999999f;
 float speed=wheel->speed;if(speed<0.0f)speed=-speed;
 float scaled=speed/100.0f;
 scaled=scaled*scaled*parameters->quadratic*value;
 float output;
 if(speed<parameters->thresholdLow)output=parameters->outputLow;
 else if(speed>parameters->thresholdHigh)output=parameters->outputHigh;
 else output=parameters->outputLow+(speed-parameters->thresholdLow)*(parameters->outputHigh-parameters->outputLow)/(parameters->thresholdHigh-parameters->thresholdLow);
 *out=output;
 if(scaled>parameters->limit)scaled=parameters->limit;
 return scaled;
}
