New! Keyboard shortcuts … Drive keyboard shortcuts have been updated to give you first-letters navigation
bank.c
#include<stdio.h>
#include<stdbool.h>

#define R 3 

// calculating the need
void calculateNeed(int need[][R], int max[][R], int allot[][R], int num) {
    for (int i = 0; i < num; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allot[i][j];
}

bool isSafe(int processes[], int avail[], int max[][R], int allot[][R], int num) {
    int need[num][R];
    bool finish[num];
    calculateNeed(need, max, allot, num);
    finish[0]=0;
    int safeSeq[num];
    int work[R];
    
    // initialising the values for work
    for (int i = 0; i < R ; i++) work[i] = avail[i];

    int count = 0;
    while (count < num) {
        bool found = false;
        for (int p = 0; p < num; p++) {
            if (!finish[p]) {
            
                int j;
                //checking the work values
		for(j=0; j<R; j++)           
                   if (need[p][j] > work[j]) break;
                //if not initialising new work
                if (j == R) {
                    for (int k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state\n");
            return false;
        }
    }
    
    
    printf("\n");
    printf("|| need ||\n");
    printf("A\tB\tC\n");
    for(int i=0; i<num; i++){
       for(int j=0; j<R; j++){
          printf("%d\t", need[i][j]);
       }
       printf("\n");
    }
    
    
    printf("System is in safe state.\nSafe sequence is: ");
    for (int i = 0; i < num ; i++)
        printf("%d ", safeSeq[i]);
    return true;
}

int main() {

    // inputing the number of processes
    int num;
    printf("enter the number of processes:\n");
    scanf("%d", &num);
    
    // initialising numbers for each processes
    int processes[num];
    for(int i=0; i<num; i++) processes[i] = i;
    
    // initialising availabile values for each processes
    int avail[R];
    printf("enter the available values:\n");
    for(int i=0; i<R; i++) scanf("%d", &avail[i]);
    
    //initialising max values for each processes
    int max[num][R];
    printf("enter the max value for each processes:\n");
    for(int i=0; i<num; i++){
       for(int j=0; j<R; j++){
          scanf("%d", &max[i][j]);
       }
    }
    
    //initialising the allocation for each processes
    int allot[num][R];
    printf("enter the allocation for each processes:\n");
    for(int i=0; i<num; i++){
       for(int j=0; j<R; j++){
          scanf("%d", &allot[i][j]);
       }
    }
    
    // printing the available values
    printf("\n");
    printf("|| available ||\n");
    printf("A\tB\tC\n");
    for(int i=0; i<R; i++) printf("%d\t", avail[i]);
    
    // printing the allocation values
    printf("\n");
    printf("|| allocation ||\n");
    printf("A\tB\tC\n");
    for(int i=0; i<num; i++){
       for(int j=0; j<R; j++){
          printf("%d\t", allot[i][j]);
       }
       printf("\n");
    }
    
    // printing the max values
    printf("\n");
    printf("|| max ||\n");
    printf("A\tB\tC\n");
    for(int i=0; i<num; i++){
       for(int j=0; j<R; j++){
          printf("%d\t", max[i][j]);
       }
       printf("\n");
    }

    // calling the functions
    isSafe(processes, avail, max, allot, num);
    return 0;
}


