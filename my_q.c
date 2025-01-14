#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
int areAlmostEqual(char* s1, char* s2) {
   int i=0;
    int j=0;
    int count=0;
    int idx1 = -1;
    int idx2 = -1;
    while(s1[i] != '\0')
    {
        if(s1[i] != s2[j])
        {
            count++;
            if(idx1 == -1)
            {
                idx1 = i;
            }
            else
            {
                idx2 = i;
            }
        }
        i++;
        j++;
    }

    if(count == 0)
    {
        return 1;
    }
    else if(count == 2 && (s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1]))
    {
        return 1;
    }
    return 0;
}
int main() {
   char *s1 = (char *)malloc(20*sizeof(char));
   char *s2 = (char *)malloc(20*sizeof(char));
 
   printf("Enter the first string: ");
   scanf("%s", s1);
   printf("Enter the second string: ");
   scanf("%s", s2);

   int val = areAlmostEqual(s1, s2);

   if(val == 1)
   {
    printf("Equal");
   }
   else
   {
    printf("Not equal");
   }
 
   return 0;
}