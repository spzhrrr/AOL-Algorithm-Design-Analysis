#include <stdio.h>
#include <string.h>

int main(){
    char input[200001];
    int freq[26]={0};
    scanf("%s",input);
    int len=strlen(input);
    for(int i=0;i<len;i++) freq[input[i]-'a']++;

    int oddCount=0;
    for(int i=0;i<26;i++) if(freq[i]%2==1) oddCount++;

    int k=(oddCount==0?1:oddCount);
    printf("%d\n",k);

    static char leftHalf[205][200001];
    static char rightHalf[205][200001];
    static char centerChar[205];
    int leftLen[205]={0}, rightLen[205]={0};

    int centerCount=0;
    for(int i=0;i<26;i++){
        if(freq[i]%2==1){
            centerChar[centerCount]='a'+i;
            freq[i]--;
            centerCount++;
        }
    }
    if(centerCount==0) centerCount=1;

    int p=0;
    for(int i=0;i<26;i++){
        while(freq[i]>0){
            char c='a'+i;
            leftHalf[p][leftLen[p]++]=c;
            rightHalf[p][rightLen[p]++]=c;
            freq[i]-=2;
            p++;
            if(p==centerCount) p=0;
        }
    }

    for(int i=0;i<centerCount;i++){
        for(int j=0;j<leftLen[i];j++) putchar(leftHalf[i][j]);
        if(oddCount!=0) putchar(centerChar[i]);
        for(int j=rightLen[i]-1;j>=0;j--) putchar(rightHalf[i][j]);
        putchar('\n');
    }
    return 0;
}
