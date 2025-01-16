#include <iostream>
#include <fstream>
using namespace std;

class temp{
  private:
   char choice;
   string search;
   int totalAmount,quantity,itemRate;
   string itemID,itemName;
   int itemQuantity,itemPrice;
   fstream file,file1;
    public:
    void addProduct(void);
    void viewProduct(void);
    void buyProduct(void);


}obj;
int main(){
    int choice;
    char select;
    do{
      do{
    cout<<"\t--------------------------------------------"<<endl;
    cout<<"\tWELCOME TO GENERAL STORE MANAGEMENT SYSTEM "<<endl;
    cout<<"\t\t Select "<<endl;
    cout<<"\t\t  1) Shopkeeper (Admin)"<<endl;
    cout<<"\t\t  2) Start Shoping "<<endl;
    cout<<"\t\t  3) Exiting..  "<<endl;
    cout<<"\t--------------------------------------------"<<endl;
    cout<<"\t\tEnter your Choice ."<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        obj.addProduct();
        break;
    case 2:
     obj.viewProduct();
     obj.buyProduct();
      break;
    case 3:
       cout<<"Exiting......."<<endl;
      break;
    
    default:
     cout<<"Invalid Choice !"<<endl;
        break;
    }}while(choice != 3);{
     cout<<"Do you want to continue ........ "<<endl;
     cin>>select;
    }
      }
      while( select == 'Y'|| select == 'y') ;
      return 0;
}
  void temp ::addProduct(){
  
         cout<<"Enter Product ID :: ";
         cin>>itemID;
         cout<<"Enter Product Name :: ";
         cin>>itemName;
         cout<<"Enter Product Quantity ::";
         cin>>itemQuantity;
         cout<<"Enter Product Price :: ";
         cin>>itemPrice;

         file.open("data.txt", ios::out| ios ::app);
         file<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;
         file.close();

 }
 void temp :: viewProduct(){
   file.open("data.txt" ,ios :: in);
   
   //file>>itemID>>itemName>>itemQuantity>>itemPrice;
   while (!file.eof()){
    cout<<"------------------------------------"<<endl;
    cout<<"Product ID\t\tProduct Name\t\tQuantity\t\tProduct Price "<<endl;
    file>>itemID>>itemName>>itemQuantity>>itemPrice;
    cout<<itemID<<"\t\t\t"<<itemName<<"\t\t\t"<<itemQuantity<<"\t\t\t"<<itemPrice<<endl;
    cout<<"-------------------------------------"<<endl;
    // file>>itemID>>itemName>>itemQuantity>>itemPrice;
   }
   file.close();
  }
void temp :: buyProduct(){
   choice='y';
   while (choice == 'y')
   {
  file.open("data.txt" ,ios :: in);
  file1.open("temp.txt",ios :: out| ios ::app);
  
   cout<<"Enter Product ID :: ";
   cin>>search;
   cout<<"Enter Quantity :: ";
   cin>>quantity;
     while(!file.eof()){
       if(itemID == search){
        itemQuantity=itemQuantity-quantity;
        file1<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;

         itemRate = quantity * itemPrice;
         totalAmount=totalAmount+itemRate;
         cout<<"----------Payment Bill --------"<<endl;
         cout<<"Total Purchase Amount ::"<<totalAmount<<endl;
         cout<<"-------------------------------"<<endl;
       }else{
        file1<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;
       }
       file>>itemID>>itemName>>itemQuantity>>itemPrice;
     }
     file.close();
     file1.close();
     remove("data.txt");
     rename("temp.txt","data.txt");
     
     cout<<"\n Do you want to continue shopping ? (Y or N)"<<endl;
     cin>>choice;
   }
}