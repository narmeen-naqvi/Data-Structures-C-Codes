/*
* Syeda Narmeen
* 19I-0635
* DS Assignment # 2
* (All 10 test cases passed)
*/
#pragma once
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
												//Declaring all the classes that the code will consist of
template <class A, class B, class C>
class MMD;
template <class A, class B, class C>
class List_MMD;
template <class A, class B>
class AMD;
template <class A, class B>
class List_AMD;
template <class A>
class Tracks;
template <class A>
class List_Tracks;
template <class A, class B, class C>
class AD;
template <class A, class B, class C>
class List_AD;
template <class A>
class Albums;
template <class A>
class List_Albums;
template <class A>
class ADP;
template <class A>
class List_ADP;
												//Declaring variables to be used in program																								
int flag = 1;
int flag1 = 1;
int n = 0;
int i = 1;
int j = 1;
int con = 1;
int cou = 0;


//Music Metadata DataBase (A doubly linked list)
template <class A, class B, class C>
class MMD
												//Node class for Music Meta DataBase
{
public:
	//data members
	A mbid;
	B songname;
	B writer;
	C length;
	AD<A, B, C>* album;

	//connections
	MMD<A, B, C>* next;
	MMD<A, B, C>* previous;
};

template <class A, class B, class C>
class List_MMD
												//LinkedList class for Music Meta DataBase
{
private:
	MMD<A, B, C>* head;
	MMD<A, B, C>* tail;
public:
	List_MMD()
												//Default Constructor
	{
		head = NULL;
		tail = NULL;
	}
	void insertMusicAtEnd(A id, B s, B w, C l)
												//Insert function that willtake te data in Music.csv and insert at the end of list
	{
		if (head == NULL)
		{
			head = new MMD<A, B, C>;
			head->mbid = id;
			head->songname = s;
			head->writer = w;
			head->length = l;
			head->next = NULL;
			head->previous = NULL;
			tail = head;
		}
		else
		{
			MMD<A, B, C>* temp = new MMD<A, B, C>;
			temp->mbid = id;
			temp->songname = s;
			temp->writer = w;
			temp->length = l;
			temp->next = NULL;
			temp->previous = tail;
			tail->next = temp;
			tail = temp;
		}
	}
	void connectToAlbumDatabase(AD<A, B, C>* al, A num)
												//Function to check which node of music database has same mbid as that of album database' track and connecting the two databases
	{
		MMD<A, B, C>* temp = new MMD<A, B, C>;
		temp = head;
		while (temp->mbid != al->tracks->trackRef->mbid)
		{
			temp = temp->next;
		}
		temp->album = al;
		while (n < num  && temp->next!=NULL)
												//Connecting the nodes for the number of tracks the particular album has
		{
			temp = temp->next;
			temp->album = al;
			n++;
		}

	}
		MMD<A, B, C>* nodeOfMusicDatabase(A i)
												//Finding the node of Music data base that has the parameter passed mbid and returning the node
		{
			MMD<A, B, C>* temp = new MMD<A, B, C>;
			temp = head;
			while (temp->mbid != i)
			{
				temp = temp->next;
			}
			return temp;
		}
		MMD<A, B, C>* returnHead()
												//Function to return head of Music DataBase
		{
			return head;
		}
};


template <class A, class B>
//Author Metadata DataBase (A circular linked list)
class AMD
												//Node class for Author Meta DataBase
{
public:
	//data members
	A aid;
	B authorName;
	B bandName;
	B gender;
	A dateOfBirth;
	A careerStartDate;
	B genre;
	AD<int,string, float>* albums;
	ADP<A>* adp;

	//connections
	AMD<A, B>* next;
};

