
tab[6,8,10,2,5,9,0];
void merge(int tab[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=left;
    int temp[right+1];
while(i<=mid && j<= right){
    if(tab[i]<=tab[j]){
      temp[k]=tab[i];
      k++;j++;
    } else{
temp[k]=tamb[j];
k++;j++;
    }
    }
while(i<=mid){
    temp[k]=tab[i];k++;i++;
}

while (j<right)
{
temp[k]=tab[j];k++;j++;
}
}
