struct Text {long head;char eighth,ninth;} __attribute__((packed));
extern "C" Text D_006A4F70;
extern "C" const char D_006A4F80[],D_006A4F98[];
extern "C" int func_005A5A30(char*,unsigned,const char*,...);
extern "C" void GranTurismo4__GetTimeString(unsigned time,char*out,unsigned capacity){if(time==0x157529ff){*(Text*)out=D_006A4F70;return;}unsigned milliseconds=time%1000;unsigned seconds=time/1000;unsigned second=seconds%60;unsigned minutes=seconds/60;unsigned minute=minutes%60;int hours=minutes/60;if(hours>0){func_005A5A30(out,capacity,D_006A4F80,hours,minute,second,milliseconds);return;}func_005A5A30(out,capacity,D_006A4F98,minute,second,milliseconds);}
