#include<stdio.h>

long long solve_expression(long long Base, long long Exponent, long long Modulus)
{
    long long result = 1;
    Base = Base % Modulus;

    while(Exponent > 0)
    {
        if(Exponent % 2 == 1)
        {
            result = (result * Base) % Modulus;
        }
        Base = (Base * Base) % Modulus;
        Exponent = Exponent/2;
    }
    return result;
}

int main()
{
    long long Base, Exponent, Modulus;

    printf("Enter Base: ");
    scanf("%lld", &Base);
    
    printf("Enter Exponent: ");
    scanf("%lld", &Exponent);
    
    printf("Enter Modulus: ");
    scanf("%lld", &Modulus);

    if (Modulus < 1) {
        printf("Error: Modulus can't be negative.\n");
        return 1;
    }
    if (Exponent < 0) {
        printf("Error: Exponent must be non-negative.\n");
        return 1;
    }

    long long result = solve_expression(Base, Exponent, Modulus);
    printf("%lld",result);
    return 0;
}