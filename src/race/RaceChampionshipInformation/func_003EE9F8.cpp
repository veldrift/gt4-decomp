struct ShowRoomCar {void *data;bool state;ShowRoomCar() __asm__("func_00364760");virtual ~ShowRoomCar() __asm__("func_003647A0");};
union Scalar {int integer;float real;};
struct Config {char bytes[32];};struct Entry;struct Directory {int unknown[2];Entry **entries;};struct Input {char unknown[96];Directory *directory;};struct Slot {int index;char unknown[388];};struct Owner {char unknown[764];int count;char unknown300[388];Slot slots[5];};
extern "C" void *func_005C15B0(unsigned);extern "C" void func_005C1628(void*);extern "C" void func_00343490(Config*);extern "C" void func_00364868(ShowRoomCar*,const void*,const Config*);extern "C" int func_00364FA8(ShowRoomCar*,int);extern "C" int func_00364E90(ShowRoomCar*,int*,int,int);extern "C" void func_003EE7C0(Owner*,Input*);
extern "C" void func_003EE9F8(Owner*self,Input*input){
 int i=0;self->count=5;Scalar *ranks=(Scalar*)func_005C15B0(24);Scalar *used=(Scalar*)func_005C15B0(24);Scalar *ratios=(Scalar*)func_005C15B0(24);
 for(;i<6;++i){used[i].integer=0;ranks[i].integer=0;ratios[i].integer=0;}
 for(i=0;i<6;++i){ShowRoomCar car;Config config;func_00343490(&config);func_00364868(&car,(char*)input->directory->entries[i]+32,&config);int mass=func_00364FA8(&car,0x6B67);int extra;int power=func_00364E90(&car,&extra,0x7073,0);ratios[i].real=(float)(mass/power);}
 for(i=1;i<6;++i){for(int j=i+1;j<6;++j){if(ratios[i].real!=ratios[j].real){if(ratios[i].real>ratios[j].real)++ranks[i].integer;else ++ranks[j].integer;}}}
 int marker=1;Slot *slot=self->slots;Scalar *rank=ranks+1;i=4;
 do{int selection=rank->integer;if(used[selection].integer==marker){do{++selection;}while(used[selection].integer==1);}slot->index=selection;++slot;used[selection].integer=marker;++rank;}while(--i>=0);
 func_005C1628(ranks);func_005C1628(used);func_005C1628(ratios);func_003EE7C0(self,input);
}
