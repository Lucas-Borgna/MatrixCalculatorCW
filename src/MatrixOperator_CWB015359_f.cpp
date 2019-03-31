/* Lucas Santiago Borgna (B015359) - Computing (11PHA290) - 18.5.12 */
/* Coursework - Matrix Calculator */

/* Begins by announcing the libraries included for the compiler */
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
/* Definition of Global variables that recur throughout the code */
	float Matrix_Result[3][3];		/* Resultant 3 x 3 Matrix Array */
	int l;							/* variable reserved for user input, to be called upon in different functions */
	ofstream outputfile;				/* Outfile to be used for the Results Output text file */

void Matrix_Display(float Input[3][3], char output[10]) // Function that defines how the array is shown on the console 
	{
		outputfile.open("Results_Output.txt", ios::app);  // Opening of file for editing
		outputfile<<endl<<output<<endl;
		cout<<endl<<output<<endl;
		for (int Row=0; Row<3; Row++)	//Initialization of Row counter for Input matrix, going from prefix 0 to 2. 
		{
			for (int Col=0; Col<3; Col++) 
			{
				cout<<" ";
				outputfile<<" ";
				cout<<fixed<<setprecision(3)<<Input[Col][Row]; //Fixed precision for displaying matrices of 3 decimal places
				outputfile<<fixed<<setprecision(3)<<Input[Col][Row]; //Fixed same precision for the displaying of matrices in the output file
				if(Col==2) //Condition for when the column number reaches its maximum integer value of 2.
				{
					cout<<" "; //When the column number is 2, leave space between for the subsequent matrix element
					outputfile<<" "; //Similar to the above cout but this is for the outputfile
				}
				else
				{
					cout<<" "; //In every other case also leave a space so that the user can differentiate between different elements easily
					outputfile<<" ";
				}

			}
			cout<<endl;
			outputfile<<endl;
		}

		outputfile.close(); //Closing of the outputfile
	}
