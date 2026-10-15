/* compiler: ee-gcc2.96-nogcse */
struct Table { int data,bytes; };
struct Database { int unknown,language; char directory[0x12c]; Table *tables[43]; int unknown1E0; Table *finalTable; };
extern char *D_00623580[], *D_006234B0[];
extern signed char D_00623798[];
extern char D_006A6D20[],D_006A6D28[],D_006A6D30[];
extern "C" int func_0057F238(const char*,const char*);
extern "C" char *func_005A609C(char*,const char*);
extern "C" char *func_005A5DC8(char*,const char*);
extern "C" int func_00443DC0(Database*,int);
extern "C" int func_00449070(Table*,const char*,int,int);
extern "C" int func_004498E8(Table*,const char*,int,int);
extern "C" int func_00449C58(Table*,const char*,int,int);
static inline int languageIndex(const char *language) {
 int selected=-1; const char **list=(const char **)D_00623580;
 for(int i=0;i<9;++i) { if(func_0057F238(language,*list++)==0) {selected=i;break;} }
 if(selected==-1)selected=0;return selected;
}
extern "C" void func_00443518(Database *self,const char *language) {
 int selected=languageIndex(language);
 if(self->language==selected)return;
 self->language=selected;
 char path[256]; char *directory=self->directory;
 char **primaryNames=D_006234B0; for(int i=0;i<43;++i,++primaryNames) if(func_00443DC0(self,i)) {
  func_005A609C(path,directory);func_005A5DC8(path,*primaryNames);func_005A5DC8(path,D_00623580[self->language]);func_005A5DC8(path,D_006A6D20);
  Table *table=self->tables[i];func_00449070(table,path,table->data,table->bytes);
 }
 signed char *list=D_00623798;
 if(*list!=43) { char *secondaryDirectory=directory; char **fileNames=D_006234B0; char **languageNames=D_00623580;
  do { int index=*list++; int offset=index*4;
   if(func_00443DC0(self,index)) {
    func_005A609C(path,secondaryDirectory);func_005A5DC8(path,*(char**)((char*)fileNames+offset));func_005A5DC8(path,languageNames[self->language]);func_005A5DC8(path,D_006A6D28);
    Table *table=*(Table**)(secondaryDirectory+0x80+offset);func_004498E8(table,path,table->data,table->bytes);
   }
  }while(*list!=43);
 }

 func_005A609C(path,directory);char **names=D_00623580;int offset=self->language*4;
 func_005A5DC8(path,*(char**)((char*)names+offset));func_005A5DC8(path,D_006A6D30);
 Table *table=self->finalTable;func_00449C58(table,path,table->data,table->bytes);
}
