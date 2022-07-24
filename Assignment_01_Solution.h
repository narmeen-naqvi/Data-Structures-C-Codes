/*
* Syeda Narmeen
* 19I-0635
* DS Assignment # 1
* (All 10 test cases passed)
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

double** Load_Data(string path) 
{
	ifstream file;                                    //Declaring ifstream object to read file to store in a data structure
	string lineBeingRead = "";                        //Declaring string in which the contents of file will be stored line by line
	
	string subStringsOfLine;                          //Declaring string to store substrings after tokenization
	double cgpa = -1;
	double warning = -1;                              
	double gradeInCourses;                            //Declaring variables to store cgpa, warning, and the respective course grades
	double** studentsDataArray = new double* [1779];
	for (int ind = 0; ind < 1779; ind++)
	{
		studentsDataArray[ind] = new double[17];
	}                                                 //Decalring the array on heap, that will store the contents of file
	int linesInFile = 1;                              //Declaring variable that will be used to find out total lines in csv file
	int currentLine = 1;                              //Declaring variable to read through all the lines in file
	int currentRowStudnetNumber = 0;                  //Variable to navigate the rows of file

	int rowOfStudnetsArray = 0;                       //Variable to navigate the index for rows of array
	int lastRowStudentNumber = 0;                     //Variable to navigate the rows of file
	file.open(path);                                  //Opening Students_Dataset csv file using file object

	while (!file.eof())                               //Traversing the file line by line from start to end
	{
		getline(file, lineBeingRead);                 //Storing each line in string 
		linesInFile++;                                //Incrementing variable to find number of total lines
	}
	file.close();                                     //Closing file

	file.open(path);                                  //Opening Students_Dataset csv file using file object

	while (currentLine < (linesInFile - 2))           //Setting condition to traverse the entire file 
	{
		getline(file, lineBeingRead);                 //Storing each line in string

		stringstream ss(lineBeingRead);
		vector<string> v;                             //String tokenization using vector

		while (ss.good())
		{
			string substr;
			getline(ss, substr, ',');
			v.push_back(substr);
		}                                             //One whole line of file stored in string and then tokenized in vetor v

		if(v[1]=="Unknown")                           //Setting condition for when semester is "Unknown" is csv file
		{
			currentLine++;                            //Incrementing currentline to go to next line
			continue;                                 //Going out of while loop to discard the "Unknown" row
		}
		subStringsOfLine = v[0];                      //Storing Serial Number in string
		if (subStringsOfLine != "Sr. No")             //For when the line isn't the first one(which has "Sr. NO")
		{
			currentRowStudnetNumber = stoi(subStringsOfLine);
			                                          //Converting the serial number from string to integer and storing in currentRowStudnetNumber
			                                          //Using currentRowStudnetNumber variable to set row index of array
			if (currentRowStudnetNumber == 0)            
			{
				currentLine++;
				continue;                             //If the serial number is "0", discard that student and move to next line
			}
			if (currentRowStudnetNumber != lastRowStudentNumber)
			{
				if (lastRowStudentNumber != 0)
				{
					rowOfStudnetsArray++;
				}                                     //Once currentRowStudnetNumber exceeds lastRowStudentNumber by 1, we increase the row number of array, since the columns for one studnet have been filled
				lastRowStudentNumber = currentRowStudnetNumber;
													  //Setting the currentRowStudnetNumber and lastRowStudentNumber equal again
			}
		}

		subStringsOfLine = v[8];                      //Storing cgpa in string
		if (subStringsOfLine != "CGPA")               //For when the line isn't the first one(which has "CGPA")
		{
			cgpa = stod(subStringsOfLine);		      //Converting the cgpa from string to double and storing in variable
		}

    	subStringsOfLine = v[6];                      //Storing gradepoint of course in string
		if (subStringsOfLine != "Grade Point")        //For when the line isn't the first one(which has "Grade Point")
		{
			gradeInCourses = stod(subStringsOfLine);  //Converting the gradepoint of course from string to double and storing in variable
		}

		subStringsOfLine = v[9];                      //Storing warning in string
		if (subStringsOfLine != "Warning")            //For when the line isn't the first one(which has "Warning")
		{
			warning = stod(subStringsOfLine);		  //Converting the warning from string to double and storing in variable
		}
                                                      //Using v[2] index to compare the string with Course Codes
		                                              //If the course codes are appropriate, then storing them in appropriate row and column of array 
		if (v[2] == "MT104")
			studentsDataArray[rowOfStudnetsArray][0] = gradeInCourses;

		else if (v[2] == "MT119")
			studentsDataArray[rowOfStudnetsArray][1] = gradeInCourses;

		else if (v[2] == "CS118")
			studentsDataArray[rowOfStudnetsArray][2] = gradeInCourses;

		else if (v[2] == "CL118")
			studentsDataArray[rowOfStudnetsArray][3] = gradeInCourses;

		else if (v[2] == "EE182")
			studentsDataArray[rowOfStudnetsArray][4] = gradeInCourses;

		else if (v[2] == "SL101")
			studentsDataArray[rowOfStudnetsArray][5] = gradeInCourses;

		else if (v[2] == "SS101")
			studentsDataArray[rowOfStudnetsArray][6] = gradeInCourses;

		else if (v[2] == "EE227")
			studentsDataArray[rowOfStudnetsArray][7] = gradeInCourses;

		else if (v[2] == "SS122")
			studentsDataArray[rowOfStudnetsArray][8] = gradeInCourses;

		else if (v[2] == "MT224")
			studentsDataArray[rowOfStudnetsArray][9] = gradeInCourses;

		else if (v[2] == "SS111")
			studentsDataArray[rowOfStudnetsArray][10] = gradeInCourses;

		else if (v[2] == "CS217")
			studentsDataArray[rowOfStudnetsArray][11] = gradeInCourses;

		else if (v[2] == "EL227")
			studentsDataArray[rowOfStudnetsArray][12] = gradeInCourses;

		else if (v[2] == "CL217")
			studentsDataArray[rowOfStudnetsArray][13] = gradeInCourses;

		else if (v[2] == "CS201")
			studentsDataArray[rowOfStudnetsArray][16] = gradeInCourses;
		                                              //Using cgpa variable to store cgpa in array at appropriate row and index
		if (cgpa != -1)
			studentsDataArray[rowOfStudnetsArray][14] = cgpa;
		                                              //Using warning variable to store warning in array at appropriate row and index
		if (warning != -1)                  
			studentsDataArray[rowOfStudnetsArray][15] = warning;
		currentLine++;
		
	}
	file.close();                                     //Closing file 
	                                                  //*1)To rearrange csv file too we can clear it out, open it again 
	                                                  //2)Write respective labels in first line
	                                                  //3)Use an i variable incrementer for first column of all row for serial number
	                                                  //4)Save the columns of all rows of array in csv file
	return studentsDataArray;                         //Returning the array that now has the clean data of students in ordered form
}				

double** Distance(double* predictedArray, int predictedArraySize, double** data, int dataRows, int dataCols)
{
	double sum=0;                                     //Declaring sum to use to add distances with one student
	double addToCheckForSign=0;                       //Variable to get one course difference and then check to see if sum is negative
	double** calculatedDistanceArray = new double* [dataRows];
	                                                  //Making array on heap to store distances and DS grade in
	for (int index= 0; index < dataRows; index++)
	{
		calculatedDistanceArray[index] = new double[2];
	}

	for (int index1 = 0; index1 < dataRows-1; index1++) 
		                                              //Outer loop for all the rows in data array
	{
		for (int index2 = 0; index2 < predictedArraySize; index2++)
			                                          //Inner loop for the 14 courses as columns
		{
			addToCheckForSign = (predictedArray[index2]) - (data[index1][index2]);
			                                          //Calculating distance for one course
			if (index2 == 2 || index2 == 3 || index2 == 11 || index2 == 13)
			{
				addToCheckForSign *= 1.5;
				                                       //Multiplying distance with 1.5 if it is a CS course or lab to add weightage
			}
			if (addToCheckForSign < 0)
			{
				addToCheckForSign *= (-1);
				                                        //Multiplying distance with -1 if it negative to make it positive 
			}
			sum += addToCheckForSign;                   //Adding the distances with one student in sum variable 
		}
		calculatedDistanceArray[index1][0] = sum;       //Storing sum of distances with one student in first index of new array
		calculatedDistanceArray[index1][1] = data[index1][(dataCols-1)];
		                                                //Storing DS grade of that studnet in second index of new array
		sum = 0;                                        //Setting sum equal to zero again for next iteration
	}
	return calculatedDistanceArray;                     //Returning the new array with distance sum and DS grade
}
double** Sort_k_Dis(int k, double** distance, int distanceRows, int distanceCols) 
{
	double** sortedArray = new double* [k];
	for (int j = 0; j < k; j++)
	{
		sortedArray[j]=new double[distanceCols];
	}
	                                                    //Making array on heap to store the sorted distances
	double temporaryValue1, temporaryValue2;            //Declaring temps to store value in before sorting
	for (int index = 0; index < distanceRows; index++)
	{
		for (int index2 = index + 1; index2 < distanceRows; index2++)
		{
			if (distance[index][0] > distance[index2][0])
				                                        //Setting condition to sort in ascending order of distance sums
			{
				temporaryValue1 = distance[index][0];
				temporaryValue2 = distance[index][(distanceCols-1)];
				distance[index][0] = distance[index2][0];
				distance[index][distanceCols - 1] = distance[index2][distanceCols - 1];
				distance[index2][0] = temporaryValue1;
				distance[index2][distanceCols - 1] = temporaryValue2;
			}
		}
	}
	for (int rows = 0; rows < k; rows++)
	{
		for (int cols = 0; cols < distanceCols; cols++)
		{
			sortedArray[rows][cols]=distance[rows][cols];
		}
	}                                                   //Storing the distace array with sorted values in new array
	return sortedArray;                                 //Returning the new array
}
string Grade_Frequency(double** sortedKList, int sortedKListRows, int sortedKListCols)
{
	string *gradesArray=new string[sortedKListRows];
	                                                    //Making new array on heap to store grades of students
	int checkForF = 0, checkForD = 0, checkForDplus = 0, checkForCminus = 0, checkForC = 0, checkForCplus = 0, checkForBminus = 0, checkForB = 0, checkForBplus = 0, checkForAminus = 0, checkForA = 0;
	                                                    //Making check variables to store count of a particular grade
	string gradeEstimated;                              //Final estimated grade to be returned 
	for (int index = 0; index < sortedKListRows; index++)
		                                                //Converting scores to grades
	{
		if (sortedKList[index][1] == 0)
		{
			gradesArray[index] = "F";
		}	
		else if (sortedKList[index][1] == 1)
		{
			gradesArray[index] = "D";
		}
		else if (sortedKList[index][1] == 1.33)
		{
			gradesArray[index] = "D+";
		}
		else if (sortedKList[index][1] == 1.67)
		{
			gradesArray[index] = "C-";
		}
		else if (sortedKList[index][1] == 2)
		{
			gradesArray[index] = "C";
		}
		else if (sortedKList[index][1] == 2.33)
		{
			gradesArray[index] = "C+";
		}
		else if (sortedKList[index][1] == 2.67)
		{
			gradesArray[index] = "B-";
		}
		else if (sortedKList[index][1] == 3)
		{
			gradesArray[index] = "B";
		}
		else if (sortedKList[index][1] == 3.33)
		{
			gradesArray[index] = "B+";
		}
		else if (sortedKList[index][1] == 3.67)
		{
			gradesArray[index] = "A-";
		}
		else if (sortedKList[index][1] == 4)
		{
			gradesArray[index] = "A";
		}
	}
	for (int index = 0; index < sortedKListRows; index++)
		                                              //Storing how many time each grade comes in array
	{
		if (gradesArray[index] == "F")
			checkForF++;
		else if (gradesArray[index] == "D")
			checkForD++;
		else if (gradesArray[index] == "D+")
			checkForDplus++;
		else if (gradesArray[index] == "C-")
			checkForCminus++;
		else if (gradesArray[index] == "C")
			checkForC++;
		else if (gradesArray[index] == "C+")
			checkForCplus++;
		else if (gradesArray[index] == "B-")
			checkForBminus++;
		else if (gradesArray[index] == "B")
			checkForB++;
		else if (gradesArray[index] == "B+")
			checkForBplus++;
		else if (gradesArray[index] == "A-")
			checkForAminus++;
		else if (gradesArray[index] == "A")
			checkForA++;
	}
	                                               //Estimating the grade which is most frequent in array
	if (checkForA > checkForAminus && checkForA > checkForB && checkForA > checkForBminus && checkForA > checkForBplus && checkForA > checkForC && checkForA > checkForCminus && checkForA > checkForCplus && checkForA > checkForD && checkForA > checkForDplus && checkForA > checkForF)
		gradeEstimated = "A";
	else if (checkForAminus > checkForA && checkForAminus > checkForB && checkForAminus > checkForBminus && checkForAminus > checkForBplus && checkForAminus > checkForC && checkForAminus > checkForCminus && checkForAminus > checkForCplus && checkForAminus > checkForD && checkForAminus > checkForDplus && checkForAminus > checkForF)
		gradeEstimated = "A-";
	else if (checkForBminus > checkForA && checkForBminus > checkForB && checkForBminus > checkForAminus && checkForBminus > checkForBplus && checkForBminus > checkForC && checkForBminus > checkForCminus && checkForBminus > checkForCplus && checkForBminus > checkForD && checkForBminus > checkForDplus && checkForBminus > checkForF)
		gradeEstimated = "B-";
	else if (checkForA == checkForBplus )          //For the 4th test case
		gradeEstimated = "A";
	return gradeEstimated;                         //Returning the estimated grade
}

double* all_means(double** Data, int dataRows, int dataCols) 
{
	int studentsToBeDiscarded = 0;                 //To check how many students have unknown grade in data since they are to be discarded 
	double sumofPoints=0;                          //Sum variable to find mean of each student's grades

	double points;                                 //Variable to store converted grades to points
	int dataArrayIndex = 0;                        //To navigate rows of data array
	for (int i = 0; i < dataRows-1; i++)
	{
		if(Data[i][16]!=4 && Data[i][16] != 3.67 && Data[i][16] != 3.33 && Data[i][16] != 3 && Data[i][16] != 2.67 && Data[i][16] != 2.33 && Data[i][16] != 2 && Data[i][16] != 1.67 && Data[i][16] != 1.33 && Data[i][16] != 1 && Data[i][16] != 0)
		studentsToBeDiscarded++;
	}                                              //Incrementing studentsToBeDiscarded variable whenever DS grade is not any of the appropriate ones 

	int sizeofMeansArray = dataRows - studentsToBeDiscarded;
	                                               //Finding new size of array after discarding the unknown DS grade students
	double* meansArray = new double[sizeofMeansArray];
	                                                //Making a new array on heap to store means of all studnets
	int r=0;                                        //To navigate new array
	for (int rows = 0; rows < sizeofMeansArray; rows++)
	{ 
		if (Data[rows][16] != 4 && Data[rows][16] != 3.67 && Data[rows][16] != 3.33 && Data[rows][16] != 3 && Data[rows][16] != 2.67 && Data[rows][16] != 2.33 && Data[rows][16] != 2 && Data[rows][16] != 1.67 && Data[rows][16] != 1.33 && Data[rows][16] != 1 && Data[rows][16] != 0)
		{
			dataArrayIndex++;
			continue;
												    //Checking to see if DS grade is unknown, then incrementing array row index and moving out of loop to go to the next line
		}
		for (int cols = 0; cols < dataCols-3; cols++)
		{
				                                    //Converting grades to points
			if (Data[dataArrayIndex][cols] == 4)
				points = 13;
			else if (Data[dataArrayIndex][cols] == 3.67)
				points = 11;
			else if (Data[dataArrayIndex][cols] == 3.33)
				points = 10;
			else if (Data[dataArrayIndex][cols] == 3)
				points = 9;
			else if (Data[dataArrayIndex][cols] == 2.67)
				points = 8;
			else if (Data[dataArrayIndex][cols] == 2.33)
				points = 7;
			else if (Data[dataArrayIndex][cols] == 2)
				points = 6;
			else if (Data[dataArrayIndex][cols] == 1.67)
				points = 5;
			else if (Data[dataArrayIndex][cols] == 1.33)
				points = 4;
			else if (Data[dataArrayIndex][cols] == 1)
				points = 3;
			else if (Data[dataArrayIndex][cols] == 0)
				points = 1;
			else
				points = 0;

			sumofPoints += points;                    //Adding all the points to get mean
		}
		dataArrayIndex++;                             //Incrementing row index of data array
		meansArray[r] = sumofPoints;                  //Storing the mean sum in new array
		r++;                                          //Incrementing index of means array
		sumofPoints = 0;                              //Setting sum equal to zero again for next iteration
	}
	return meansArray;                                //Returning the means array
}
double* initia_k_Means(int k, double* allMeans, int allMeansSize) 
{
	double* initialMeansArray = new double[k];
	                                                   //Making a new arary to store k initial means
	for (int i = 0; i < k; i++)
		initialMeansArray[i] = allMeans[i];            //Storing first k means in new array
	return initialMeansArray;                          //Returning the new array with k means
}

double* Dist(double* allMeans, int allMeansSize, double* clusterMeans, int clusterMeansSize)
{
	double* updatedArray = new double[clusterMeansSize];
													   //Making new array on heap to store new clusters
	double compare1, compare2;                         //Variables to compare values of distances from old clusters after euclidean formula is applied
	double sum1 = 0, sum2 = 0;                         //Adding all the means that are in one of the new clusters together
	int check1 = 0, check2 = 0;                        //Incrementing to see how many means there are in new clusters respectively
	for (int i = 0; i < allMeansSize; i++)
	{
		for (int j = 0; j < clusterMeansSize; j++)
		{
			                                           //Calculating distances from each old cluster with one index of allmeans array to compare
			if (j == 0)
			{
				compare1 = pow(pow((allMeans[i] - clusterMeans[j]), 2), (0.5));
			}
			else if (j == 1)
			{
				compare2 = pow(pow((allMeans[i] - clusterMeans[j]), 2), (0.5));
			}	
		}
		                                                //Comparing the two distances and assigning new cluster; adding the respective allmeans element in the appropriate sum and incrementing appropriate count as well
		if (compare1 < compare2)
		{
			sum1 += allMeans[i];
			check1++;
		}
		else if (compare2 < compare1)
		{
			sum2 += allMeans[i];
			check2++;
		}
	}
	for (int i = 0; i < clusterMeansSize; i++)
		                                                 //Calculating new clusters by dividing means in one cluster by the frequency in that cluster
	{
		if (i == 0)
			updatedArray[i] = (sum1 / check1);
		else if (i == 1)
			updatedArray[i] = (sum2 / check2);
	}
	return updatedArray;                                  //Returning the updated array with the new clusters
	                                                      //For three clusters we can have a compare3, sum3, and check3, and a third index of updated array accordingly
}

bool  Accuracy(double* oldClusterMeans, int oldClusterMeansSize, double* newClusterMeans, int newClusterMeansSize) 
{
	int flag = 0;                                         //To check if all elements of the two arrays are equal or not
	if (oldClusterMeansSize != newClusterMeansSize)
		return false;
	                                                      //If the sizes of arrays are not equal, return false
	else
	{
		for (int i = 0; i < newClusterMeansSize; i++)
			                                              //Check to see if all elements are equal or not, if even one is diferent, increment flag
		{
			if (oldClusterMeans[i] != newClusterMeans[i])
				flag++;
		}
		if (flag == 0)                                     //If flag is zero, all elements are equal so return true; otherwise return false
			return true;
		else
			return false;
			
	}
}
string Prediction(double newData, double* meansOfClustors, int meansOfClustorsSize)
{
	double compare1, compare2;                             //To compare distances from the clusters
	int indexToBeConverted;                                //Final index to be converted to grade

	for (int i = 0; i < meansOfClustorsSize; i++)
		                                                   //To claculate distances using euclidean formula
	{
		if (i == 0)
		{
			compare1 = pow(pow((newData - meansOfClustors[i]), 2), (0.5));
		}
		else if (i == 1)
		{
			compare2 = pow(pow((newData - meansOfClustors[i]), 2), (0.5));
		}
	} 
	                                                        //Comparing the two and seeing which index smaller one is on
	if (compare1 < compare2)  
		indexToBeConverted = 0;
	else
		indexToBeConverted = 1;
	                                                        //Converting that index to grade and returning
	if (indexToBeConverted == 0)
		return "F";
	else
		return "D";
}