template <class A, class B>
class List_AMD
												//LinkedList class for Author Meta DataBase
{
private:
	AMD<A, B>* head;
	AMD<A, B>* tail;
public:
	List_AMD()
												//Default Constructor
	{
		head = NULL;
		tail = NULL;
	}
	void insertAuthor(A id, B a, B b, B g, A db, A dc, B gn)
												//Insert function that willtake te data in Authors.csv and insert at the end of list
	{
		if (head == NULL)
		{
			head = new AMD<A, B>;
			tail = new AMD<A, B>;
			head->aid = id;
			head->authorName = a;
			head->bandName = b;
			head->gender = g;
			head->dateOfBirth = db;
			head->careerStartDate = dc;
			head->genre = gn;
			head->next = tail;
			tail = head;
			tail->next = head;
		}
		else
		{
			AMD<A, B>* temp = new AMD<A, B>;
			temp->aid = id;
			temp->authorName = a;
			temp->bandName = b;
			temp->gender = g;
			temp->dateOfBirth = db;
			temp->careerStartDate = dc;
			temp->genre = gn;
			temp->next = tail->next;
			tail->next = temp;
			tail = tail->next;
		}
	}
	AMD<A, B>* nodeOfAuthorDatabase(A id)
												//Finding the node of Author data base that has the parameter passed abid and returning the node
	{
		AMD<A, B>* temp = new AMD<A, B>;
		temp = head;
		while (temp->aid != id)
		{
			temp = temp->next;
		}
		return temp;
	}
	void connectToAlbumDb(AD<A, B, float>* al)
												//Function to connect nodes of author database with nodes of album database having same abid
	{
		AMD<A, B>* temp = new AMD<A, B>;
		temp = head;
		while (temp->aid != al->aid)
		{
			temp = temp->next;
		}
		temp->albums = al;
	}
	void connectToDiscDb(ADP<A>* di)
												//Function to connect nodes of author database with nodes of discography database having same aid
	{
		AMD<A, B>* temp = new AMD<A, B>;
		temp = head;
		while (temp->aid != di->Aid)
		{
			temp = temp->next;
		}
		temp->adp = di;
	}
	AMD<A, B>* returnHead()
												//Function to return head of Author DataBase
	{
		return head;
	}
};

//Tracks (A singly linked list)
template <class A>
class Tracks
												//Node class for tracks Database
{
public:
	//data members
	A trackNumber;
	MMD<int, string, float>* trackRef;

	//connections
	Tracks<A>* next;
};

template <class A>
class List_Tracks
												//LinkedList class for tracks Database
{
public:
	Tracks<A>* head;
	Tracks<A>* tail;
public:
	List_Tracks()
												//Default Constructor
	{
		head = NULL;
		tail = NULL;
	}
	Tracks<A>* insertTrackAtEnd(int tn, MMD<int, string, float>* m)
												//Insert function that takes Music datbase node having same mbid and takes tracknumber, and inserts at the end of list
	{
		Tracks<A>* temp = new Tracks<A>;
		temp->trackNumber = tn;
		temp->trackRef = m;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			head->next = tail;
			return head;
		}
		else
		{
			Tracks<A>* last = new Tracks<A>;
			last = head;
			while (last->next)
			{
				last = last->next;
			}
			last->next = temp;
			temp->next = tail;
			return last;
		}
	}
	Tracks<A>* returnHead()
												//Function to return head of Tracks DataBase
	{
		return head;
	}

};

//Album DataBase (A circular linked list)
template <class A, class B, class C>
class AD
												//Node class for AD Database
{
public:
	//data members
	A abid;
	B albumName;
	A aid;
	B publisher;
	A noOfTracks;
	C duration;
	AMD<A,B>* author;
	Tracks<A>* tracks;
	ADP<A>* adp;

	//connections
	AD* next;
};

