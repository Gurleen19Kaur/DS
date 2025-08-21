#include<iostream>
using namespace std;
void bubblesort(int c[20][3], int);
int main(){
	int i , j , r1 , val1, c1 ,a[20][3];
		// input matrix A
	cout<<"enter the rows columns and no of  non zero elements of A sparse matrix \n";
	cin>>r1>>c1>>val1;
	
	a[0][0]=r1;
	a[0][1]=c1; a[0][2]=val1;
	
	cout<<"enter the non zero elemnts of A (row,column,value)\n";
	for(i=1;i<val1+1;i++){
	 	cin>>a[i][0]>>a[i][1]>>a[i][2];}
	 	// input matrix B
	 	int r2,c2,val2,b[20][3];
	 	cout<<"enter the rows columns and no of  non zero elements of B sparse matrix \n";
	cin>>r2>>c2>>val2;
	
	b[0][0]=r2;
	b[0][1]=c2; b[0][2]=val2;
	
	cout<<"enter the non zero elemnts OF B (row,column,value)\n";
	for(i=1;i<val2+1;i++){
	 	cin>>b[i][0]>>b[i][1]>>b[i][2];}
	 	
	 	int t[100][3];
    for (int i = 0; i < val2+1; i++) {
        t[i][0] = b[i][1];  // transpose: new row = old col
        t[i][1] = b[i][0];  // transpose: new col = old row
        t[i][2] = b[i][2];  // value stays same
    }
	 	
	// multiplication
	

	int c[20][3];
	int c_nonzero=0; 
	
	for(i=1;i<val1+1;i++){
		int ra= a[i][0];
		int ca= a[i][1];
		int va= a[i][2];
		
		for(j=1;j<val2+1;j++){
		int rt= t[j][0];
		int ct= t[j][1];
		int vt= t[j][2];
		if(ca==ct){
		int	rowc=ra;
		int colc=rt;
		int valc= va*vt;
			 
			int found =0 ;
			for (int k = 0; k < c_nonzero; k++) {
                    if (c[k][0] == rowc && c[k][1] == colc) {
                        c[k][2] += valc;
                        found++;;
                        break;
                    }}
                    
                    if(found==0){
                    	c[c_nonzero][0]=rowc;
                    	c[c_nonzero][1]=colc;
                    	c[c_nonzero][2]=valc;
                    	c_nonzero++;
					}
}	}}

  bubblesort(c,c_nonzero);// function call for sorting

	cout<<"after multiplication\n";
	for(i=0;i<c_nonzero;i++){
			cout<<c[i][0]<<" "<<c[i][1]<<" "<<c[i][2]<<"\n";
		}
	return 0; }
	
	
void bubblesort(int c[20][3], int n){
	int i , j ,temp , k;
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(c[j][0]>c[j+1][0] || ((c[j][0]==c[j+1][0])&& (c[j][1]>c[j+1][1])) ) {
				for(k=0;k<3;k++){
				
				temp=c[j][k];
				c[j][k]=c[j+1][k];
				c[j+1][k]=temp;}
			}
		}
	}
}