void SumAB (float Input1[3][3], float Input2[3][3]) // Function definition for Matrix A + B operation
{
	for(int n=0; n<3; n++)
	{
		for (int m=0; m<3; m++)
		{
			Matrix_Result[m][n]=Input1[m][n]+Input2[m][n]; //sum of the two input matrices
		}
	}
	cout<<"The Result of Matrix operation A+B"<<"\n";
	cout<<"Note that A+B=B+A"<<endl;
	Matrix_Display(Matrix_Result, "A+B ="); // Calling the Matrix_Display Function to display the matrix in the console
	
}
void SubAB (float Input1[3][3], float Input2[3][3]) // Function definition for Matrix A-B operation
{
	for (int n=0; n<3; n++)
	{
		for (int m=0; m<3; m++)
		{
			Matrix_Result[m][n] = Input1[m][n]-Input2[m][n]; //subtraction of input matrices A and B
		}
	}
	cout<<"The result of Matrix operation is A-B ="<<endl;
	Matrix_Display(Matrix_Result,"A-B =");
}
void SubBA (float Input1[3][3], float Input2[3][3]) //Function definition for Matrix B - A operation.
{
	for (int n=0; n<3; n++)
	{
		for (int m=0; m<3; m++)
		{
			Matrix_Result[m][n]= Input2[m][n] - Input1[m][n];
		}
	}

	cout<<"The Result of Matrix Operation B-A ="<<endl;
	Matrix_Display(Matrix_Result,"B-A =");
}
void Det_Matrix(float Input[3][3])
{
	outputfile.open("Results_Output.txt", ios::app); //outputfile needs to be reopened here because Det_Matrix does not use the Matrix_Display function
	float Determinant=0;
	float d1,d2,d3,d4,d5,d6,sumd123,sumd456; //Local variables for this function 
	d1 = Input[0][0]*Input[1][1]*Input[2][2];   // Makes the calculating the determinant visually easier
	d2 = Input[0][2]*Input[1][0]*Input[2][1];
	d3 = Input[0][1]*Input[1][2]*Input[2][0];
	d4 = Input[0][2]*Input[1][1]*Input[2][0];
	d5 = Input[0][1]*Input[1][0]*Input[2][2];
	d6 = Input[0][0]*Input[1][2]*Input[2][1];
	
	sumd123 = d1 + d2 + d3;
	sumd456 = d4 + d5 + d6;
	
    Determinant = sumd123 - sumd456; // Final step of calculating of the Determinant
	cout<<"The Determinant of the chosen matrix is Det = "<<Determinant<<endl; //Displaying the result of the determinant calculation
	outputfile<<endl<<"The Determinant is Det = "<<Determinant; //Writes the determinant value in the output file
	outputfile.close();
}
void Matrix_Product_AB (float Input1[3][3], float Input2[3][3]) // Function to determine the resultant matrix from the product of two same sized matrices
{
		
	for (int m=0; m<3; m++)
	{
		for (int n=0; n<3; n++)
		{
			Matrix_Result[m][n]=0;
				for (int k=0; k<3; k++)
				{
					
					
					{
						Matrix_Result[m][n]+=Input1[k][n]*Input2[m][k];
						
					}
											
							
				}
		}
	}
	if (l==1)	// Condition to set which order the user wants to multiply the matrices because matrices are not commutative
	{
		cout<<"The Product A X B = "<<endl;
		Matrix_Display(Matrix_Result,"A X B = ");
	}
	else
	{
		cout<<"The Product B X A ="<<endl;
		Matrix_Display(Matrix_Result,"B X A =");
	}
						
}
void Nav_Menu(void) // Function to call for the display of the menu and the available operations
{
	cout<<"Welcome to the surprisingly helpful 3 x 3 Matrix Operator!"<<endl;
	cout<<"Lucas Santiago Borgna (B015359) - Computing (11PHA290) Coursework Task."<<endl<<endl;
	cout<<"In order to proceed please select your desired operation, from the menu, to perform with the matrices A and B."<<endl;
	cout<<"Operations:"<<endl<<endl;
	cout<<" (a) View Matrix A and B from the input file."<<endl;
	cout<<" (b) Calculate the determinant of either Matrix A or B."<<endl;
	cout<<" (c) Add or Subtract Matrix A and B."<<endl;
	cout<<" (d) Multiply Matrices A and B."<<endl;
	cout<<" (e) Terminate Program."<<endl<<endl;
	cout<<" Version 1.0"<<endl;


}
int main (void) // Definition of Main Functions
{
	float MatrixA[3][3];  // Defining the 3x3 arrays in which Matrix A and B will be stored in
	float MatrixB[3][3];
	outputfile.open("Results_Output.txt",ios::out|ios::trunc); //Opening of file to clear it everytime the program is restarted
	outputfile.close();
	{
		ifstream infile; // calling upon the input txt file.
		infile.open ("Input_Matrices_A&B.txt"); // opening the file
		if(!infile.is_open()) // Case if there is an error reading the file for numerous reasons.
		{
			cout<<"Error: Catastrophic Failure Imminent"<<"\n";
			cout<<"Verify if file is in use by another application or if it has been moved"<<endl;
			cout<<"If the problem persists please contact technical support"<<endl;
			system("pause");
			return -1; //Tells the computer that there is an error.
		}
		while (infile.good()) // Condition for when the file is present and readable
		{ // Assigning the numbers in the text file into the approapiate Matrix
			for(int n=0; n<6;n++) //Row counter 
			{
				for(int m=0; m<3; m++) //column counter
				{
					if(n<3)
					{
						infile>>MatrixA[m][n]; //Defining the Matrix A array with the first 9 set of numbers in the text file
					} 
					else
					{
						infile>>MatrixB[m][n-3]; //The rest of the numbers go into Matrix B
					}
				}
			}
		}
		
	infile.close(); // Finish using and reading the data file, thus program closes it

	int taskno=0;
	 int Input;
	while (taskno !=6)
	{
		Nav_Menu();
		taskno=_getch();
		switch(taskno)
		{
		case 'a': //First menu option: Viewing the Matrices A and B simultaneously
			cout<<"Matrix A"<<endl;
			Matrix_Display(MatrixA,"A =");
			cout<<endl<<"Matrix B"<<endl;
			Matrix_Display(MatrixB,"B =");
		break;

		case 'b': //Second menu option: Calculating the determinant of either matrix A or B
			cout<<endl<<"Which Matrix Would you like the determinant of? A or B";
			Input=getch();
			cout<<endl;
			if(Input == 'A' || Input == 'a') // condition for user input of either A or a
			{
				Det_Matrix (MatrixA);
				taskno=0;
			}
			else if(Input == 'B' || Input =='b')
			{
				Det_Matrix(MatrixB);
				taskno=0;
			}
			else 
			{
				cout<<"Please enter a valid option";
			}
			cout<<endl;
			
			break;

		case 'c': // Option to add or subtract matrices 
			int m; //variable for user to input and decide which of the three operation is desired.
			cout<<"What operation would you like to perform"<<endl;
			cout<<"(1) A + B"<<endl<<" (2) A - B"<<endl<<" Or (3) B-A"<<endl;
			cin>>m;cout<<endl;
			if (m == 1) // Condition for when A + B is desired
			{
				SumAB (MatrixA,MatrixB); //Call upon function SumAB
				cout<<endl; 
				break;
			}
			else if (m ==2) // Condition for when A - B is desired
			{
				SubAB (MatrixA,MatrixB); //Call upon function SubAB
				break;
			}
			else (m ==3); // Condition for when B - A is desired
			{
				SubBA (MatrixA,MatrixB); //Call upon function SubBA
				break;
			}
			cout<<endl;
			
			
		case 'd':
			
	        cout<<"Please Select Which order to multiply the Matrices A and B"<<endl;
			cout<<" (1) A X B"<<endl;cout<<"or (2) B X A"<<endl;
			cin>>l;
			if(l==1)
				 
				{
					Matrix_Product_AB(MatrixA, MatrixB); //matrix product A*B using matrix A and matrix B
				}
			else
			{
				Matrix_Product_AB (MatrixB, MatrixA); //matrix product B*A using matrix A and Matrix B
			}

			cout<<endl;
			
			break;

		case 'e': 
			return 1; //Terminates and exit the console application
		default:
			cout<<endl<<"Please Enter a valid option"<<endl; // Case if the user enters undefined input characters
		
			break;
	
		}
			system("pause"); 
			system("cls"); // Resets screen to home screen or initial options display
	}
}
return 0; //program executes with no errors
}