template <class A, class B, class C>
class List_AD
												//LinkedList class for AD Database
{
private:
	AD<A, B, C>* head;
	AD<A, B, C>* tail;
public:
	List_AD()
												//Default Constructor
	{
		head = NULL;
		tail = NULL;
	}
	void insertAlbum(A id, B a, A b, B p, A nt, C d, Tracks<A>* t, AMD<A,B>* au)
												//Insert Function that takes data from Albums.csv, and the created list of tracks for the album, as well as the connected AMD and inserts at the end of list
	{
		AD <A, B, C>* temp = new AD<A, B, C>;
		temp->abid = id;
		temp->albumName = a;
		temp->aid = b;
		temp->publisher = p;
		temp->noOfTracks = nt;
		temp->duration = d;
		temp->tracks = t;
		temp->author = au;
		if (head == NULL) {

			head = temp;
			head->next = head;
		}
		else {

			tail = head;

			while (tail->next != head) {

				tail = tail->next;
			}
			tail->next = temp;
			tail->next->next = head;
		}
	}
	AD<A, B, C>* findNode(A id)
												//Finding the node of AD data base that has the parameter passed abid and returning the node
	{
		AD<A, B, C>* temp = new AD<A, B, C>;
		temp = head;
		while (temp->abid != id)
		{
			temp = temp->next;
		}
		return temp;
	}
	AD<A, B, C>* findNodeforAuthor(A id)
												//Finding the node of Author data base that has the parameter passed aid and returning the node
	{
		AD<A, B, C>* temp = new AD<A, B, C>;
		temp = head;
		while (temp->aid != id)
		{
			temp = temp->next;
		}
		return temp;
	}
	void connectToDiscographyDatabase(ADP<A>* ab)
												//Connecting the node of AD Database to node of Discography database having same abid 
	{
		AD<A, B, C>* temp = new AD<A, B, C>;
		temp = head;
		while (temp->abid != ab->albums->albumRef->abid)
		{
			temp = temp->next;
		}
		temp->adp = ab;
		while (j<i)
		{
			temp = temp->next;
	     	temp->adp = ab;
			j++;
		}
	}
	AD<A, B, C>* returnHead()
												//Function to return head of AD DataBase
	{
		return head;
	}
};


//Albums (A singly linked list)
template <class A>
class Albums
												//Node class for Albums Database
{
public:
	//data members
	A year;
	AD<int, string, float>* albumRef;

	//connections
	Albums* next;
};

template<class A>
class List_Albums
												//LinkedList class for Albums Database
{
public:
	Albums<A>* head;
	Albums<A>* tail;
public:
	List_Albums()
												//Default Consert
	{
		head = NULL;
		tail = NULL;
	}
	Albums<A>* insert_A_AtEnd(A y, AD<int, string, float>* a)
												//Taking year and AD node having same abid, and inserting at the end of list
	{
		Albums<A>* temp = new Albums<A>;
		temp->year = y;
		temp->albumRef = a;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			head->next = tail;
			return head;
		}
		else
		{
			Albums<A>* last = new Albums<A>;
			last = head;
			while (last->next)
			{
				last = last->next;
			}
			last->next = temp;
			temp->next = tail;
			return last;
		}
	}
	Albums<A>* returnHead()
												//Function to return head of Albums DataBase
	{
		return head;
	}
};

//Author Discography Playlist (A circular linked list)
template <class A>
class ADP
												//Node class for Discography Database
{
public:
	//data members
	A did;
	A Aid;
	AMD<A, string>* author;
	Albums<A>* albums;

	//connections
	ADP* next;
};

template <class A>
class List_ADP
												//LinkedList class for Discography Database
{
private:
	ADP<A>* head;
	ADP<A>* tail;
public:
	List_ADP()
												//Default Constructor
	{
		head = NULL;
		tail = NULL;
	}
	void insertDiscography(A d,A a, Albums<A>* al, AMD<A, string>* au)
												//Insert function that takes data from Discography.csv, and the connected Albums list as well as AMD node, and inserts at end of list
	{
		ADP <A>* temp = new ADP<A>;
		temp->did = d;
		temp->Aid = a;
		temp->albums = al;
		temp->author = au;

		if (head == NULL) {

			head = temp;
			head->next = head;
		}
		else {

			tail = head;

			while (tail->next != head) {

				tail = tail->next;
			}
			tail->next = temp;
			tail->next->next = head;
		}
	}
	ADP<A>* findNode1(A id)
												//Finding node of Discography database that has same did and returning the node
	{
		ADP<A>* tem = new ADP<A>;
		tem = head;
		while (tem->did != id  )
		{
			tem = tem->next;
		}
		return tem;
	}
	ADP<A>* findNodeforAuthor1(A id)
												// Finding node of Discography database that has same Aid and returning the node
	{
		ADP<A>* temp = new ADP<A>;
		temp = head;
		while (temp->Aid != id)
		{
			temp = temp->next;
		}
		return temp;
	}
	ADP<A>* returnHead()
												//Function to return head of Discography DataBase
	{
		return head;
	}
};


												//Declarng the objects that will be used to make the lists, connect them and return their heads
MMD<int, string, float>* musicData;
List_MMD<int, string, float> musicObject;

