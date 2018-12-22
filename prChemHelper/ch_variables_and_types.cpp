#include <fstream>

#include "ch_variables_and_types.h"

using namespace std;

int PrevTime = 0;
int TimeEditAnimationStart = 0;
int TimeEditInverseAnimationStart = 0;
int TimeAllAnimationStart = 0;
int TimeAllInverseAnimationStart = 0;

position EditStartPosition, EditFinishPosition;
position ImageStartPosition, ImageFinishPosition;
position SGBottomStartPosition, SGBottomFinishPosition;

bool EditAnimationRunning = false;
bool EditInverseAnimationRunning = false;
bool AllAnimationRunning = false;
bool AllInverseAnimationRunning = false;
bool WasEditAnimation = false;
bool WasAllAnimation = false;
bool WasChangedInputFormula = false;
bool WasJustCreated = true;

vector<chemElement> ElementList;
string ExceptionList;
string PathToBrowser;
vector<string> CiteArray;

const double CurrentAccelerationCoefficient = 0.0, CurrentSpeed = 0.0;
const double EditLeftAcceleration = 0.0, EditTopAcceleration = 0.0;
const double SGAcceleration = 0.0;
const double EditLineAcceleration = 0.0;
const double ImageLeftAcceleration = 0.0, ImageTopAcceleration = 0.0;
const int EditAnimationTime = 300;
const int AllAnimationTime = 500;
const double StartAcceleration = 1;
const int StartSpeed = 0;

int MonitorHeight;
int MonitorWidth;

int HWbtnSearch;

// CLASS_METHODS :

// SOME OTHER FUNCTIONS :

void skipSpaces (string someStr, int &i)
{
    while (i <= someStr.size() && someStr[i] == ' ')
        i++;
}


string readUntilSpace(string someLine, int &i)
{
    string Result;
    Result = "";
    while (i <= someLine.size() && someLine[i] != ' ')
    {
        Result = Result + someLine[i];
        i++;
    }
    skipSpaces(someLine, i);
    return Result;
}


vector<chemElement> getChemElementArrayFromFile(string path)
{
    vector<chemElement> result;
    ifstream fin(path.c_str());
    string formula, degreeOfOxidation, name;
    while (fin >> formula >> degreeOfOxidation >> name)
    {
        result.push_back(chemElement(formula, degreeOfOxidation, name, 0));
    }
    fin.close();
    return result;
}


vector<string> getStringArrayFromFile(string path)
{
    vector<string> result;
    ifstream fin(path.c_str());
    string line;
    while(getline(fin, line))
    {
        result.push_back(line);
    }
    fin.close();
    return result;
}


string GetStringFromFile(string path)
{
  string result;
  ifstream fin(path.c_str());
  fin >> result;
  fin.close();
  return result;
}


/*void initializeVariables( )
{
  /*# with Form1.edtInputFormula do
  {
    Width = Min( 300, Form1.Width / 2 );
    Left = ( Form1.Width - Width ) / 2;
    Font.Height = 20;
    Font.Name = "Calibri";
  }
  /*# with Form1.shpLine do
  {
    Shape = stRectangle;
    Height = 3;
    Width = 10;
    Left = Form1.edtInputFormula.Left + Form1.edtInputFormula.Width / 2;
    Top = Form1.edtInputFormula.Top + Form1.edtInputFormula.Height;
    Pen.Color = RGB( 102, 102, 255 );
    Brush.Color = RGB( 102, 102, 255 );
  }
  /*# with Form1.strngrdSearchResults do
  {
    Top = Form1.Height / 2 - Form1.Height / 6;
    Left = Form1.Width / 10;
    Width = Form1.Width / 2;
    ColCount = 2;
    RowCount = 0;
    DefaultColWidth = Width / 2 - 5;
    DefaultRowHeight = 25;
    Font.Height = 20;
    Height = 0;
  }
  /*# with Form1.imgHeader do
  {
    Left = ( Form1.Width - Width ) / 2;
  }
  /*# with Form1.imgSearchButton do
  {
    Left = Form1.edtInputFormula.Left + Form1.edtInputFormula.Width + 10;
    Top = Form1.edtInputFormula.Top;
    Width = Form1.edtInputFormula.Height;
    Height = Form1.edtInputFormula.Height;
  }
  EditStartPosition = GetObjectPosition( Form1.edtInputFormula );
  EditFinishPosition = GetSomePosition( Form1.Width / 10, Form1.Height / 8 );
  SGBottomStartPosition = GetObjectPosition( Form1.strngrdSearchResults );
  SGBottomFinishPosition = GetSomePosition( SGBottomStartPosition->Left, Form1.Height - 40 );
  ImageStartPosition = GetObjectPosition( Form1.imgHeader );
  ImageFinishPosition = GetSomePosition( 3 * Form1.Width / 4 - Form1.imgHeader.Width / 2, Form1.imgHeader.Top );
  EditLeftAcceleration = double( 4 ) * ( EditFinishPosition->Left - EditStartPosition->Left ) / Sqr( AllAnimationTime );
  EditTopAcceleration = double( 4 ) * ( EditFinishPosition->Top - EditStartPosition->Top ) / Sqr( AllAnimationTime );
  SGAcceleration = double( 4 ) * ( SGBottomFinishPosition->Top - SGBottomStartPosition->Top ) / Sqr( AllAnimationTime );
  EditLineAcceleration = double( 2 ) * Form1.edtInputFormula.Width / Sqr( EditAnimationTime );
  ImageLeftAcceleration = double( 4 ) * ( ImageFinishPosition->Left - ImageStartPosition->Left ) / Sqr( AllAnimationTime );
  ImageTopAcceleration = double( 4 ) * ( ImageFinishPosition->Top - ImageStartPosition->Top ) / Sqr( AllAnimationTime );
  ElementList = GetElementArrayFromFile( "Data\\files\\Elements.txt" );
  ExceptionList = GetStringFromFile( "Data\\files\\ExceptionList.txt" );
  PathToBrowser = GetStringFromFile( "Data\\files\\PathToBrowser.txt" );
  CiteArray = GetStringArrayFromFile( "Data\\files\\Cites.txt" );
}*/

wstring stringToWString(string str)
{
    return wstring(str.begin(), str.end());
}
