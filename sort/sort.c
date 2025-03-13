#include <stddef.h>
#include <stdio.h>


void sort(int * numbers , size_t len){
    size_t pointerOne = 0; // Points to the index of the first element
    size_t pointerTwo = 1; // Points to the index of the second element
    // Both will increment by 1 in each iteration

   while (pointerTwo < len)
   /* Ensures the second pointer does not exceed the array bounds */
   {
       if (numbers[pointerOne] > numbers[pointerTwo]) {
           size_t pointerOneRev = pointerOne; // Reverse pointer, similar idea as above but in the opposite direction
           size_t pointerTwoRev = pointerTwo;
           // These will decrement by 1 in each iteration

           while (pointerOneRev + 1 > 0)
           /* size_t is unsigned, so when pointerOneRev becomes -1, it wraps around to a large value.
              Thus, (pointerOneRev + 1 > 0) prevents an infinite loop. */
           {
               if (numbers[pointerOneRev] > numbers[pointerTwoRev]) {
                   // Swap numbers[pointerOneRev] and numbers[pointerTwoRev] without a temporary variable
                   numbers[pointerOneRev] = numbers[pointerTwoRev] + numbers[pointerOneRev];
                   numbers[pointerTwoRev] = numbers[pointerOneRev] - numbers[pointerTwoRev];
                   numbers[pointerOneRev] = numbers[pointerOneRev] - numbers[pointerTwoRev];
                   /* Thanks for the interview question! :) */
               } else {
                   break;
               }
               --pointerOneRev;
               --pointerTwoRev;
           }
       }
       ++pointerOne;
       ++pointerTwo;
   }
}


int main(void)
/* for testing */
{
    int arrOfNum[] = {1,656,22,99,21,11,1,1,1,83,3,2,90};
    size_t arrOfNumLen = sizeof(arrOfNum)/sizeof(int);

    for (size_t i = 0; i < arrOfNumLen; ++i)
    {
        printf("%d ",arrOfNum[i]);
    }
    puts(":END");

    sort(arrOfNum, arrOfNumLen);
    puts("afterSort");


    for (size_t i = 0; i < arrOfNumLen; ++i)
    {
        printf("%d ",arrOfNum[i]);
    }
    puts(":END");

}
