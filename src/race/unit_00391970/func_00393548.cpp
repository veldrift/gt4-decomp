/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Settings { char pad[0x38D18]; int volume; };
extern Settings *D_00622F4C;
extern "C" int SystemSoundGetOutputMode(void);
extern "C" float SystemSoundGetOutputModeVolume(int,int);
extern "C" void func_00463378(void *,void *,unsigned int,float,float);
extern "C" void func_00393548(void *a,void *b,float x,float y) {
 float v=x*((float)D_00622F4C->volume * 0.0078125f);
 func_00463378(a,b,0x7FFFFFFF,v*SystemSoundGetOutputModeVolume(SystemSoundGetOutputMode(),3),y);
}
