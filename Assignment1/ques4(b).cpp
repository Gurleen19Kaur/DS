include<iostream>
using namespace std;
int main(){
	int m,n,p,s;
		int a[100][100] , b[100][100] , c[100][100]={0};
		
	cout<<"enter rows and columns for 1 matrix\n";
	cin>>m>>n;
	cout<<"enter rows and columns for  2 matrix\n";
	cin>>s>>p;
	
	if(n==s){
		int i,j;
		 cout<<"Enter elements of first matrix \n";
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout<<"Enter elements of second matrix \n";
    for(i=0;i<s;i++){
        for(j=0;j<p;j++) {
            cin>>b[i][j];
        }
    }
    
    for(i=0;i<m;i++){
    	for(j=0;j<p;j++){
    		for(int k=0;k<n;k++){
    			c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	cout<<"Resultant Matrix\n";
	for(i=0;i<m;i++){
        for(j=0;j<p;j++) {
            cout<<c[i][j]<<" ";}
			cout<<endl;
			}
	}
	
	if(n!=s){
	cout<<"multiplication not possible";
	}
	return 0;
}
