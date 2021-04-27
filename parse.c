#include <stdio.h>
#include <string.h>


int main(){
  char *str= "danu,an";
//   printf("%d", strlen(data));
  char partial[9];
  int lock = 0;
  int count = 0;
  int memory = 0;

  size_t len = strlen(partial);

char joint[10]="";
char value[10]="";

for(int i=0; i <strlen(str);i++){ 


    printf("%d \n", lock);
    if(str[i] == ','){
        lock =1;
    }

    if(lock == 0){
        if (count == 0 )
            joint[i] = str[i]; 
        if (count == 1 )
            value[i-memory] = str[i]; 
    }
    if(lock==1){
        count ++;
        lock = 0;
        memory = i+1;
    }
}

  printf("%s \n", joint);
  printf("%s \n", value);
  printf("%d \n", memory);

  

}
