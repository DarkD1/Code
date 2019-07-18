#include<stdio.h>
#include<string.h>

void concat(char str1[],char str2[]);
void insetion(char str1[],char str2[],char str3[]);
int len(char str1[]);
void deletion(char str[]);
void replacement(char str[]);
int index(char a[], char b[]);
int main()
{
    char str1[50],str2[50],str3[50];
    int i=0,j=0,l=0,option;
    printf("***** STRING OPERATION *****");
    printf("\n1. Concatenation");
    printf("\n2. Length");
    printf("\n3. Insertion");
    printf("\n4. Deletion");
    printf("\n5. Replacement");
    printf("\nChoose an option: ");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
    {
        concat(str1,str2);
        printf("\nConcatenated String is %s",str1);
        break;
    }

    case 2:
    {
        printf("Enter String: ");
        scanf("%s",str1);
        printf("Length of the String is %d",len(str1));
        break;
    }
    case 3:
    {
        insetion(str1,str2,str3);
        break;
    }
    case 4:
    {
        deletion(str1);
        break;
    }
    case 5:
    {
        replacement(str1);
        break;
    }
    default:
        printf("Invalid Option");
    }
    return 0;
}

void concat(char str1[],char str2[])
{
    int i=0,j=0;
    printf("\n Enter First String: ");
    scanf("%s",str1);
    printf("\n Enter Second String: ");
    scanf("%s",str2);
    while(str1[i]!='\0') i++;
    while(str2[j]!='\0')
    {
        str1[i+1]=str2[j];
        j++;
        i++;
    }
    str1[i+1]='\0';
}

int len(char str1[])
{
    int len =0;
    while(str1[len]!='\0') len++;
    return len;
}
void insetion(char str1[],char str2[],char str3[])
{

    int p=0,r=0,i=0;
    int t=0;
    int x,g,s,n,o;

    puts("Enter First String:");
    scanf("%s",str1);
    puts("Enter Second String:");
    scanf("%s",str2);
    printf("Enter the position where the item has to be inserted: ");
    scanf("%d",&p);
    r = len(str1);
    n = len(str2);
    while(i <= r)
    {
        str3[i]=str1[i];
        i++;
    }
    s = n+r;
    o = p+n;
    for(i=p; i<s; i++)
    {
        x = str3[i];
        if(t<n)
        {
            str1[i] = str2[t];
            t=t+1;
        }
        str1[o]=x;
        o=o+1;
    }

    printf("%s", str1);
}

void deletion(char str1[])
{
    int position,length,i,j,le;
    printf("\n Enter a String: ");
    scanf("%s",str1);
    printf("\n Enter starting position to delete: ");
    scanf("%d",&position);
    printf("\n Enter Length: ");
    scanf("%d",&length);
    j = position + length;
    le = len(str1);
    if(j > le)
    {
        printf("Sorry, Cant delete!!");
        exit(0);
    }

    for(i=position; i<le; i++)
    {
        str1[i] = str1[j];
        j++;
        if(j > le) break;
    }
    str1[j] = '\0';
    printf("%s",str1);
}
void replacement(char str1[])
{
    int position,length,i,j,k;
    char str2[50], str3[50], str4[50];
    printf("\n Enter a String: ");
    scanf("%s",str1);
    printf("\n Enter string you want to replace: ");
    scanf("%s",str2);

    printf("\n Enter string you want to replace with %s: ",str2);
    scanf("%s",str3);
    if(index(str1,str2) == -1){
        printf("Substring doesn't exist");
        exit(0);
    }
    for (i = 0, k = 0; i < index(str1,str2); ++i,++k)	str4[k] = str1[i];
    for (i = 0; i < len(str3); ++i,++k) str4[k] = str3[i];
    for (i = index(str1,str2) + len(str2); i < len(str1); ++i,++k) str4[k] = str1[i];
    str4[k] = '\0';
    printf("After replacing string is : %s",str4);
}
int index(char a[], char b[]){
		int j = 0;
		int i = 0;
		int k = 0;
		int counter;
		if(len(a) < len(b)) return -1;
		for (i = 0; i < len(a); ++i)
		{
			if(a[i] == b[j]){
				counter = 0;
				for (j = 0, k = i; j < len(b); ++j,++k)	if(a[k] == b[j]) counter++;
				if(counter == len(b)) return i;
			}
		}

		return -1;
	}