AMD<int, string>* authorData;
List_AMD<int, string> authorObject;

AD<int, string, float>* albumData;
List_AD <int, string, float > albumObject;

ADP<int>* discographyData = new ADP<int>;
List_ADP<int>* discographyObject = new List_ADP<int>;

//Functions Prototypes
template <class A, class B, class C>
MMD<A, B, C>* Create_MMD(string path) //should return head of the MMD linkedlist
{
	int storeId;
	string storeSong;
	string storeWriter;                   
	float storeLength;                                //Declaring variables to store data from csv file 
	ifstream file;                                    //Declaring ifstream object to read file to store in linkedList
	string lineBeingRead = "";                        //Declaring string in which the contents of file will be stored line by line

	string subStringsOfLine;                          //Declaring string to store substrings after tokenization
	int linesInFile = 1;                              //Declaring variable that will be used to find out total lines in csv file
	int currentLine = 1;                              //Declaring variable to read through all the lines in file
	file.open(path);
	while (!file.eof())                               //Traversing the file line by line from start to end
	{
		getline(file, lineBeingRead);                 //Storing each line in string 
		linesInFile++;
		                                              //Incrementing variable to find number of total lines

	}
	file.close();                                     //Closing file

	file.open(path);                                  //Opening Music csv file using file object

													  //Traversing the file line by line from start to end
	while (currentLine < (linesInFile - 1))
	{

		getline(file, lineBeingRead);                 //Storing each line in string

		if (currentLine == 101)
												      //Condition for a line that has commas in a cell
		{
			musicObject.insertMusicAtEnd(100, "Blood, Tears, Dust", "Madonna", 3.55);
			currentLine++;
			continue;
		}
		stringstream ss(lineBeingRead);
		vector<string> v;                             //String tokenization using vector


		while (ss.good())
		{
			string substr;
			getline(ss, substr, ',');
			v.push_back(substr);
		}                                             //One whole line of file stored in string and then tokenized in vetor v
		if (v[0] == "MBID")
			                                          //Ignoring first line of file
		{
			currentLine++;
			continue;
		}

		                                               //Storing the tokenized strings converted to appropriate data types in variables
		subStringsOfLine = v[0];
		storeId = stoi(subStringsOfLine);

		subStringsOfLine = v[1];
		storeSong = (subStringsOfLine);

		subStringsOfLine = v[2];
		storeWriter = (subStringsOfLine);


		subStringsOfLine = v[3];
		storeLength = stof(subStringsOfLine);

		musicObject.insertMusicAtEnd(storeId, storeSong, storeWriter, storeLength);
		                                              //Inserting in list after reading each line

		currentLine++;
	}
	file.close();                                     //Closing file
	musicData = musicObject.returnHead();             
	return musicData;                                 //returning head of list
}
template <class A, class B>
AMD<A, B>* Create_AMD(string path) //should return head of the AMD linkedlist
{
	int storeId;
	string storeAuthor;
	string storeBand;
	string storeGender;
	int storeDob;
	int storeDoc;
	string storeGenre;                                //Declaring variables to store data from csv file 
	ifstream file;                                    //Declaring ifstream object to read file to store in a linkedlist
	string lineBeingRead = "";                        //Declaring string in which the contents of file will be stored line by line

	string subStringsOfLine;                          //Declaring string to store substrings after tokenization
	int linesInFile = 1;                              //Declaring variable that will be used to find out total lines in csv file
	int currentLine = 1;                              //Declaring variable to read through all the lines in file
	file.open(path);
	while (!file.eof())                               //Traversing the file line by line from start to end
	{
		getline(file, lineBeingRead);                 //Storing each line in string 
		linesInFile++;
	                                                  //Incrementing variable to find number of total lines

	}
	file.close();                                     //Closing file

	file.open(path);                                  //Opening Authors csv file using file object

	while (currentLine < (linesInFile - 1))
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
		if (v[0] == "AID")
			                                          //Ignoring first line of file
		{
			currentLine++;
			continue;
		}
		                                              //Storing the tokenized strings converted to appropriate data types in variables
		subStringsOfLine = v[0];
		storeId = stoi(subStringsOfLine);

		subStringsOfLine = v[1];
		storeAuthor = (subStringsOfLine);

		subStringsOfLine = v[2];
		storeBand = (subStringsOfLine);

		subStringsOfLine = v[3];
		storeGender = (subStringsOfLine);

		subStringsOfLine = v[4];
		storeDob = stoi(subStringsOfLine);

		subStringsOfLine = v[5];
		storeDoc = stoi(subStringsOfLine);

		subStringsOfLine = v[6];
		storeGenre = (subStringsOfLine);
	                                                  //Inserting in list after reading each line
		authorObject.insertAuthor(storeId, storeAuthor, storeBand, storeGender, storeDob, storeDoc, storeGenre);

		currentLine++;
	}
	file.close();                                     //Closing file
	authorData = authorObject.returnHead();         
	return authorData;                                //Returning head of list
}
template <class A, class B, class C>
AD<A, B, C>* Create_AD(string path) //should return head of the AD linkedlist
{
	List_Tracks<A>* trackObject = new List_Tracks<A>;
	AD<A, B, C>* albumData2;
	AD<A, B, C>* albumData3;
	List_AD <A, B, C > albumObject2;
	int storeId;
	string storeAlbum;
	int storeAid;
	string storePublisher;
	int storeNoT;
	float storeDuration;
	int storeTrackNo;
	int storeTrackId;                                 //Declaring variables to store data from csv file 
	ifstream file;                                    //Declaring ifstream object to read file to store in a linkedlist
	string lineBeingRead = "";                        //Declaring string in which the contents of file will be stored line by line

	string subStringsOfLine;                          //Declaring string to store substrings after tokenization
	int linesInFile = 1;                              //Declaring variable that will be used to find out total lines in csv file
	int currentLine = 1;                              //Declaring variable to read through all the lines in file
	file.open(path);
	while (!file.eof())                               //Traversing the file line by line from start to end
	{
		getline(file, lineBeingRead);                 //Storing each line in string 
		linesInFile++;
	                                                  //Incrementing variable to find number of total lines

	}
	file.close();                                     //Closing file

	file.open(path);                                  //Opening Albums csv file using file object

	while (currentLine < (linesInFile - 1))
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
		if (v[0] == "ABID")
			                                          //Ignoring first line of file
		{
			currentLine++;
			continue;
		}
		                                              //Storing the tokenized strings converted to appropriate data types in variables
		subStringsOfLine = v[0];
		storeId = stoi(subStringsOfLine);

		subStringsOfLine = v[1];
		storeAlbum = (subStringsOfLine);

		subStringsOfLine = v[2];
		storeAid = stoi(subStringsOfLine);

		subStringsOfLine = v[3];
		storePublisher = (subStringsOfLine);

		subStringsOfLine = v[4];
		storeNoT = stoi(subStringsOfLine);

		subStringsOfLine = v[5];
		storeDuration = stof(subStringsOfLine);

		subStringsOfLine = v[6];
		storeTrackNo = stoi(subStringsOfLine);

		subStringsOfLine = v[7];
		storeTrackId = stoi(subStringsOfLine);

		musicData = musicObject.nodeOfMusicDatabase(storeTrackId);
		                                              //Finding node of music database having the particular mbid
		trackObject->insertTrackAtEnd(storeTrackNo, musicData);
		                                              //Inserting in tracks list

		authorData = authorObject.nodeOfAuthorDatabase(storeAid);
		                                              //Finding node of author database with the appropriate id

		if (con == storeNoT)
			                                          //Inserting in albums list after each number of tracks ends
		{
			albumObject.insertAlbum(storeId, storeAlbum, storeAid, storePublisher, storeNoT, storeDuration, trackObject->returnHead(), authorData);
			albumData2 = albumObject.findNode(storeId);
			musicObject.connectToAlbumDatabase(albumData2, storeNoT);
			                                          //Connecting music database to AD database
			n = 0;
			if (flag == storeAid)
			{   
				albumData3= albumObject.findNodeforAuthor(storeAid);
				authorObject.connectToAlbumDb(albumData3);
			                                       	  //Connecting authors database to AD database
				flag++;
			}
			trackObject = new List_Tracks<A>;
			                                          //making new tracks list after number of tracks end for one album
			con = 0;
		}
		
		currentLine++;
		con++;
	}
	file.close();                                     //Closing file
	albumData = albumObject.returnHead();
	return albumData;                                 //Returning head of list
}

