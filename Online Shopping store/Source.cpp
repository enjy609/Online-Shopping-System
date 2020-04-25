#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct  SHOP_OWNER {
	string name;
	int  ID;
	string  password;
	int  age;
	string gender;
	string address;
	string category;
	shop your_shop;
	int shop_no;
};
void registration (SHOP_OWNER shop_owner[],int size);
struct shopper{
	string id;
	string name;
	string address;
	string passw;
	string age;
};
void print(shopper arr[], int size){
	for (int i = 0; i < size; i++){

		cout << "shoper name=" << arr[i].name << "\n";
		cout << "shopper id=" << arr[i].id << "\n";
		cout << "shopper age=" << arr[i].age << "\n";
		cout << "shopper addres=" << arr[i].passw << "\n";
		cout << "shopper gender=" << arr[i].address << "\n";
		cout << "************************ \n";
	}

}
void registration(shopper arr[], int& size){
	shopper s1;
	fstream read;
	read.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\Shopper .txt", ios::app);
	cin.ignore();
	cout << "enter name";
	cin >> s1.name;
	cout << "enet the id";

	cin >> s1.id;
	cout << "enter age";
	cin >> s1.age;
	cout << "enter passw";

	cin >> s1.passw;
	cout << "enter address";
	cin >> s1.address;
	
	
	arr[size] = s1;
	size++;
	read << s1.name << s1.id << s1.age << s1.passw << s1.address;
	read.close();
}
void update_shopper()
{

	fstream shopper;
	fstream temp;
	shopper.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\Shopper .txt", ios::in);
	temp.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\TEMP.txt", ios::out);
	char name[25];
	char Id[25];
	char passward[25];
	char age[25];
	char gender[25];
	char address[25];
	char a[25];
	cin.ignore();
	cout << "\n Enter the name to update :" << endl;
	cin.getline(a, 25);
	while (!shopper.eof())
	{
		shopper.getline(name, 25, '|');
		shopper.getline(Id, 25, '|');
		shopper.getline(passward, 25, '|');
		shopper.getline(age, 25, '|');
		shopper.getline(gender, 25, '|');
		shopper.getline(address, 25, '|');
		if (strcmp(name, a) == 0)
		{
			cout << "Enter the new information " << endl;
			cout << "\n name:" << endl;
			cin.getline(name, 25);
			cout << "\n Id :" << endl;
			cin.getline(Id, 25);
			cout << "\npassward:" << endl;
			cin.getline(passward, 25);
			cout << "\n age:" << endl;
			cin.getline(age, 25);
			cout << "\n gender :" << endl;
			cin.getline(gender, 25);
			cout << "\n address:" << endl;
			cin.getline(address, 25);
			temp << name << '|' << Id << '|' << passward << '|' << age << '|' << gender << '|' << address << '|' << endl;


		}
		else
		{
			temp << name << '|' << Id << '|' << passward << '|' << age << '|' << gender << '|' << address << '|' << endl;
		}
	}
	temp.close();
	shopper.close();
	shopper.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\Shopper .txt", ios::out);
	temp.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\TEMP.txt", ios::in);
	while (!temp.eof())
	{
		temp.getline(name, 25, '|');
		temp.getline(Id, 25, '|');
		temp.getline(passward, 25, '|');
		temp.getline(age, 25, '|');
		temp.getline(gender, 25, '|');
		temp.getline(address, 25, '|');
		shopper << name << '|' << Id << '|' << passward << '|' << age << '|' << gender << '|' << address << '|' << endl;

	}
	temp.close();
	shopper.close();
	remove("C:\\Users\\Engy Ahmed\\Desktop\\project\\TEMP.txt");
	cout << "\n done " << endl;
}
bool IsloggedIn(){
	string name, passward, un, pw;
	cout << "Enter Username :"; cin >> name;
	cout << "Enter passward:"; cin >> passward;
	fstream read("C:\\Users\\Engy Ahmed\\Desktop\\project\\register.txt");
	getline(read, un);
	getline(read, pw);
	if (un == name&&pw == passward){
		return true;
	}
	else {
		return false;
	}
}
void registration(){
	char ID[20];
	char name[20];
	char age[20];
	char address[20];
	char gender[20];
	char passw[20];
	fstream Shopper;
	Shopper.open("Shopper.txt", ios::app);
	cin.ignore();
	cout << "Shopper Name:";
	cin.getline(name, 20);
	cout << " ID:";
	cin.getline(ID, 20);
	cout << " Age:";
	cin.getline(age, 20);
	cout << " address:";
	cin.getline(address, 20);
	cout << " password:";
	cin.getline(passw, 20);

	Shopper << name << '|' << ID << '|' << age << '|' << address << '|' << passw << endl;
	cout << "Done !";
	Shopper.close();
}

