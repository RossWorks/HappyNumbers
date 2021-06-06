#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t main(){
	uint32_t Limit=0, number=0,ThisNumber=0;
	uint8_t addup=0,check=0,digits=0,I=0;
	uint8_t unhappy[8]={4, 16, 37, 58, 89, 145, 42, 20};
	FILE *FID;
	printf("Enter upper limit for happy numbers: ");
	scanf("%ulli",&Limit);
	FID=fopen("C's Happy numbers.txt","w");
	for (number=1;number<=Limit;number++){
		ThisNumber=number;
		addup=0; check=0;
		while(check==0){
			digits=(uint8_t)log10(ThisNumber)+1;
			addup=0;
			for (I=0;I<digits;I++){
				addup+=pow(((ThisNumber%(uint64_t)(pow(10,I+1)))-
				(ThisNumber%(uint64_t)(pow(10,I))))
				/(pow(10,I)),2);
			}
			if (addup==1){fprintf(FID,"%llu\n",number);break;}
			for(I=0;I<8;I++){
				if (addup==*(unhappy+I)){
					check=1;break;
				}
			}
		ThisNumber=addup;
		}
	}
	fclose(FID);
}