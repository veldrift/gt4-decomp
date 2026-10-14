extern char D_006235A8[];
struct Packed{long a,b;} __attribute__((packed));
extern "C" void SPEC_DATABASE__DisabledInfo__searchInfo(long);
extern "C" int SPEC_DATABASE__DatabaseStorage__getRow_2(void*,int,int,void*);
extern "C" int SPEC_DATABASE__GetCarNameInfo(long index,Packed* output){SPEC_DATABASE__DisabledInfo__searchInfo(index);Packed value;if(!SPEC_DATABASE__DatabaseStorage__getRow_2(D_006235A8,(int)index,39,&value))return 0;*output=value;return 1;}
