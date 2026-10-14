typedef unsigned long long U64;
struct Car { U64 key;char unknown8[0x58];int index;Car() __asm__("func_00430750");~Car() __asm__("func_004307A0"); };
struct Info { char unknown0[0x110];U64 metadata;char unknown118[8];int option;char unknown124[0x98c];U64 courseKey;int selected;Info() __asm__("func_00338658");~Info() __asm__("func_003386A0"); };
struct Entry {short delta,unknown;void(*call)(void*,int);};
struct Course {char unknown0[0x974];Entry*table;};
struct Battle { char unknown0[0x64];Entry*table;int unknown68;Course*course;char unknown70[0xC70];int state;char unknownCE4[0x21f9c];Battle() __asm__("func_003389F0"); };
inline void*operator new(unsigned int,void*p){return p;}
extern "C" char D_00645570[0],D_0068D070[],D_0068D068[];
extern "C" char* D_00622F4C;
extern "C" void func_0044CA98(int,int,int,int),func_0044CB10();
extern "C" int func_00430830(void*);
extern "C" void RaceNetBattleInformation__virtual_20(Info*,void*),RaceNetBattleInformation__virtual_03(Info*,U64);
extern "C" U64 func_00447C78(const char*);
extern "C" int func_00329858(int*,const char*);
extern "C" int func_004F9E60(void*,int),func_004F9EC0(void*,int);
extern "C" void*func_004F9F18(void*,int);
extern "C" void func_0010CFB8(Car*,void*),func_005C2A10(Info*,int,const Car*);
extern "C" Course*func_003B7850(Info*);
extern "C" void*exception__structor_0(unsigned);
extern "C" void func_0010AF40(int),func_0010CEB8() throw(),func_0042FC10(void*,const char*),func_0010D8F0(Course*,int,int);
inline void callEntry(void*p,Entry*entry,int arg){entry->call((char*)p+entry->delta,arg);}
extern "C" void func_0010D2E0() {
 char*settings=D_00645570;
 func_0044CA98(0x30000,2,6,0xBC8000);
 {
 Info info;
 func_00430830(D_00622F4C+0xD8);
 RaceNetBattleInformation__virtual_20(&info,D_00622F4C+0x44);
 RaceNetBattleInformation__virtual_03(&info,func_00447C78(settings+0xF78));
 int option;
 if(func_00329858(&option,D_0068D070))info.option=option;
 int count=*(int*)(settings+0xEE0);
 int selection=func_004F9EC0(settings,func_004F9E60(settings,*(int*)(settings+0xCC4)));
 info.selected=selection;
 for(int i=0;i<count;++i) {
  void*record=func_004F9F18(D_00645570,i);
  Car car;
  func_0010CFB8(&car,record);
  func_005C2A10(&info,i,&car);
 }
 Course*course=func_003B7850(&info);
 Battle*battle=new(exception__structor_0(0x22C80))Battle;
 battle->course=course;
 callEntry(battle,battle->table+0x328/8,0);
 int state=battle->state;
 if(battle)callEntry(battle,battle->table+1,3);
 func_0010AF40(0);
 if(state==7){func_0010CEB8();func_0042FC10(D_00622F4C+0x3A368,D_0068D068);}
 else func_0010D8F0(course,selection,state);
 if(course)callEntry(course,course->table+1,3);
 }
 func_0044CB10();
}
