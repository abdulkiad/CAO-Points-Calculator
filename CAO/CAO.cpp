/* Project 2
============================================================================
Name : Abduls CAO Points---------
Author : Abdulrahman salim
Student NO.: 15362566
Version  : V1
Copyright  : Abdulrahman.c
Description : CAO
============================================================================
*/
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char arr[1000][700]; // stores  data (limited to 1000 rows)
char h[900][10101]; // stores data (limited to 900 rows)

//reults
typedef struct { 		//The structure for storing results e.g. Maths H A2
	char subject[15]; //subjects
	char level[4];    //level
	char grade[3];   // grade
	int points;     //points
} SubjectResult ;
//gradepoints
typedef struct {		//The structure for storing the points mapping e.g. A2 H 90
	char grade[3]; //grade
	char level[3]; //level
	char points[4]; //points
} GradePoint ;
SubjectResult s[150];  //size of array
GradePoint g[200];   //size of array
int main(void) 
{
	int numberOfLine = 0; //linecount for the results for the first file
	
	int numberofline2=0; //linecount for the grade and points for the second file
	
	FILE *fp = fopen("C:\\Users\\User\\Desktop\\folder\\results17.txt", "r+" );  /* open for reading */
	// This will take each row in the file and store it in arr.
	if (fp == NULL ){ /* check does playlist file exist etc */
		perror ("Error occured ");
		numberOfLine = -1; /* use this as a file not found code */
	} else
		// fgets returns NULL when it gets to the end of the file
		while ( fgets( arr[numberOfLine], sizeof(arr[numberOfLine]), fp ) != NULL ) {
			numberOfLine++;
		}
		
	fclose (fp);
	
	FILE *pf = fopen("C:\\Users\\User\\Desktop\\folder\\GradePoints17.txt", "r+" );  /* open for reading */
	// This will take each row in the file and store it in arr.
	if (pf == NULL ){ /* check does playlist file exist etc */
		perror ("Error occured ");
		numberofline2 = -1; /* use this as a file not found code */
	} else
		// fgets returns NULL when it gets to the end of the file
		while ( fgets( h[numberofline2], sizeof(h[numberofline2]), pf ) != NULL ) {
			numberofline2++;
		}
		
	fclose (pf);


	int x;
	for(x=0;x<numberOfLine;x++)
	{
        sscanf (arr[x],"%s%s%s",s[x].subject,s[x].level,s[x].grade); //seperating the sections
       

   }

	int j;
	printf("\n----------Points and Grades System---------\n");
	for(j=0;j<=numberofline2;j++)
{
        sscanf (h[j],"%s%s%s",g[j].grade,g[j].level,g[j].points); //seperating the different sections
        printf("%s\t%s\t%s\n",g[j].grade,g[j].level,g[j].points);
}
	int y;
	printf("\n----------Uncalculated Results ---------\n");
	for(x = 0;x< numberOfLine;x++)
{
	for(y = 0; y < numberofline2; y++)
 {
	if(strncmp(s[x].grade,g[y].grade,3)==0) //checks if the two grades are equal matching them
		{
    	break;
		}


 }

	if((strncmp(s[x].level,"O",2)==0) && (strncmp(h[0],"A1",2)==0)) //to defrientiate between higher and ordinary level
 {
	y =y +11; //ordinary subjects -40 points

 }
//atoi turn the points from strings to integers, combing parts of the 2 files together
	if((strncmp(s[x].subject,"Maths",2)==0)&&(strncmp(s[x].level,"H",2)==0)&&(strncmp(s[x].grade,"E",1)!=0) &&(strncmp(s[x].grade,"F",1)!=0) && (strncmp(s[x].grade,"H7",2)!=0) && (strncmp(s[x].grade,"H8",2)!=0)) //adding the 25 points to higher level maths & the hedgecsases 
  { 

 	sprintf(arr[x],"%d\t%s\t%s\t%s\t",atoi(g[y].points)+25,s[x].grade,s[x].level,s[x].subject); 

  } 
   else	{
   	
   		sprintf(arr[x],"%s\t%s\t%s\t%s\t",g[y].points,s[x].grade,s[x].level,s[x].subject);
        }

 
	printf("\n%s\n",arr[x]); //prints uncalculated points


}

//sorting begins here

	int i,k,s,q;
	char temp[700];
	int arr3[numberOfLine];
  //sorting the points in order to calculate the points
  for(q=0;q<numberOfLine;q++)
  {
  	arr3[q]=atoi(arr[q]); //converting the points into integers
  }

  
	for(q=0; q<numberOfLine; q++)
      {
		for(k=0; k<numberOfLine-1-q; k++) //buble sorting with strings
		{
			if(arr3[k+1]>arr3[k]) //sorting algorithim comparing the strings
			{
				int temp2;
				temp2=arr3[k];
				arr3[k]=arr3[k+1];
				arr3[k+1]=temp2; //bubble sorting the points
				strcpy(temp, arr[k]);
				strcpy(arr[k], arr[k+1]); //algorithim to sort the strings
				strcpy(arr[k+1], temp);
				for(s=0;s<numberOfLine;s++)
	   {
		
     	}	
			}
			
    	}
}	
	printf("\n----------Sorted Results---------\n");
		for(s=0;s<numberOfLine;s++)
	{
		
		printf("\n%s\n",arr[s]); //printing sorted list

	}	
	//calculating total number of points
	int sum;
	int c;
  for (c = 0; c < 6; c++)
  	 {
   		sum += arr3[c]; //algorithim to add the tops six points up
  	 }
 		 printf("\n------------------------------------------------------------------------\n");
			printf("%d Points (best six)", sum); //printing the points
	
return 0;
}
