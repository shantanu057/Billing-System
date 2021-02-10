//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
void intro()
{clrscr();char ch[8]="WELCOME"; textcolor(random(10)+4);clrscr();
for(int a=0;a<=5;a++)
{textcolor(random(63));clrscr();
gotoxy(17,18);cout<<ch;gotoxy(58,18);cout<<ch;gotoxy(58,6);cout<<ch;
gotoxy(17,6);cout<<ch;gotoxy(72,12);puts(ch);gotoxy(1,12);puts(ch);
gotoxy(1,22);puts(ch);gotoxy(74,22);puts(ch);gotoxy(35,1);puts(ch);
gotoxy(35,22);puts(ch);gotoxy(35,12);puts(ch);gotoxy(1,1);puts(ch);
gotoxy(74,1);puts(ch);delay(100);}
clrscr();
char*intro="M A D E  B Y  \n\n\n\t\t\t H A R S H  $$\n\n\n\t\t\t  S H A N T A N U  $$  \n\n\n\t\t\tA N C H I T";
for(a=0;a<=strlen(intro);a++)
{
putch(intro[a]); textcolor(a);sound(random(1000)); delay(random(100));

nosound();}
textcolor(GREEN);clrscr();
intro="IN THE GUIDANCE OF";
gotoxy(30,12);
for(a=0;a<=strlen(intro);a++)
{cout<<intro[a];sound(random(800));delay(random(90));nosound(); }
intro=" HANSRAJ SAINI SIR ";clrscr();
for(int i=0;i<=strlen(intro);i++)
{for(int a=0;a<=strlen(intro);a++)
{textcolor(a); gotoxy(a+i,a);
if(intro[i]==' ')
{intro[i]=22;textcolor(random(63));}
putch(intro[i]);delay(1);}}
cout<<"\n\t\t\t\t\tPRESS ANY KEY TO CONTINUE";
getch();}
//==========================================================================
 void BORDER() //outline
{randomize();
clrscr();int i;
int num=random(256);
for(i=1;i<=23;i++)
{gotoxy(1,i);textcolor(i);delay(7);
putch(num);}
for(i=1;i<=80;i++)
{gotoxy(i,1);  delay(7);
textcolor(i);
putch(num);}
for(i=1;i<=23;i++)
{gotoxy(80,i); delay(7);
textcolor(i);
putch(num);}
for(i=80;i>=1;i--)
{gotoxy(i,24);   delay(7);
textcolor(i);
putch(num);}

for(i=1;i<=80;i++)
{gotoxy(i,3);  delay(5);
textcolor(i);
putch(num);}

for(i=1;i<=23;i++)
{gotoxy(3,i);textcolor(i);delay(5);
putch(num);}


for(i=1;i<=23;i++)
{gotoxy(78,i); delay(5);
textcolor(i);
putch(num);}

for(i=80;i>=1;i--)
{gotoxy(i,22);   delay(5);
textcolor(i);
putch(num);}

}

//========================================================================



class product
{
 int pno;
 char name[50];
 float price,qty,tax,dis;
 public:
	void create_product()
	{
	 cout<<"\nPlease Enter The Product No. of The Product: ";
	 cin>>pno;
	 cout<<"\n\nPlease Enter The Name of The Product: ";
	 gets(name);
	 cout<<"\nPlease Enter The Price of The Product: ";
	 cin>>price;
	 cout<<"\nPlease Enter The Discount (%): ";
	 cin>>dis;
	 }

	void show_product()
	{
	 cout<<"\nThe Product No. of The Product : "<<pno;
	 cout<<"\nThe Name of The Product : ";
	 puts(name);
	 cout<<"\nThe Price of The Product : "<<price;
	 cout<<"\nDiscount(%) : "<<dis;
	 }

  int  retpno()
  {return pno;}

  float retprice()
  {return price;}

  char* retname()
  {return name;}

  int retdis()
  {return dis;}

};         //class ends here



//***************************************************************
//    	global declaration for stream object, object
//****************************************************************

 fstream fp;
 product pr;


//***************************************************************
//    	function to write in file
//****************************************************************

void write_product()
   {
    fp.open("Shop.dat",ios::out|ios::app);
    pr.create_product();
    fp.write((char*)&pr,sizeof(product));
    fp.close();
    cout<<"\n\nThe Product Has Been Created ";
    getch();
   }


//***************************************************************
//    	function to read all records from file
//****************************************************************


void display_all()
{
    clrscr();
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
	{
	 pr.show_product();
	 cout<<"\n\n====================================\n";
	 getch();
	 }
    fp.close();
    getch();
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_sp(int n)
{
    int flag=0;
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
	{
	 if(pr.retpno()==n)
		{
		 clrscr();
		 pr.show_product();
		 flag=1;
		}
	}
    fp.close();
if(flag==0)
 cout<<"\n\nrecord not exist";
    getch();
}


//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_product()
{int no,found=0;
clrscr();
  //  BORDER();  changes to be made
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tPlease Enter The Product No. of The Product";
    cin>>no;
    fp.open("Shop.dat",ios::in|ios::out);
    while(fp.read((char*)&pr,sizeof(product)) && found==0)
	   {
	    if(pr.retpno()==no)
		   {
		    pr.show_product();
		    cout<<"\nPlease Enter The New Details of Product:"<<endl;
		    pr.create_product();
		    int pos=-1*sizeof(pr);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&pr,sizeof(product));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		   }
	     }
    fp.close();
    if(found==0)
    cout<<"\n\n!!!!!  Record Not Found  !!!!! ";
    getch();
}


