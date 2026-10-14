struct Record {char* text;int width,height,a,b,c,d;};
struct Image {void* pixels;int a,size;int getSize() const{return size;}};
struct Archive {void*data;int count;void*entries;void*vtable;Archive(void*) asm("func_002771C8");~Archive() asm("func_002771F0");};
struct Self {char opaque0[0xA0];int format,index;char opaqueA8[12];void*job;Image image;char opaqueC4[16];void*archiveData;void*owned;};
extern char D_00697120[];
extern "C" int func_00220A08(Record*);
extern "C" void func_001FD618(Self*,int,int);
extern "C" int func_002209B0(Record*,char*,int);
extern "C" void func_001FE558(Self*);
extern "C" int func_00277228(Archive*,Image*,const char*);
extern "C" void free(void*);
extern "C" void* func_00578CB0(int);
extern "C" void func_002771A8(Image*,void*);
extern "C" void func_001FE4E8(Self*,int);
extern "C" int func_001FE200(Self*,const char*,int,int,int);
extern "C" int func_0054EFE8(void*);
extern "C" int func_0054EDA0(void*);
extern "C" int func_004A22C0(int);
struct TextPrefix {int length;char opaque[12];};
inline char* terminate(Record*record){int length=(((TextPrefix*)record->text)-1)->length;if(!length)return D_00697120;record->text[length]=0;return record->text;}
extern "C" void func_001FE2B8(Self*self,Record*record,int wait){
 char path[128];int format;if(record->b)format=record->d?2:1;else format=0;
 int hasFormat=record->a!=0;int flag=record->c==0;self->index=-1;self->format=hasFormat;int width=record->width;int height=func_00220A08(record);func_001FD618(self,width,height);
 if(!func_002209B0(record,path,128))return;
 if(!wait)func_001FE558(self);
 if(self->archiveData){Archive archive(self->archiveData);int found=func_00277228(&archive,&self->image,terminate(record));void*old=self->owned;self->owned=0;if(found){if(old)free(old);old=func_00578CB0(self->image.getSize());func_002771A8(&self->image,old);}else{if(old)free(old);old=0;}self->owned=old;}
 func_001FE4E8(self,1);func_001FE200(self,path,format,flag,0);func_001FE4E8(self,0);
 if(wait){while(!func_0054EFE8(self->job)&&!func_0054EDA0(self->job))func_004A22C0(1);}
}