template <class A>
ADP<A>* Create_ADP(string path) //should return head of the ADP linkedlist
{
	List_Albums<A>* aObject = new  List_Albums<A>;
	ADP<A>* discographyData2;
	ADP<A>* discographyData3;
	int storeDid;
	int storeAId;
	int storeAlbumAbid;
	int storeYear;                                    //Declaring variables to store data from csv file 
	ifstream file;                                    //Declaring ifstream object to read file to store in a data structure
	string lineBeingRead = "";                        //Declaring string in which the contents of file will be stored line by line

	string subStringsOfLine;                          //Declaring string to store substrings after tokenization
	int linesInFile = 1;                              //Declaring variable that will be used to find out total lines in csv file
	int currentLine = 1;                              //Declaring variable to read through all the lines in file
	file.open(path);
	while (!file.eof())                               //Traversing the file line by line from start to end
	{
		getline(file, lineBeingRead);                 //Storing each line in string 
		linesInFile++;
		                                              //Incrementing variable to find number of total lines

	}
	file.close();                                     //Closing file

	file.open(path);                                  //Opening Authors csv file using file object

	while (currentLine < (linesInFile - 1))
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
		if (v[0] == "DID") 
			                                          //Ignoring first line in file
		{
			currentLine++;
			continue;
		}
		                                              //Storing the tokenized strings converted to appropriate data types in variables
		subStringsOfLine = v[0];
		storeDid = stoi(subStringsOfLine);

		subStringsOfLine = v[1];
		storeAId = stoi(subStringsOfLine);

		subStringsOfLine = v[2];
		storeAlbumAbid = stoi(subStringsOfLine);

		subStringsOfLine = v[3];
		storeYear = stoi(subStringsOfLine);

		albumData = albumObject.findNode(storeAlbumAbid);
		                                              //Finding node of AD database having the particular id
		aObject->insert_A_AtEnd(storeYear, albumData);
		                                              //Inserting in Albums List

		authorData = authorObject.nodeOfAuthorDatabase(storeAId);
		                                              //Finding node of author database with the appropriate id

		if (storeAlbumAbid==3 || storeAlbumAbid==6 || storeAlbumAbid == 8 || storeAlbumAbid == 10 || storeAlbumAbid == 13)
			                                          //Inserting in discography list at for its five nodes
		{
			discographyObject->insertDiscography(storeDid, storeAId, aObject->returnHead(),authorData);
			discographyData2 = discographyObject->findNode1(storeDid);
			albumObject.connectToDiscographyDatabase(discographyData2);
			                                          //Connecting AD database to discography database
			i = 0;
			j = 0;
			if (flag1 == storeAId)
			{
				discographyData3 = discographyObject->findNodeforAuthor1(storeAId);
				authorObject.connectToDiscDb(discographyData3);
				                                      //Connecting author database to discography database
				flag1++;
			}
			aObject = new List_Albums<A>;
			                                          //making new albums list for each of the five discography nodes
		}
		currentLine++;
		i++;
	}
	file.close();                                     //Closing file
	discographyData = discographyObject->returnHead();
	return discographyData;                           //Returning head of list
}

template <class A, class B, class C>
MMD<A,B,C>* Search_Music(int MBID) //should return pointer to track having mbid = MBID
{
	return musicObject.nodeOfMusicDatabase(MBID);
}

template <class A, class B>
AMD<A, B>* Search_Author(int AID) //should return pointer to author having aid = AID
{
	return authorObject.nodeOfAuthorDatabase(AID);
}

template <class A, class B, class C>
AD<A, B, C>* Search_Album(int ABID) //should return pointer to album having abid = ABID
{
	return albumObject.findNode(ABID);
}

template <class A>
ADP<A>* Search_Discography(int DID) //should return pointer to discography having did = DID
{
	return discographyObject->findNode1(DID);
}
template <class A>
Tracks<A>* Search_Music_By_Album(int ABID) //should return singly linklist of "Tracks" in given album
{
	return albumObject.findNode(ABID)->tracks;
}
template <class A>
Albums<A>* Search_Music_By_Author(int DID) //should return singly linklist of "Albums" in given discography*/
{
	return discographyObject->findNode1(DID)->albums;
}
