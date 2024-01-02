
#include <iostream>
#include <iomanip>
using namespace std;
const int row = 4;
const int col = 6;
 int table[row][col] = {{5, 1, 21, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {23, 5, 20, 5, 30, -1}, {20, 9, 5, 0, -1, -1}};

void updated_table();
void insert_value();
void count_num();
void delete_value();
void most_frequent_value();
void average();
void maximum_score();
int perform_another_operation();  // Declaration added here

void menu_function();


int main()
{
	menu_function();
	return 0;
}


void menu_function(){
	// Making Table
	cout << "........................Table........................" << endl;
	// This for loop Show the Table
	for (int i = 0; i <row; i++)
	{
		cout << "\t \t"
			 << "Field " << i + 1 << "\t  ";
		for (int j = 0; j < col; j++)
		{
			cout << " " << table[i][j] << " ";
		}
		cout << "\n \n";
	}

	// Create Menu for User
	cout <<"\t"<< "Press 1 to insert new test result. " << endl;
	cout <<"\t" << "Press 2 to display total number of results in table. " << endl;
	cout <<"\t" << "Press 3 to delete any test value from table. " << endl;
	cout <<"\t" << "Press 4 to display the 2 most frequent values in table. " << endl;
	cout <<"\t" << "Press 5 to display average scores of each field. " << endl;
	cout <<"\t" << "Press 6 to display field having maximum success score. " << endl;
	int choice;
	cin >> choice;
	while (choice>6||choice<1)
	{
		cout << "You entered an invalid Number. Please entered a valid number choice! between 1 - 6 ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		insert_value();

		break;
	case 2:
		count_num();

		break;
	case 3:
		delete_value();
		break;
	case 4:

		most_frequent_value();
		break;
	case 5:
		average();
		break;
	case 6:

		maximum_score();
		break;
	}
	perform_another_operation();
}
void updated_table()
{
	cout << "........................Update Table........................" << endl;
    
	for (int i = 0; i < row; i++)
	{
			cout << "\t \t"
			 << "Field " << i + 1 << "\t  ";
		for (int j = 0; j < col; j++)
		{
        
			cout << " " << table[i][j] << " ";
		}
		cout << "\n \n";
	}

}
// function 1 starts from here
void insert_value()
{
	int field, value,count=0;
	
	cout << "Enter the field in which you want to enter a value : ";
	cin >> field;
	while(field>4||field<1){
		cout<<"You entered an invalid field number! Please enter a valid field number betwen 1 - 4 :) ";
		cin>>field;

	}
	cout << endl<< "Enter the value you want to enter : ";
	cin >> value;

	for (int i = 0; i < row; i++)
	{
		if (field == i + 1)
		{
			for (int j = 0; j < col; j++)
			{
				if (table[i][j] == -1)
				{
					table[i][j] = value;
					cout<<endl<<"______Value is inserted successfully in field no: "<<field<<" and at position "<<j+1<<" ______"<<endl<<endl;
					break;
				}
				if(table[i][j]!=-1){
					count++;
				}
			}
		}
	}
	if(count==6){
		cout<<"______This Field is full of values you cannot insert any more values!_______"<<endl<<endl;
	}else{
			updated_table();
	}

}
// function 2 starts from here

void count_num()
{
	int count = 0;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (table[i][j] != -1)
			{
				count++;
			}
		}
	}
	cout << "number of filled locations in table are: " << count << endl;
}
// function 3 starts from here
void delete_value()
{
	int field;
	cout << "Enter The field number You want to Delete the value : ";
	cin >> field;
	while(field>4||field<1){
		cout<<"You entered an invalid field number! Please enter a valid field number betwen 1 - 4 :) ";
		cin>>field;
		
	}
	cout << endl
		 << "Enter the position you want to delete at field no " << field << "  : ";
	int value;
	cin >> value;
	while (value > 6 || value < 0)
	{
		cout << "Invalid Position! Please Enter A Valid Position Between 1 and 6";
		cin >> value;
	}
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((field - 1) == i && (value - 1) == j)
			{
				if(table[i][j]==-1){
					cout<<"______This position is already empty position______ "<<endl<<endl;
					++count;
					
				}else{
				table[i][j] = -1;
				cout<<" Value is deleted successfully in field no: "<<field<<" and at position "<<j+1<<endl<<endl;
				
					}
			}
		}
	}
	
	if (count>0)
	{
		char choice;
cout<<"If you want to delete other value in other field then type y. If no then type n :) ";
	cin>>choice;
	cout<<endl;
	while (choice!='Y'&&choice!='y'&&choice!='n'&&choice!='N')
	{
		cout <<"You entered an invalid choice! Please enter a valid choice Y or N :)";
		cin>>choice;
	}
	
	if(choice=='y' || choice == 'Y'){
		delete_value();
	}else if(choice=='n'||choice=='N'){
	cout<<"Program is terminated";

	}

	}else{
		
	
	updated_table();
	}
}
// function 4 starts from here

