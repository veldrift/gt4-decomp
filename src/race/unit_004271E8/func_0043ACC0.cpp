typedef unsigned long long U64;
struct Record { char data[0x238]; };
struct Header { Header() __asm__("func_004338F8"); void* table; Record* data; int count; int unknown; };
struct Base { Base() __asm__("func_0043A3F8"); void* table; };
inline void* operator new(unsigned int,void* p) { return p; }
extern char D_00687E90[], D_00687F10[], D_00687ED0[];
extern "C" {

void func_0042EF90(void*);
void func_004351A8(void*);
void func_00430CB8(void*);

void func_00432368(void*);
void func_0042E8D8(void*);
void func_00430320(void*);
void func_00439D18(void*);
void func_0042F820(void*);
void func_0043B598(void*);
void func_00432E28(Record*);
void func_00433930(Header*,Record*,int);
void func_00433998(Header*,Record*,int,int);
void func_00430398(void*,int);
void func_0043AF88(void*,int);
void* func_005A48D8(void*,int,unsigned);
}
extern "C" void func_0043ACC0(char* self) {
 Header* first=(Header*)(self+0x146E8);
 Record* p=(Record*)(self+0x146F8);
 int n=127;
 new(self) Base;
 *(void**)self=D_00687E90;
 func_0042EF90(self+0x220);
 func_004351A8(self+0xB8E8);
 func_00430CB8(self+0x13AE0);
 new(first) Header;
 first->table=D_00687F10;
 do { Record* current=p++; --n; func_00432E28(current); } while(n!=-1);
 func_00433930(first,(Record*)(first+1),128);
 Header* second=(Header*)(self+0x262F8);
 new(second) Header;
 second->table=D_00687ED0;
 Record* small=(Record*)(self+0x26308);
 p=small;n=3;
 do { Record* current=p++; --n; func_00432E28(current); } while(n!=-1);
 char* left=self+0x38618;
 func_00433930(second,(Record*)(second+1),4);
 func_00432368(self+0x26BE8);
 func_0042E8D8(self+0x36208);
 char* right=self+0x38728;
 func_00430320(left);
 func_00430320(right);
 func_00439D18(self+0x38838);
 func_0042F820(self+0x388B0);
 func_0043B598(self+0x38940);
 self[8]=0;self[0x28]=0;self[0x30]=0;
 *(U64*)(self+0x40)=0;*(U64*)(self+0x48)=0;
 *(int*)(self+0x50)=0;
 *(int*)(self+0x54)=0;
 *(int*)(self+0x58)=0;
 *(int*)(self+0x5C)=0;
 *(int*)(self+0x60)=0;
 *(int*)(self+0x64)=0;
 *(int*)(self+0x68)=0;
 *(int*)(self+0x6C)=0;
 *(U64*)(self+0x70)=0;*(U64*)(self+0x78)=0;
 *(int*)(self+0x80)=0;*(int*)(self+0x84)=0;self[0x88]=0;
 func_005A48D8(self+0x9C,0,0x180);
 func_00433998((Header*)(self+0x262F8),small,4,2);
 func_00430398(left,30);func_00430398(right,30);
 return func_0043AF88(self,0);
}