//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_product()
   {
    int no;
    clrscr();
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin>>no;
    fp.open("Shop.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&pr,sizeof(product)))
	{
	 if(pr.retpno()!=no)
		{
		 fp2.write((char*)&pr,sizeof(product));
		 }
	 }
    fp2.close();
    fp.close();
    remove("Shop.dat");
    rename("Temp.dat","Shop.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
    }


//***************************************************************
//    	function to display all products price list
//****************************************************************

    void menu()
    {
     clrscr();
     fp.open("Shop.dat",ios::in);
     if(!fp)
     {
       cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
       cout<<"\n\n\n Program is closing ....";
       getch();
       exit(0);
     }

     cout<<"\n\n\t\tProduct MENU\n\n";
	  cout<<"====================================================\n";
	  cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	  cout<<"====================================================\n";

      while(fp.read((char*)&pr,sizeof(product)))
	 {
	   cout<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<endl;
	}
     fp.close();
}




//***************************************************************
//    	function to place order and generating bill for Products
//****************************************************************

   void place_order()
   {
    int  order_arr[50],quan[50],c=0;
    float amt,damt,total=0;
    char ch='Y';
    menu();
    cout<<"\n============================";
    cout<<"\n    PLACE YOUR ORDER";
    cout<<"\n============================\n";
    do{
	 cout<<"\n\nEnter The Product No. Of The Product : ";
	 cin>>order_arr[c];
	 cout<<"\nQuantity in number : ";
	 cin>>quan[c];
	 c++;
	 cout<<"\nDo You Want To Order Another Product ? (y/n)";
	 cin>>ch;
    }while(ch=='y' ||ch=='Y');
    cout<<"\n\nThank You For Placing The Order";getch();clrscr();
      cout<<"\n\n********************************INVOICE************************\n";
      cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
      for(int x=0;x<=c;x++)
	{
		 fp.open("Shop.dat",ios::in);
		 fp.read((char*)&pr,sizeof(product));
		  while(!fp.eof())
			{
			if(pr.retpno()==order_arr[x])
				{
				 amt=pr.retprice()*quan[x];
				 damt=amt-(amt*pr.retdis()/100);
				 cout<<"\n"<<order_arr[x]<<"\t"<<pr.retname()<<"\t"<<quan[x]<<"\t\t"<<pr.retprice()<<"\t"<<amt<<"\t\t"<<damt;
				 total+=damt;
				}
			fp.read((char*)&pr,sizeof(product));
			}

		 fp.close();
	 }
       cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
       cout<<"\n\n\n\t\t\t\t\tPress Any Key To Continue";
    getch();
    }






//***************************************************************
//    	ADMINSTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{clrscr();
  BORDER();
  char ch2;
gotoxy(35,2);
  textcolor(random(23)-BLACK);
  cprintf("ADMIN MENU");
  gotoxy(4,4);
  cprintf("1.CREATE PRODUCT");
  gotoxy(4,6);
  cprintf("2.DISPLAY ALL PRODUCTS");
  gotoxy(4,8);
  cprintf("3.QUERY ");
  gotoxy(4,10);
  cprintf("4.MODIFY PRODUCT");
  gotoxy(4,12);
  cprintf("5.DELETE PRODUCT");
  gotoxy(4,14);
  cprintf("6.VIEW PRODUCT MENU");
  gotoxy(4,16);
  cprintf("7.BACK TO MAIN MENU");
  gotoxy(4,18);
cprintf("Please Enter Your Choice (1-7) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': clrscr();
	      write_product();
	      break;
    case '2': display_all();break;
    case '3':
	       int num;
	       clrscr();
	       cout<<"\n\n\tPlease Enter The Product No. ";
	       cin>>num;
	       display_sp(num);
	       break;
      case '4': modify_product();break;
      case '5': delete_product();break;
      case '6': menu();
		getch();
      case '7': break;
      default:cout<<"\a";admin_menu();
   }
}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


void main()
{
  char ch;
 intro();
  do
    {
	  BORDER();
	  gotoxy(35,2);
	  textcolor(random(23)-BLACK);
	  cout<<"MAIN MENU";
	  gotoxy(4,8);
	  cout<<"01. CUSTOMER";
	 gotoxy(4,10);
	  cout<<"02. ADMINISTRATOR";
	  gotoxy(4,12);
	  cout<<"03. EXIT";
	  gotoxy(8,14);
	  cout<<"Please Select Your Option (1-3) ";
	  ch=getche();
	  switch(ch)
	  {
		 case '1': clrscr();
			   place_order();
			   getch();
			   break;
		  case '2': admin_menu();
			    break;
		  case '3':exit(0);
		  default :cout<<"\a";
	}
    }while(ch!='3');
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************