void most_frequent_value()
{
	int firstFreqValue = -1;
	int secondFreqValue = -1;
	int thirdFreqValue= -1;
	int first_tempt = 0, second_tempt = 0,third_tempt=0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		
		{
			//If Value is already exist then no update in firest_tempt variable
			if(firstFreqValue!=table[i][j]){
			if (table[i][j] != -1)
			{

				for (int k = 0; k < row; k++)
				{
					for (int l = 0; l < col; l++)
					{
						if (table[i][j] == table[k][l])
						{
							
							first_tempt++;
						}	
					
					}
				}
				//If first_tempt variable containe greater then or equal to previous_tempt then update the value of secondFreqValue variable
				if (first_tempt >= second_tempt)
				{
					thirdFreqValue=secondFreqValue;
					secondFreqValue = firstFreqValue;
					firstFreqValue = table[i][j];
					third_tempt= second_tempt;
					second_tempt = first_tempt;
				}
			
				if(first_tempt>=third_tempt&&first_tempt<second_tempt){
				third_tempt = first_tempt;
				thirdFreqValue=secondFreqValue;
				secondFreqValue=table[i][j];
				}
					first_tempt = 0;
			
				}	}
		}
	}
	cout << "First Frequent Value is : " << firstFreqValue << "  Second Frequent Value is : " << secondFreqValue << endl;
}
// function 5 starts from here
void average()
{
	int sum = 0, totalValues = 0;
 	float average;
	for (int i = 0; i < row; i++)
	{
		totalValues = 0;
		for (int j = 0; j < col; j++)
		{
			if (table[i][j] != -1)
			{
				totalValues = totalValues + 1;
				sum = sum + table[i][j];
			}
		}
		if (sum != 0 && totalValues != 0)
		{

			average = (double)sum / totalValues;
			cout <<fixed<< "Field " << i + 1 << " Average is : " <<setprecision(1)<< average << endl;

			sum = 0;
			average = 0.0;
		}
		else
		{
			cout << "Field " << i + 1 << " Average : Empty field " << endl;
		}
	}
}

// function 6 starts from here
void maximum_score()
{
	int maximum_score = 0, sum = 0, field;

	for (int i = 0; i < row; i++)
	{
		sum = 0;
		for (int j = 0; j < col; j++)
		{
			if (table[i][j] != -1)
			{
				sum= sum+ table[i][j];
			}
		}
		if (maximum_score == 0)
		{
			field = i + 1;
			maximum_score = sum;
		}
		else if (sum > maximum_score)
		{
			maximum_score = sum;
			field = i + 1;
		}
	}
	cout << "Field " << field << " has the maximum success score ." << endl;
}




int perform_another_operation(){
	char choice;
	cout<<"If you want to perform another operation in updated table then type y. If no then type n :) ";
	cin>>choice;
	cout<<endl;
	while (choice!='Y'&&choice!='y'&&choice!='n'&&choice!='N')
	{
		cout <<"You entered an invalid choice! Please enter a valid choice Y or N :)";
		cin>>choice;
	}
	
	if(choice=='y' || choice == 'Y'){
		menu_function();
	}else if(choice=='n'||choice=='N'){
	cout<<"Program is terminated";
		return 0;
	}

}

