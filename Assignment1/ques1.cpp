 #include <iostream>
using namespace std;
 int a[100];
 int n,i;
 void create();
 void display();
 void insert();
  void deleteelement();
  void linearsearch();
   int main(){
    int b;
       cout << "MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> b;

        switch(b){
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:insert();
            break;
            case 4:deleteelement();
            break;
            case 5:linearsearch();
            break;
            case 6:cout<<"exiting the program\n";
            break;
        }
   }

   void create(){
    cout<<"enter number of elements\n";
    cin>>n;
    cout<<"enter the array elements\n";
    for(i=0;i<n;i++){
cin>>a[i];
    }
    cout<<"array created succesfully\n";
   }

   void display(){
    if (n==0){
        cout<<"empty array";
    }
    cout<<"array elements";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
   }

   void insert(){
    int pos, val;
    cout<<"enter the position";
    cin>>pos;
    cout<<"enter the value";
    cin>>val;
    for(i=n;i>=pos;i--){
         a[i] = a[i - 1];
    a[pos - 1] = val;
    }
    n=n+1;
    cout<<"array elements";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
   }

   void deleteelement(){
    int pos;
    cout << "Enter position to delete";
    cin >> pos;
    for (i=pos-1; i<n-1; i++){
        a[i] = a[i + 1];}
n=n-1;
cout<<"array elements";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
   }

   void linearsearch(){
    int count=0,num;
    cout<<"enter element to search";
    cin>>num;
    for (i=0;i<n;i++) {
        if (a[i]==num) {
            cout << "Element found at position " << i + 1;
            count=1;}}
            if(count!=1){
                cout<<"elemnt not found";
            }
        }
