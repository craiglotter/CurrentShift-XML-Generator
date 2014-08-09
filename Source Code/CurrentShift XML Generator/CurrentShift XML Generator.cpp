// CurrentShift XML Generator.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <fstream.h>



//structure used in print credit binary.rec file
struct _CURRENTSHIFT
{
	unsigned int Number;
	unsigned int Channel1;
	unsigned int Channel2;
	unsigned int Channel3;
	unsigned int Channel4;
	unsigned int Channel5;
	unsigned int Channel6;
	double DateTime;	
};

//program entry point. reads binary current shift file and generates more user-friendly xml file.
int main(int argc, char* argv[])
{
	//execute code only if two program arguments are supplied, namely input binary file and 
	//output path to write to. (Remember, 1st argument contains program name)
	if (argc >= 3)
	{
		//read binary file (file is expected to contain an instance of CurrentXAction
		cout << "Reading Binary File...";      
	  	_CURRENTSHIFT p_Data;
		FILE* in;
		in = fopen(argv[1], "rb");
		if (in!=NULL)
		{
			fread(&p_Data, sizeof(_CURRENTSHIFT), 1, in); 
			fclose(in);
			cout << " Ok" << endl;

			//generate XML file
			cout << "Writing XML File...";   
			fstream file_op(argv[2],ios::out);
			file_op<<"<CurrentShift_File>"<<endl;
			file_op<<"<CurrentShift>"<<endl;
			file_op<<"<Number>"<< p_Data.Number <<"</Number>"<<endl;
			file_op<<"<Channel1>"<< p_Data.Channel1 <<"</Channel1>"<<endl;
			file_op<<"<Channel2>"<< p_Data.Channel2 <<"</Channel2>"<<endl;
			file_op<<"<Channel3>"<< p_Data.Channel3 <<"</Channel3>"<<endl;
			file_op<<"<Channel4>"<< p_Data.Channel4 <<"</Channel4>"<<endl;
			file_op<<"<Channel5>"<< p_Data.Channel5 <<"</Channel5>"<<endl;
			file_op<<"<Channel6>"<< p_Data.Channel6 <<"</Channel6>"<<endl;
			file_op<<"<DateTime>"<< p_Data.DateTime <<"</DateTime>"<<endl;
			file_op<<"</CurrentShift>"<<endl;
			file_op<<"</CurrentShift_File>"<<endl;
			file_op.close();
			cout << " Ok" << endl;

			//print success message
			cout << "Operation Successful. (" << argv[2] << " generated)" <<endl;
		}
		else
		{
			//in case binary file cannot be opened/located
			cout << " Fail" << endl;
			cout << "Error: Input binary file cannot be opened" << endl;
			cout << "Operation Failed." << endl;
		}
	}
	else
	{
		//incorrect number of arguments supplied to the program
		cout << "Usage: <CurrentShift XML Generator.exe> <binary input file> <xml output file>" << endl;
		cout << "Where <binary input file> is filename of binary current shift file to read and <xml output file> is the file path for the generated xml current shift file." << endl;
	}
	return 0;
}

