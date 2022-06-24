#include <stdio.h>
#include <assert.h>

#define TEST_SOFTWARE 1
#define PRODUCTION_SOFTWARE 2
#define SOFTWARE TEST_SOFTWARE

int alertFailureCount = 0;

int networkAlertStub(float celcius) 
{
     if(celcius<=200)
     {
          return 200; // Return 200 for ok
     }
     else
     {
       printf("ALERT: Temperature is %.1f celcius.\n", celcius); 
       return 500; // Return 500 for not-ok
     }    
}

void alertInCelcius(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    
    #if(SOFTWARE == TEST_SOFTWARE)
    int returnCode = networkAlertStub(celcius);
    #endif
    
    if (returnCode != 200) 
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() 
{
    alertInCelcius(400.5);
    assert(alertFailureCount==1);
    alertInCelcius(303.6);
    assert(alertFailureCount==1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
