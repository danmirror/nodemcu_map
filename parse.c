#include <stdio.h>
#include <string.h>


int main(){
  char *data= "danu,an";
  printf("%d", strlen(data));
  char partial[9];

  size_t len = strlen(partial);

  for(int i=0; i <strlen(data);i++){
    partial[len++] = data[i]; 


    // partial[i]= data[i];
   
    
  }

  // char res[10];
  // size_t len = strlen(res);
  // res[1] = 'A'; /* we overwriting the null-character with another one */
  // // res[12] = 'B'; 
  // res[len] = '\0'; /* to make the string null-terminated again */

  // // partial[0] = 'a';
  // //  partial[1] = '\0';
  // // partial = partial+"b";
  printf("%s", partial);

  

}