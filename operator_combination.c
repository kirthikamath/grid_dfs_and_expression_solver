#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char line[100];
    int sum=0;
    fp =fopen("input.txt","r");
    if (fp==NULL)
    {
        printf("error opening file\n");
        return 1;
    }
    
    while(fgets(line,sizeof(line),fp))
    {
        printf("Line: %s",line);
        
        //removing trailing newline from input line
        line[strcspn(line,"\n")]=0;
        line[strcspn(line,"\r")]=0;
        //parsing the targets and the operands
        char *l1=strtok(line,":");
        char *l2=strtok(NULL,":");
        
        printf("Target: %s\n",l1);
        int target=atoi(l1); //converting from string to integer
        
        char *token=strtok(l2," ");
        int num[100];
        int i=0;
        while(token!=NULL)
        {
            num[i] = atoi(token);
            printf("Operand:%s\n", token); 
            i++;
            token= strtok(NULL, " ");    
        }
        for(int j=0;j<i;j++)
        {
            printf("%d ", num[j]);
        }
        printf("\n");
        
        int total=1<<(i-1); //total number of operator combinations possible
        for(int comb=0;comb<total;comb++)//run once for every possible combination
        {
            int result = num[0];
            for(int pos=0;pos<i-1;pos++)
            {
                int op=(comb>>pos)&1;// to decide which operator 
                
                if(op==0)
                    result = result + num[pos + 1];
                else
                    result = result * num[pos + 1];
            }
            printf("Result = %d\n", result);
            if (result == target)
            {
                sum+=target;
                break;        
            }
        }
    }
    
    fclose(fp);
    printf("Final sum is: %d\n", sum);
    return 0;
}
