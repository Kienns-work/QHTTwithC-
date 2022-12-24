#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<process.h>
using namespace std;

int main()
{
	int c[10][10],a[10],b[10],i,k,j,m,n,p,q,sum1=0,sum2=0,f=0,s=0,max=0,min=0;
	cout<<"\n\t\tBTVT THU LON HON PHAT HAM MUC TIEU MIN\n\n";
	
	cout<<"\nNhap so luong diem thu : ";
	cin>>m;
	
	cout<<"\nNhap so luong diem phat : ";
	cin>>n;
	
	cout<<"\nNhap luong hang diem thu : \n";
	for(i=0;i<m;i++)
	{
		cin>>a[i];
		sum1=sum1+a[i];
	}
	
	cout<<"\nNhap so luong hang diem phat : \n";
	for(j=0;j<n;j++)
	{
		cin>>b[j];
		sum2=sum2+b[j];
	}
	
	
	//Nhap bang van tai	
	cout<<"\nNhap bang cuoc phi van tai : \n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		cin>>c[i][j];
		cout<<"\n";
	}
	
	
	max=c[0][0];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		if(c[i][j]>max)
		max=c[i][j];
		}
	}
	for(j=0;j<n;j++)
	{
		do
		{
			k=j;
			min=c[0][j];
			p=j;
			q=0;
			for(i=0;i<m;i++)
			{
			if(c[i][j]<min)
	
					{
						min=c[i][j];
						q=i;
						p=j;
					}
				}
				if(min>max)
					break;
			if(a[q]>b[p])
			{
				s+=min*b[p];
				a[q]=a[q]-b[p];
				b[p]=0;
				f++;
			}else if(b[p]>a[q])
			{
				s+=min*a[q];
				b[p]=b[p]-a[q];
				a[q]=0;
				f++;
			}
			else
			{
				s+=min*a[q];
				a[q]=0;
				b[p]=0;
				f++;
			}
			if(a[q]==0)
			{
				for(j=0;j<n;j++)
				c[q][j]=max+1;
			}
			if(b[p]==0)
			{
				for(i=0;i<m;i++)
				c[i][p]=max+1;
	
			}
			j=k;
		}while(min<=max);
	}
	
	
	cout<<"\nChi phi van tai toi uu la "<<s;
	
	getch();

}


/*	test:
	m=3; n=4;
	so luong hang diem thu :  50  55  70
	so luong hang diem phat : 30  60  20  40
	bang chi phi van tai :
	15  18  19  13
	21  14  15  17
	25  12  17  22
	=>Chi phi van tai toi uu: 2070
*/

