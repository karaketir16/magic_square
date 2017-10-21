#include <iostream>
using namespace std;

class Matrix
{
	private:
		
		int number;
		int nb2;
		int n;//number
		int nd;//last number of array = n-1
	public:
		int **dizi;
		Matrix(int a)
		{
			
			n=a;
			nd=n-1;
			nb2=a/2;
			int **array=new int*[a];
		
			
			for(int b=0;b<a;b++)
			{
				array[b]=new int[a];
			}
			dizi=array;
			for(int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
				{
					dizi[i][j]=0;
				}
			}
			fill();
		}
		bool fill()
		{
			int i;
			int j;
			int x=1;
			for(i=nb2,j=nd;j>nb2;j--,x++)//1,2,3
			{
				
				dizi[i][j]=x;
			}
			for(i=nd,j=0;i>nb2;i--,j++,x++)//4,5,6
			{
				dizi[i][j]=x;
			}
			for(i=0,j=nb2;i<nb2;i++,x++)//7,8,9
			{
				dizi[i][j]=x;
				
			}
			
			for(j=0;j<nb2-1;j++)
			{
				for(i=j+1;i<nb2;i++,x=x+4)
				{
					dizi[i][j]=x;
					dizi[nd-i][nd-j]=(x+1);
					dizi[j][i]=(x+2);
					dizi[nd-j][nd-i]=(x+3);
				}
			}
			x=n*n;//x=49
			for(i=nb2,j=0;j<nb2;j++,x--)//49,48,47
			{
				
				dizi[i][j]=x;
			}
			for(i=0,j=nd;i<nb2;i++,j--,x--)//46,45,44
			{
				dizi[i][j]=x;
			}
			for(i=nd,j=nb2;i>nb2;i--,x--)//43,42,41
			{
				dizi[i][j]=x;
			}
			for(j=0;j<nb2-1;j++)
			{
				for(i=nd-1-j;i>nb2;i--,x=x-4)
				{
					dizi[i][j]=x;
					dizi[nd-i][nd-j]=(x-1);
					dizi[j][i]=(x-2);
					dizi[nd-j][nd-i]=(x-3);
					
				}
			}
			x=(n*n+1)/2;
			x=x-(nd/2);
			for(i=0,j=0;i<n;i++,j++,x++)//22,23,24,25,26,27,28
			{
				dizi[i][j]=x;
			}
			
			
		return true;	
		}
		bool row_test()
		{	
			int tester=(n*n+1)*n/2;
			
			for(int i=0;i<n;i++)
			{
				int toplam=0;
				for(int j=0;j<n;j++)
				{
					toplam+=dizi[i][j];
					
				}
				cout<<toplam<<endl;
				if(toplam!=tester)
				{
					return false;
				}
			}
			return true;
		}
	
	
};
int main()
{	
	cout<<"n: ";
	
	int n;
	cin>>n;
	Matrix matrix(n);
	
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<matrix.dizi[i][j]<<"\t";
				
			}
			cout<<endl;
		}
	
	//bool a=true;
	//a=matrix.row_test();
	//cout<<"tester: "<<(n*n+1)*n/2<<endl<<endl;
	//cout<<a<<endl;

	cout<<endl;
	return 0;
}