void add_shopdata(){
	char shopname[20];
	char address[20];
	char category[20];
	fstream ShopData;
	ShopData.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\shop.txt", ios::app);
	cin.ignore();
	cout << "shopname :";
	cin.getline(shopname, 20);
	cout << " address :";
	cin.getline(address, 20);
	cout << " category:";
	cin.getline(category, 20);

	ShopData << shopname << '|' << address << '|' << category << endl;
	cout << "done !";
	ShopData.close();
}
void search_product(){
	fstream product;
	product.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\products.txt", ios::in);
	char name[25];
	char noshop[25];
	char category[25];
	char quantity[25];
	char price[25];
	char p[25];
	cout << " \n enter the noshop to search about it\n";
	cin.ignore();
	cin.getline(p, 25);
	int x = 0;
	cout << "\t name \t noshop \t category \t quantity \t price";

	while (!product.eof())
	{
		product.getline(noshop, 25, '|');
		product.getline(name, 25, '|');
		product.getline(category, 25, '|');
		product.getline(quantity, 25, '|');
		product.getline(price, 25);
		if (strcmp(noshop, p) == 0){
			cout << "\n \t" << name << "\t" << noshop << "\t" << category << "\t" << quantity << "\t" << price << endl;
			x = 1;
		}
	}
	if (x == 0){
		cout << " not found !!" << endl;
	}
	product.close();
}
void insert_product(){
	char name[25];
	char noshop[25];
	char category[25];
	char quantity[25];
	char price[25];
	fstream product;
	product.open("C:\Users\Engy Ahmed\Desktop\project\products.txt", ios::app);
	cin.ignore();
	cout << "noshop :";
	cin.getline(noshop, 25);
	cout << " name :";
	cin.getline(name, 25);
	cout << " ctagory:";
	cin.getline(category, 25);
	cout << "quantity :";
	cin.getline(quantity, 25);
	cout << "price :";
	cin.getline(price, 25);
	product << noshop << '|' << name << '|' << category << '|' << quantity << '|' << price << endl;
	cout << "done !";
	product.close();
}
void delete_product(){
	fstream readproduct;
	fstream temp;
	readproduct.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\products.txt", ios::in);
	temp.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\TEMP.txt", ios::out);
	char name[25];
	char noshop[25];
	char category[25];
	char quantity[25];
	char price[25];
	char p[25];
	cin.ignore();
	cout << " enter the noshop of product to delete it\n ";
	cin.getline(p, 25);

	while (!readproduct.eof()){

		readproduct.getline(name, 25, '|');
		readproduct.getline(noshop, 25, '|');
		readproduct.getline(category, 25, '|');
		readproduct.getline(quantity, 25, '|');
		readproduct.getline(price, 25);
		if (strcmp(noshop, p) == 0)
		{
			continue;
		}
		else {
			temp << name << '|' << noshop << '|' << category << '|' << quantity << '|' << price << endl;
		}
	}
	temp.close();
	readproduct.close();
	readproduct.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\products.txt", ios::out);
	temp.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\TEMP.txt", ios::in);
	while (!temp.eof()){

		temp.getline(name, 25, '|');
		temp.getline(noshop, 25, '|');
		temp.getline(category, 25, '|');
		temp.getline(quantity, 25, '|');
		temp.getline(price, 25);
		readproduct << name << '|' << noshop << '|' << category << '|' << quantity << '|' << price << endl;


	}

	temp.close();
	readproduct.close();
	remove("C:\\Users\\Engy Ahmed\\Desktop\\project\\TEMP.txt");
	cout << "\n done !! ";
}
void display_product(){
	char name[25];
	char noshop[25];
	char category[25];
	char quantity[25];
	char price[25];
	char p[25];
	fstream product;
	product.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\products.txt", ios::in);

	cout << "\t name \t noshop \t category \t quantity \t price";
	while (!product.eof())
	{
		product.getline(noshop, 25, '|');
		product.getline(name, 25, '|');
		product.getline(category, 25, '|');
		product.getline(quantity, 25, '|');
		product.getline(price, 25);
		cout << "\n \t" << name << "\t" << noshop << "\t" << category << "\t" << quantity << "\t" << price << endl;
	}
	product.close();
}
int main(){                                                                       // M  A  I  N
	SHOP_OWNER shop_owner[10];
	ifstream infile;
	string text="  ";
	int i=0;
	infile.open("C:\\Users\\Engy Ahmed\\Desktop\\project\\Shop Owner.txt");
		infile>>text;
	while(!infile.eof()){
		SHOP_OWNER s;
		s.name=text;
		infile>>text;
		s.ID= stoi(text); 
		infile>>text;
		s.password=text;
		infile>>text;
		s.age=stoi(text);
		infile>>text;
		s.gender=text;
		infile>>text;
		s.address=text;
		infile>>text;
		s.category=text;
		infile>>text;
		s.shop_no=stoi(text);
		shop_owner[i]=s;
		cout<<endl;
		cout<<"Name is :"<<shop_owner[i].name<<endl;
		cout<<"ID is :"<<shop_owner[i].ID<<endl;
		cout<<"password is :"<<shop_owner[i].password<<endl;
		cout<<"age is :"<<shop_owner[i].age<<endl;
		cout<<"gender is :"<<shop_owner[i].gender<<endl;
		cout<<"address is :"<<shop_owner[i].address<<endl;
		cout<<"shop number :"<<shop_owner[i].shop_no<<endl;

		i++;	
		infile>>text;
	}

	infile.close();
	shopper shoper[10];
	ifstream infile;
	infile.open("F:\\ConsoleApplication42\\ConsoleApplication42\\shopper.txt");
	int i = 0;
	string text = "";
	while (!infile.eof()){
		shopper s;
		infile >> text;
		s.name = text;

		infile >> text;
		s.id = text;

		infile >> text;
		s.age = text;

		infile >> text;
		s.passw = text;

		infile >> text;
		s.address = text;

		shoper[i] = s;

		cout << endl;

		i++;

	}
	int choice;
	cout << " 1:Register \n 2:login \n your choice :"; cin >> choice;
	if (choice == 1){
		string name, passward;
		cout << "Select username :"; 
		cin >> name;
		cout << "Select passward :"; cin >> passward;
		fstream file;
		file.open("C:\\Users\\Ahmed\\Documents\\Visual Studio 2013\\Projects\\Online Shopping store\\Online Shopping store\\regist.txt");
		file << name << endl << passward;
		file.close();
	}
	else if (choice == 2){
		bool status = IsloggedIn();
		if (!status){
			cout << "False login!" << endl;
			return 0;
		}
		else {
			cout << "Succesfully login !" << endl;
			return 1;
		}


	}
	
	bool flag = true;
	while (flag)
	{
		cout << " insert : 1 \n  search : 2\n  delete : 3 \n  display : 4 \n AddShopData : 5\n ShopperRegestration : 6\n updateShopper : 7\n write your choose :";
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
			insert_product();
			break;
		case 2:
			search_product();
			break;
		case 3:
			delete_product();
			break;
		case 4: display_product();
			break;
		case 5:
			add_shopdata();
			break;
		case 6:
			registration();
			break;
		case 7:
			update_shopper();
		default:
			cout << "\n choose right number \n";
		}
		cout << " if you conitnue to use program press 'y' \n";
		char f;
		cin >> f;
		if (f != 'y')
		{
			flag = false;
		}

	}
}
