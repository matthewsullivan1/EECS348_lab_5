#include <stdio.h>
#include <string.h>

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void monthlySales(float sales[]){
    printf("Monthly sales report for 2022:\nMonth\t\tSales\n");

    for(int i = 0; i<12; i++){
        printf("%s \t $%.2f \n", months[i], sales[i]);
    }
}
int compareSales(const void *a, const void *b){
    return (*(float *)b - *(float *)a);
}

void salesSummary(float sales[]){
    int min_month = 0;
    int max_month = 0;
    
    float min = sales[0];
    float max = sales[0];
    float avg = 0;
    
    printf("\nSales Summary:\n\n");
    for (int i = 0; i < 12; i++) {     
        if(sales[i] < min){
            min = sales[i];
            min_month = i;
        }    
        if(sales[i] > max){  
            max = sales[i];
            max_month = i;
        }
        avg += sales[i];    
    }
    printf("Minimun sales:\t$%.2f (%s)\n", min, months[min_month]);
    printf("Maximun sales:\t$%.2f (%s)\n", max, months[max_month]);
    printf("Average sales:\t$%.2f\n\n", avg/12);
}
void sixMonthReport(float sales[]){
    printf("\nSix-Month Moving Average Report:\n\n");
    for (int i = 0; i < 7; i++){
        float avg = 0;

        for (int j = 0; j < 6; j++){
            avg += sales[j+i];            
        }
        printf("%s-%s\t$%.2f\n", months[0+i],months[5+i], avg/6);
    }
}
void highestToLowest(float sales[]){
    char months2[12][15] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char temp[15];

    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12 - i; j++){
            if (sales[j] < sales[j+1]){    
                float tmp = sales[j];
                sales[j] = sales[j+1];
                sales[j+1] = tmp;

  
                strcpy(temp, months2[j]);
                strcpy(months2[j], months2[j+1]);
                strcpy(months2[j+1], temp);
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n\nMonth\t\tSales\n");
    for(int i = 0; i < 12; i++){
        printf("%s\t$%.2f\n", months2[i],sales[i]);
    }
}

int main(){

    FILE* file = fopen ("data.txt", "r");
    float sales[100]; 

    int i = 0;   
    while (fscanf(file, "%f", &sales[i]) == 1){
        i++;
        if (i >= 100){
            break;
        }
    }
    fclose (file);

    monthlySales(sales);
    salesSummary(sales);
    sixMonthReport(sales);
    highestToLowest(sales);

    return 0;
}
