// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mCourseRecord:hObject {void* const data;mCourseRecord(void*) __asm__("func_0015CF58");virtual ~mCourseRecord();};
mCourseRecord::mCourseRecord(void* value):data(value){}
