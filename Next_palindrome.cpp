#include<iostream>
#include<string>
using namespace std;
bool all_nine(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if(str[i]!='9') return false;
	}
	return true;
}
int main()
{
	string str;
		cin>>str;
	int n=str.length(),i,j;
	char ans[2+n];
	if(all_nine(str))
	{
		ans[0]='1';
		for(int i=1;i<n;i++)
		ans[i]='0';
		ans[n]='1';
		ans[n+1]='\0';
		cout <<ans << endl;
	}
	else
	{
			i=n/2;
    		j=i;
    		if(n%2==0)
 		    i=i-1;
		while(i>=0 && str[i]==str[j])
		{
			i--;
			j++;
		}
		if(i<0 || str[i]<str[j])  //12327
		{
			i=n/2;
    		j=i;
    		if(n%2==0)
 		    i=i-1;
			int carry = 1;
			while(i>=0)
			{
				int num=(str[i]-'0')+carry;
				carry = num/10;
				str[i]='0'+(num%10); //adding only one digit number
				str[j]=str[i];
				i--;
				j++;
			}
		}
		else
		{
			while(i>=0)
			{
				str[j]=str[i];
				j++;
				i--;	
			}
		}	
		cout << str;
}
return 0;
}












