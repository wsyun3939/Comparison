#include<iostream>
using namespace std;
#define TIER 6
#define STACK 6
#define NBLOCK 30
#define NUMBER 1

int main(){
    int rEither=0;
    int rDouble=0;
    int sumEither=0;
    int sumDouble=0;
    int nblock = NBLOCK;
    char filename[256];
	FILE * fp1 = NULL;
    FILE *fp2=NULL;
    double rate=0;
    for (int a = NUMBER; a < NUMBER+100*TIER; a++) {
        if(a%100==1){
			sprintf(filename, "../duplicate/Benchmark/%d-%d-%d.csv", TIER, STACK, nblock);
			printf("%s\n", filename);

			//	読み込みモードでファイルを開く
			fp1=fopen(filename, "r");
            sprintf(filename, "../duplicate/Benchmark/%d-%d-%d(either).csv", TIER, STACK, nblock);
			printf("%s\n", filename);

			//	読み込みモードでファイルを開く
			fp1=fopen(filename, "r");
        }
        fscanf(fp1,"%d\n",&rDouble);
        sumDouble+=rDouble;
        fscanf(fp2,"%d\n",&rEither);
        sumEither+=rEither;
        rate+=(double)rDouble/rEither;
        if(a%100==0){
            nblock++;
            fclose(fp1);
            fclose(fp2);
        }
    }
        cout<<"ave(double):"<<sumDouble/(100*TIER)<<",ave(either):"<<sumEither/(100*TIER)<<",rate:"<<rate/(100*TIER)<<endl;
        }