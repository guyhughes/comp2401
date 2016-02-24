#define MAX_STR  32

typedef struct {
   char first[MAX_STR];
   char last[MAX_STR];
   int age;
} PersonType;

typedef struct {
   PersonType basicInfo;
   char stuNumber[MAX_STR];
   float gpa;
} StudentType;

void initStudent ( char*, char*, int, char*, float, StudentType** );
void printStudent ( const StudentType* );
void cleanupStudent ( StudentType* );

