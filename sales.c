#include <stdio.h>
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void monthlySales(float sales[]){
    printf("Monthly sales report for 2022:\nMonth\tSales\n");

    for(int i = 0; i<12; i++){
        printf("%s \t %f \n", months[i], sales[i]);
    }
}

void salesSummary(float sales[]){
    int min_month;
    int max_month;
    
    float min = sales[0];
    float max = sales[0];
    float avg = 0;

    for (int i = 0; i < 12; i++) {     
        if(sales[i] < min){
            min = sales[i];
            min_month = i;
            printf("%f < %f\n", sales[i], min);
        }    
        if(sales[i] > max){  
            max = sales[i];
            max_month = i;
        }
        avg += sales[i];    
    }


    
    printf("Minimun sales:\t$%f (%s)\n", min, months[min_month]);
    printf("Maximun sales:\t$%f (%s)\n", max, months[max_month]);
    printf("Average sales:\t$%f\n", avg/12);

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

    



    return 0;
}