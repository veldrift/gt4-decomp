struct TunerCodes { unsigned long first; unsigned short last; }; extern "C" int func_004478B8(unsigned long,TunerCodes*) throw();
extern "C" int func_004478F8(unsigned long identifier,int *output,int capacity) {
 if(!output)return 0; TunerCodes row; if(!func_004478B8(identifier,&row))return 0;
 TunerCodes codes; codes.first=row.first; codes.last=row.last;
 const unsigned char *names=(const unsigned char *)&codes; int count=0;
 const unsigned char *end=names+10;
 int *cursor=output;
 while(names!=end && count<capacity && *names) {
   *cursor++=*names++; ++count;
 }
 return count;
}
